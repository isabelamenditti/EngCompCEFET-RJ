#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs_AEDS1_Isabela.h"
#include "livros_AEDS1_Isabela.h"

///TABELA HASH DE LIVROS
int HashLivros(int numero_categoria){
    int hash; ///Posição i que encontra-se essa categoria na tabela.
    hash = numero_categoria%tam_livros;
    return hash;
}

int HashLivrosID(int id){
    int chave, hash; ///Posição i que encontra-se esse ID na tabela.
    chave = id/10000;
    hash = chave%tam_livros;
    return hash;
}


///LISTA TODOS OS LIVROS CADASTRADOS EM UM ARQUIVO
void ListarLivros(NoLivro *TabelaLivros[]){
    FILE *l; ///ponteiro para o arquivo que lista todos os livros
    l = fopen("livros_cadastrados.txt", "w");

    fprintf(l, "\nLISTA DE LIVROS CADASTRADOS:\n");

    ///Imprimindo cada Lista Encadeada da Tabela Hash
    for(int i=0; i<tam_livros; ++i){
        NoLivro *p = TabelaLivros[i]->prox;
        if(TabelaLivros[i]->prox != NULL){
            while(p != NULL){
                fprintf(l, "\nNOME: %s\nID: %d\nANO DE PUBLICACAO: %d\nCATEGORIA: %s\n", p->livro.nome_livro, p->livro.ID_livro, p->livro.ano_livro, p->livro.categoria_livro);
                if(strcmp(p->livro.livro_emprestimo, "0000000ABCD") != 0){
                    fprintf(l, "EMPRESTIMO: %s\n", p->livro.livro_emprestimo);
                }else{
                    fprintf(l, "Livro Disponivel\n");
                }
                p = p->prox;
            }
        }
    }
    fclose(l);
    return;
}


///LISTA OS LIVROS DE DETERMINADA CATEGORIA
void ListarLivrosCategoria(NoLivro *cab){
    printf("\nLISTA DE LIVROS DA CATEGORIA SELECIONADA:\n");

    NoLivro *p = cab->prox;
    if(cab->prox != NULL){
        while(p != NULL){
            printf("\nNOME: %s\nID: %d\nANO DE PUBLICACAO: %d\nCATEGORIA: %s\n", p->livro.nome_livro, p->livro.ID_livro, p->livro.ano_livro, p->livro.categoria_livro);
            if(strcmp(p->livro.livro_emprestimo, "0000000ABCD") != 0){
                printf("EMPRESTIMO: %s\n", p->livro.livro_emprestimo);
            }else{
                printf("Livro Disponivel\n");
            }
            p = p->prox;
        }
    }else{
        printf("\nNao existem livros nessa categoria!\n");
    }
    return;
}


///PROCURA OS LIVROS
NoLivro *ProcurarLivro_ID(NoLivro *cab, int id, NoLivro **ant){ ///mecanismo de busca do livro através do ID
    (*ant) = cab;
    NoLivro *p = cab->prox;
    
    while(p != NULL && p->livro.ID_livro < id){
        (*ant) = p;
        p = p->prox;
    }
    return p;
}


///MOSTRAR DADOS DE UM LIVRO ESPECÍFICO
void DadosLivro_ID(NoLivro *cab, int id){
    NoLivro *ant = NULL;
    NoLivro *p = ProcurarLivro_ID(cab, id, &ant);
    if(p == NULL){
        printf("\nEsse livro nao se encontra no cadastro.\n");
        return;
    }
    printf("\nNOME: %s\nID: %d\nANO DE PUBLICACAO: %d\nCATEGORIA: %s\n", p->livro.nome_livro, p->livro.ID_livro, p->livro.ano_livro, p->livro.categoria_livro);
    if(strcmp(p->livro.livro_emprestimo, "0000000ABCD") != 0){
        printf("EMPRESTIMO: %s\n", p->livro.livro_emprestimo);
    } else{
        printf("Livro Disponivel\n");
    }
    return;
}


///ADICIONA OS LIVROS
void AdicionarLivro(NoLivro *cab, int num_categoria, char nome[50], int ano){
    NoLivro *ant = NULL;
    (*&ant) = cab;
    NoLivro *p = cab->prox;
    
    int id = 0; ///Produzindo o ID do livro adicionado
    if(p == NULL){ ///Para categoria que ainda não possua nenhum livro
        id = 2000000 + num_categoria*10000 + 1;
        printf("%d", id);
    }
    else{
        while (p != NULL){ ///Para categoria que já possua algum livro
            id = p->livro.ID_livro + 1; ///o ID sempre será baseado no ID do livro anterior
            (*&ant) = p;
            p = p->prox;
            printf("%d", id);
        }    
    }

    ///Inserindo a posição do novo livro
    p = (NoLivro *)malloc(sizeof(NoLivro));
    p->livro.ID_livro = id;
    p->livro.numero_categoria = num_categoria;
    strcpy(p->livro.nome_livro, nome);
    p->livro.ano_livro = ano;
    strcpy(p->livro.livro_emprestimo, "0000000ABCD"); ///o livro começa não estando emprestado

    ///Ciência da computação, informação e generalidades(1); Filosofia e psicologia(2); Religião(3); Ciências sociais(4); Línguas(5);
    ///Ciências puras(6); Tecnologia e ciências aplicadas(7); Artes e recreação(8); Literatura(9); História e geografia(10).
    
    switch (num_categoria){
        case 1:
            strcpy(p->livro.categoria_livro, "Ciencia da computacao, informacao e generalidades");
            break;
        case 2:
            strcpy(p->livro.categoria_livro, "Filosofia e psicologia");
            break;
        case 3:
            strcpy(p->livro.categoria_livro, "Religiao");
            break;
        case 4:
            strcpy(p->livro.categoria_livro, "Ciencias sociais");
            break;
        case 5:
            strcpy(p->livro.categoria_livro, "Linguas");
            break;
        case 6:
            strcpy(p->livro.categoria_livro, "Ciencias puras");
            break;
        case 7:
            strcpy(p->livro.categoria_livro, "Tecnologia e ciencias aplicadas");
            break;
        case 8:
            strcpy(p->livro.categoria_livro, "Artes e recreacao");
            break;
        case 9:
            strcpy(p->livro.categoria_livro, "Literatura");
            break;
        case 10:
            strcpy(p->livro.categoria_livro, "Historia e geografia");
            break;
    }

    printf("\nNOME: %s\nID: %d\nANO DE PUBLICACAO: %d\nCATEGORIA: %s\nLivro Disponivel\n", p->livro.nome_livro, p->livro.ID_livro, p->livro.ano_livro, p->livro.categoria_livro);

    p->prox = ant->prox;
    ant->prox = p;
    printf("\nLivro cadastrado com sucesso e possui ID %d.\n", p->livro.ID_livro);
    return;
}


///REMOVE OS LIVROS
void RemoverLivro_ID(NoLivro *cab, int id){
    NoLivro *ant = NULL;
    NoLivro *p = ProcurarLivro_ID(cab, id, &ant);

    if(p == NULL){ ///Verificando se esse livro existe no cadastro
        printf("\nEsse livro nao se encontra no cadastro.\n");
        return;
    }

    if(strcmp(p->livro.livro_emprestimo, "0000000ABCD") != 0){ ///Verificando se o livro está emprestado
        printf("\nEsse livro encontra-se emprestado ao aluno de matricula %s e nao pode ser removido!\n", p->livro.livro_emprestimo);
        return;
    }

    ant->prox = p->prox;
    free(p);
    printf("\nLivro removido com sucesso!\n");
    return;
}