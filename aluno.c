#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs_AEDS1_Isabela.h"
#include "alunos_AEDS1_Isabela.h"

///TABELA HASH DE ALUNOS
int HashAlunosID(int id){
    int chave, hash; ///Posição i que encontra-se esse ID na tabela.
    chave = id%1000000;
    chave = chave/10000;
    hash = chave%tam_alunos;
    return hash;
}

int HashAlunosMatricula(char matricula[12]){ ///Posição i que encontra-se essa Matrícula na tabela.
    int chave, hash;
    chave = (matricula[0] - 48)*10 + matricula[1] - 48;
    hash = chave%tam_alunos;
    return hash;
}


///LISTA TODOS OS ALUNOS MATRICULADOS EM UM ARQUIVO
void ListarAlunos(NoAluno *TabelaAlunos[]){
    FILE *a; ///ponteiro para o arquivo que lista todos os alunos
    a = fopen("alunos_cadastrados.txt", "w");

    fprintf(a, "\nLISTA DE ALUNOS MATRICULADOS:\n");

    ///Imprimindo cada Lista Encadeada da Tabela Hash
    for(int i=0; i<tam_alunos; ++i){
        NoAluno *p = TabelaAlunos[i]->prox;
        if(TabelaAlunos[i]->prox != NULL){
            while(p != NULL){
                fprintf(a, "\nNOME: %s\nMATRICULA: %s\nID: %d\n", p->aluno.nome_aluno, p->aluno.matricula_aluno, p->aluno.ID_aluno);
                fprintf(a, "PENDENCIAS: ");
                int x=0;
                for(int i=0; i<8; ++i){
                    if(p->aluno.pendencia_aluno[i] != 0){
                        ++x;
                        fprintf(a, "%d ", p->aluno.pendencia_aluno[i]);
                    }
                }
                if(x ==0){
                    fprintf(a, "Nao ha!");
                }
                fprintf(a, "\n");
                p = p->prox;
            }
        }
    }
    fclose(a);
    return;
}


///PROCURA OS ALUNOS
NoAluno *ProcurarAluno_ID(NoAluno *cab, int id, NoAluno **ant){ ///mecanismo de busca do aluno através do ID
    (*ant) = cab;
    NoAluno *p = cab->prox;
    
    while(p != NULL && p->aluno.ID_aluno < id){
        (*ant) = p;
        p = p->prox;
    }
    return p;
}

NoAluno *ProcurarAluno_Matricula(NoAluno *cab, char matricula[12], NoAluno **ant){ ///mecanismo de busca do aluno através da Matrícula
    (*ant) = cab;
    NoAluno *p = cab->prox;
    
    while(p != NULL && (strcmp(p->aluno.matricula_aluno, matricula)<0)){
        (*ant) = p;
        p = p->prox;
    }
    return p;
}


///MOSTRAR DADOS DE UM ALUNO ESPECÍFICO
void DadosAluno_ID(NoAluno *cab, int id){
    NoAluno *ant = NULL;
    NoAluno *p = ProcurarAluno_ID(cab, id, &ant);
    if(p == NULL){
        printf("\nEsse aluno nao se encontra no cadastro.\n");
        return;
    }
    printf("\nNOME: %s\nMATRICULA: %s\nID: %d\n", p->aluno.nome_aluno, p->aluno.matricula_aluno, p->aluno.ID_aluno);

    printf("PENDENCIAS: ");
    int x = 0;
    for(int i=0; i<8; ++i){
        if(p->aluno.pendencia_aluno[i] != 0){
            ++x;
            printf("%d ", p->aluno.pendencia_aluno[i]);
        }
    }
    if(x == 0){
        printf("Nao ha!");
    }
    printf("\n");
    return;
}

void DadosAluno_Matricula(NoAluno *cab, char matricula[12]){
    NoAluno *ant = NULL;
    NoAluno *p = ProcurarAluno_Matricula(cab, matricula, &ant);
    if(p == NULL){
        printf("\nEsse aluno nao se encontra no cadastro.\n");
        return;
    }
    printf("\nNOME: %s\nMATRICULA: %s\nID: %d\n", p->aluno.nome_aluno, p->aluno.matricula_aluno, p->aluno.ID_aluno);
    
    printf("PENDENCIAS: ");
    int x=0;
    for(int i=0; i<8; ++i){
        if(p->aluno.pendencia_aluno[i] != 0){
            ++x;
            printf("%d ", p->aluno.pendencia_aluno[i]);
        }
    }
    if(x == 0){
        printf("Nao ha!");
    }
    printf("\n");
    return;  
}


///ADICIONA OS ALUNOS
void AdicionarAluno(NoAluno *cab, char matricula[12], char nome[50]){
    NoAluno *ant = NULL;
    NoAluno *p = ProcurarAluno_Matricula(cab, matricula, &ant);
    
    if(p != NULL && (strcmp(p->aluno.matricula_aluno, matricula)==0)){ ///Verificando se o aluno já se encontra cadastrado no sistema
        printf("\nEssa matricula ja esta cadastrada!\n");
        return;
    }

    ///produzir ID do Aluno através da matrícula
    int u, d, c, m, um, dm, id;
    u = matricula[6] - 48;
    d = (matricula[5] - 48)*10;
    c = (matricula[4] - 48)*100;
    m = (matricula[3] - 48)*1000;
    um = (matricula[1] - 48)*10000;
    dm = (matricula[0] - 48)*100000;

    id = u + d +c + m + + um +dm + 1000000;

    ///inserindo a posição do novo aluno
    p = (NoAluno *)malloc(sizeof(NoAluno));
    strcpy(p->aluno.matricula_aluno, matricula);
    p->aluno.ID_aluno = id;
    strcpy(p->aluno.nome_aluno, nome);
    for(int i=0; i<8; ++i){ ///O aluno inicia sua matrícula com zero pendências
        p->aluno.pendencia_aluno[i] = 0;
    }
    p->prox = ant->prox;
    ant->prox = p;
    printf("\nAluno de Matricula %s foi cadastrado com sucesso e possui ID %d.\n", p->aluno.matricula_aluno, p->aluno.ID_aluno);
    return;
}


///REMOVE OS ALUNOS
void RemoverAluno_Matricula(NoAluno *cab, char matricula[12]){
    NoAluno *ant = NULL;
    NoAluno *p = ProcurarAluno_Matricula(cab, matricula, &ant);

    if(p == NULL){ ///Verificando se o aluno existe no cadastro
        printf("\nEsse aluno nao se encontra no cadastro.\n");
        return;
    }

    int pend=0; ///Analisando as pendências antes da remoção
    for(int i=0; i<8; ++i){
        if(p->aluno.pendencia_aluno[i] != 0){
            ++pend;
        }
    }

    if(pend > 0){ ///Para remover o aluno deve possuir o número de pendências == 0
        printf("\nO aluno possui %d pendencia(s) e nao pode ser removido!\n", pend);
        return;
    }
    ant->prox = p->prox;
    free(p);
    printf("\nAluno removido com sucesso!\n");
    return;
}

void RemoverAluno_ID(NoAluno *cab, int id){
    NoAluno *ant = NULL;
    NoAluno *p = ProcurarAluno_ID(cab, id, &ant);

    if(p == NULL){ ///Verificando se esse aluno existe no cadastro
        printf("\nEsse aluno nao se encontra no cadastro.\n");
        return;
    }

    int n=0; ///Analisando as pendências antes da remoção
    for(int i=0; i<8; ++i){
        if(p->aluno.pendencia_aluno[i] != 0){
            ++n;
        }
    }

    if(n > 0){ ///Para remover o aluno deve possuir o número de pendências == 0
        printf("\nO aluno possui %d pendencia(s) e nao pode ser removido!\n", n);
        return;
    }
    ant->prox = p->prox;
    free(p);
    printf("\nAluno removido com sucesso!\n");
    return;
}