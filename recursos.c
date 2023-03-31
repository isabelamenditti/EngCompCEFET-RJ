#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs_AEDS1_Isabela.h"
#include "recursos_AEDS1_Isabela.h"

///TABELA HASH DE RECURSOS
int HashRecursos(int numero_recurso){
    int hash; ///Posição i que encontra-se esse tipo na tabela.
    hash = numero_recurso%tam_recursos;
    return hash;
}

int HashRecursosID(int id){
    int chave, hash; ///Posição i que encontra-se esse ID na tabela.
    chave = id/10000;
    hash = chave%tam_recursos;
    return hash;
}


///LISTA TODOS OS RECURSOS CADASTRADOS EM UM ARQUIVO
void ListarRecursos(NoRecurso *TabelaRecursos[]){
    FILE *r; ///ponteiro para o arquivo que lista todos os recursos
    r = fopen("recursos_cadastrados.txt", "w");

    fprintf(r, "\nLISTA DE RECURSOS CADASTRADOS:\n");

    ///Imprimindo cada Lista Encadeada da Tabela Hash
    for(int i=0; i<tam_recursos; ++i){
        NoRecurso *p = TabelaRecursos[i]->prox;
        if(TabelaRecursos[i]->prox != NULL){
            while(p != NULL){
                fprintf(r, "\nID: %d\nTIPO: %s\n", p->recurso.ID_recurso, p->recurso.tipo_recurso);
                if(strcmp(p->recurso.emprestimo_recurso, "0000000ABCD") != 0){
                    fprintf(r, "EMPRESTIMO: %s\n", p->recurso.emprestimo_recurso);
                }else{
                    fprintf(r, "Recurso Disponivel\n");
                }
                p = p->prox;
            }
        }
    }
    fclose(r);
    return;
}


///LISTA OS RECURSOS DE DETERMINADO TIPO
void ListarRecursosTipo(NoRecurso *cab){
    printf("\nLISTA DE RECURSOS DO TIPO SELECIONADO:\n");

    NoRecurso *p = cab->prox;
    if(cab->prox != NULL){
        while(p != NULL){
            printf("\nID: %d\nTIPO: %s\n", p->recurso.ID_recurso, p->recurso.tipo_recurso);
            if(strcmp(p->recurso.emprestimo_recurso, "0000000ABCD") != 0){
                printf("EMPRESTIMO: %s\n", p->recurso.emprestimo_recurso);
            }else{
                printf("Recurso Disponivel\n");
            }
            p = p->prox;
        }
    }else{
        printf("\nNao existem recursos desse tipo!\n");
    }
    return;
}


///PROCURA OS RECURSOS
NoRecurso *ProcurarRecurso_ID(NoRecurso *cab, int id, NoRecurso **ant){ ///mecanismo de busca do livro através do ID
    (*ant) = cab;
    NoRecurso *p = cab->prox;
    
    while(p != NULL && p->recurso.ID_recurso < id){
        (*ant) = p;
        p = p->prox;
    }
    return p;
}


///MOSTRAR DADOS DE UM RECURSO ESPECÍFICO
void DadosRecurso_ID(NoRecurso *cab, int id){
    NoRecurso *ant = NULL;
    NoRecurso *p = ProcurarRecurso_ID(cab, id, &ant);
    if(p == NULL){
        printf("\nEsse recurso nao se encontra no cadastro.\n");
        return;
    }
    printf("\nID: %d\nTIPO: %s\n", p->recurso.ID_recurso, p->recurso.tipo_recurso);
    if(strcmp(p->recurso.emprestimo_recurso, "0000000ABCD") != 0){
        printf("EMPRESTIMO: %s\n", p->recurso.emprestimo_recurso);
    }else{
        printf("Recurso Disponivel\n");
    }
    return;
}


///ADICIONA OS RECURSOS
void AdicionarRecurso(NoRecurso *cab, int tipo){
    NoRecurso *ant = NULL;
    (*&ant) = cab;
    NoRecurso *p = cab->prox;
    
    int id = 0; ///Produzindo o ID do recurso adicionado
    if(p == NULL){ ///Para categoria que ainda não possua nenhum recurso
        id = 3000000 + tipo*10000 + 1;
        printf("%d", id);
    }
    else{
        while (p != NULL){ ///Para categoria que já possua algum recurso
            id = p->recurso.ID_recurso + 1; ///o ID sempre será baseado no ID do recurso anterior
            (*&ant) = p;
            p = p->prox;
            printf("%d", id);
        }    
    }

    ///Inserindo a posição do novo livro
    p = (NoRecurso *)malloc(sizeof(NoRecurso));
    p->recurso.ID_recurso = id;
    p->recurso.numero_recurso = tipo;
    strcpy(p->recurso.emprestimo_recurso, "0000000ABCD"); ///o recurso começa não estando emprestado

    switch (tipo){
        case 1:
            strcpy(p->recurso.tipo_recurso, "Sala");
            break;
        case 2:
            strcpy(p->recurso.tipo_recurso, "Computador");
            break;
        case 3:
            strcpy(p->recurso.tipo_recurso, "Armario");
            break;
    }
    printf("\nID: %d\nTIPO: %s\nRecurso Disponivel\n", p->recurso.ID_recurso, p->recurso.tipo_recurso);

    p->prox = ant->prox;
    ant->prox = p;
    printf("\nRecurso cadastrado com sucesso e possui ID %d.\n", p->recurso.ID_recurso);
    return;
}


///REMOVE OS RECURSOS
void RemoverRecurso_ID(NoRecurso *cab, int id){
    NoRecurso *ant = NULL;
    NoRecurso *p = ProcurarRecurso_ID(cab, id, &ant);

    if(p == NULL){ ///Verificando se esse recurso existe no cadastro
        printf("\nEsse recurso nao se encontra no cadastro.\n");
        return;
    }

    if(strcmp(p->recurso.emprestimo_recurso, "0000000ABCD") != 0){ ///Verificando se o livro está emprestado
        printf("\nEsse recurso encontra-se emprestado ao aluno de matricula %s e nao pode ser removido!\n", p->recurso.emprestimo_recurso);
        return;
    }

    ant->prox = p->prox;
    free(p);
    printf("\nRecurso removido com sucesso!\n");
    return;
}