///ALGORITMOS E ESTRUTURAS DE DADOS I
///SOFTWARE DE GERENCIAMENTO DE UMA BIBLIOTECA

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "structs_AEDS1_Isabela.h"
#include "alunos_AEDS1_Isabela.h"
#include "livros_AEDS1_Isabela.h"
#include "recursos_AEDS1_Isabela.h"

/**
*A matrícula dos alunos possui o seguinte formato: 21 1 2106 GCOM (ano - semestre - número de matrícula - curso)
*O ID gerado pela biblioteca  para alunos possuirá o seguinte formato como no exemplo: 1 21 2106 (tipo de informação - ano - número de matrícula)
*O ID gerado pela biblioteca  para livros e recursos possuirá o seguinte formato como no exemplo: 203 1234 (tipo de informação - número de cadastro)

*TIPO DE INFORMAÇÃO:
*Alunos: 1

*Livros: 
*201 Ciência da computação, informação e generalidades;
*202 Filosofia e psicologia; 
*203 Religião; 
*204 Ciências sociais;
*205 Línguas;
*206 Ciências puras;
*207 Tecnologia e ciências aplicadas;
*208 Artes e recreação;
*209 Literatura;
*210 História e geografia.

*Recursos:
*301 Salas;
*302 Computadores;
*303 Armários.
*/

int main(){

    ///CRIAÇÃO DAS TABELAS HASH
    NoAluno *TabelaAlunos[tam_alunos]; ///Tabela Hash de alunos

    for(int i=0; i<tam_alunos; ++i){
        NoAluno *cab = (NoAluno *)malloc(sizeof(NoAluno));
        cab->prox = NULL;
        TabelaAlunos[i] = cab;  
    }

    NoLivro *TabelaLivros[tam_livros]; ///Tabela Hash de livros

    for(int i=0; i<tam_livros; ++i){
        NoLivro *cab = (NoLivro *)malloc(sizeof(NoLivro));
        cab->prox = NULL;
        TabelaLivros[i] = cab;  
    }

    NoRecurso *TabelaRecursos[tam_recursos]; ///Tabela Hash de recursos

    for(int i=0; i<tam_recursos; ++i){
        NoRecurso *cab = (NoRecurso *)malloc(sizeof(NoRecurso));
        cab->prox = NULL;
        TabelaRecursos[i] = cab;  
    }

    ///OPÇÕES DO MENU
    while(1){
        printf("\nO que voce deseja fazer?\n1. Cadastro/Descadastramento\n2. Emprestimo/Devolucao de Livros\n3. Emprestimo/Devolucao de Recursos\n4. Buscar Cadastro\n5. Listar Cadastros\n0. ENCERRAR PROGRAMA\n");

        int menu_principal, menu_secundario, menu_terciario;
        scanf("%d", &menu_principal);

        switch (menu_principal){

        int id, idE, n, m, pos, categoria, ano, tipo;
        char matricula[12], nome[50];

            case 1:
                
                printf("\n\t1. Adicionar ALUNO\n\t2. Remover ALUNO\n\t3. Adicionar LIVRO\n\t4. Remover LIVRO\n\t5. Adicionar RECURSO\n\t6. Remover RECURSO\n\t0. SAIR\n");
                scanf("%d", &menu_secundario);
                
                switch (menu_secundario){
                    
                    case 1:
                        ///Adicionar ALUNO
                        printf("\nInsira a Matricula: ");
                        scanf(" %[^\n]", matricula);
                        printf("\nInsira o nome: ");
                        scanf(" %[^\n]", nome);
                        n = HashAlunosMatricula(matricula);
                        AdicionarAluno(TabelaAlunos[n], matricula, nome);
                        break;
                    
                    case 2:
                        ///Remover ALUNO
                        printf("\n\t\t1. Remover atraves do ID\n\t\t2. Remover atraves da Matricula\n\t\t0. SAIR\n");
                        scanf("%d", &menu_terciario);

                        switch (menu_terciario){
                            case 1: ///Remover atraves do ID
                                printf("\nInsira o ID a ser removido: \n");
                                scanf("%d", &id);
                                n = HashAlunosID(id);
                                RemoverAluno_ID(TabelaAlunos[n], id);
                                break;

                            case 2: ///Remover atraves da Matricula
                                printf("\nInsira a matricula a ser removida: \n");
                                scanf(" %[^\n]", &matricula);
                                n = HashAlunosMatricula(matricula);
                                RemoverAluno_ID(TabelaAlunos[n], id);
                                break;

                            case 0: ///Sair
                                break;

                            default:
                                printf("\nOpcao Invalida!\n");
                                break;
                        }
                        break;

                    case 3:
                        ///Adicionar LIVRO
                        printf("\nInsira a categoria:\n\t1. Ciencia da computacao, informacao e generalidades\n\t2. Filosofia e psicologia\n\t3. Religiao\n\t4. Ciencias sociais\n\t5. Linguas\n\t6. Ciencias puras\n\t7. Tecnologia e ciencias aplicadas\n\t8. Artes e recreacao\n\t9. Literatura\n\t10. Historia e geografia\n");

                        scanf("%d", &categoria);
                        printf("\nInsira o nome do livro: ");
                        scanf(" %[^\n]", nome);
                        printf("\nInsira o ano de publicacao: ");
                        scanf("%d", &ano);
                        n = HashLivros(categoria);
                        AdicionarLivro(TabelaLivros[n], categoria, nome, ano);
                        break;

                    case 4:
                        ///Remover LIVRO
                        printf("\nInsira o ID a ser removido: \n");
                        scanf("%d", &id);
                        n = HashLivrosID(id);
                        RemoverLivro_ID(TabelaLivros[n], id);
                        break;

                    case 5:
                        ///Adicionar RECURSO
                        printf("\nInsira o tipo:\n\t1. Sala\n\t2. Computador\n\t3. Armario\n");
                        scanf("%d", &tipo);
                        n = HashRecursos(tipo);
                        AdicionarRecurso(TabelaRecursos[n], tipo);
                        break;

                    case 6:
                        ///Remover RECURSO
                        printf("\nInsira o ID a ser removido: \n");
                        scanf("%d", &id);
                        n = HashRecursosID(id);
                        RemoverRecurso_ID(TabelaRecursos[n], id);
                        break;

                    case 0: ///Sair
                        break;

                    default:
                        printf("\nOpcao Invalida!\n");
                        break;
                }
                break;
            
            case 2:
                printf("\n\t1. Emprestimo de LIVRO\n\t2. Devolucao de LIVRO\n\t0. SAIR\n");
                scanf("%d", &menu_secundario);
                
                printf("\nInsira o ID do aluno: "); ///Verificando o aluno e colhendo as informações
                scanf("%d", &id);
                n = HashAlunosID(id);
                NoAluno *antAl = NULL;
                NoAluno *Al = ProcurarAluno_ID(TabelaAlunos[n], id, &antAl);
                if(Al == NULL){
                    printf("\nEsse aluno nao se encontra no cadastro.\n");
                    break;
                }

                
                printf("\nInsira o ID do livro: "); ///Verificando o livro e colhendo as informações
                scanf("%d", &idE);
                m = HashLivrosID(idE);
                NoLivro *antL = NULL;
                NoLivro *L = ProcurarLivro_ID(TabelaLivros[m], idE, &antL);
                if(L == NULL){
                    printf("\nEsse livro nao se encontra no cadastro.\n");
                    break;
                }

                switch (menu_secundario){
                case 1:
                    ///Emprestimo de LIVRO
                    if(Al->aluno.pendencia_aluno[4] != 0){
                        printf("\nEsse aluno nao pode pegar mais livros!\n");
                        break;
                    }
                    for(int i=0; i<5; ++i){
                        if(Al->aluno.pendencia_aluno[i] == 0){
                            pos = i;
                            break;
                        }
                    }
                    Al->aluno.pendencia_aluno[pos] = L->livro.ID_livro;
                    strcpy(L->livro.livro_emprestimo, Al->aluno.matricula_aluno);
                    printf("\nLivro emprestado\n");
                    break;

                case 2:
                    ///Devolucao de LIVRO
                    for(int i=0; i<5; ++i){
                        if(Al->aluno.pendencia_aluno[i] == idE){
                            pos = i;
                            break;
                        }
                    }
                    Al->aluno.pendencia_aluno[pos] = 0;
                    strcpy(L->livro.livro_emprestimo, "0000000ABCD");
                    printf("\nLivro devolvido\n");
                    break;

                case 0: ///Sair
                    break;;

                default:
                    printf("\nOpcao Invalida!\n");
                    break;
                }
                break;
            
            case 3:
                printf("\n\t1. Emprestimo de RECURSO\n\t2. Devolucao de RECURSO\n\t0. SAIR\n");
                scanf("%d", &menu_secundario);
                
                printf("\nInsira o ID do aluno: "); ///Verificando o aluno e colhendo as informações
                scanf("%d", &id);
                n = HashAlunosID(id);
                NoAluno *antAr = NULL;
                NoAluno *Ar = ProcurarAluno_ID(TabelaAlunos[n], id, &antAr);
                if(Ar == NULL){
                    printf("\nEsse aluno nao se encontra no cadastro.\n");
                    break;
                }

                
                printf("\nInsira o ID do recurso: "); ///Verificando o recurso e colhendo as informações
                scanf("%d", &idE);
                m = HashLivrosID(idE);
                NoRecurso *antR = NULL;
                NoRecurso *R = ProcurarRecurso_ID(TabelaRecursos[m], idE, &antR);
                pos = R->recurso.numero_recurso;
                if(R == NULL){
                    printf("\nEsse recurso nao se encontra no cadastro.\n");
                    break;
                }

                switch (menu_secundario){
                case 1:
                    ///Emprestimo de RECURSO
                    if(Ar->aluno.pendencia_aluno[pos + 4] != 0){
                        printf("\nEsse aluno nao pode pegar mais recursos desse tipo!\n");
                        break;
                    }
                    Ar->aluno.pendencia_aluno[pos + 4] = R->recurso.ID_recurso;
                    strcpy(R->recurso.emprestimo_recurso, Ar->aluno.matricula_aluno);
                    printf("\nRecurso emprestado\n");
                    break;

                case 2:
                    ///Devolucao de RECURSO
                    Ar->aluno.pendencia_aluno[pos + 4] = 0;
                    strcpy(R->recurso.emprestimo_recurso, "0000000ABCD");
                    printf("\nRecurso devolvido\n");
                    break;

                case 0: ///Sair
                    break;

                default:
                    printf("\nOpcao Invalida!\n");
                    break;
                }
                break;
            
            case 4:
                printf("\n\t1. Buscar ALUNO\n\t2. Buscar LIVRO\n\t3. Buscar RECURSO\n\t0. SAIR\n");
                scanf("%d", &menu_secundario);
                
                switch (menu_secundario){
                    case 1:
                        ///Buscar ALUNO
                        printf("\n\t\t1. Buscar atraves do ID\n\t\t2. Buscar atraves da Matricula\n\t\t0. SAIR\n");
                        scanf("%d", &menu_terciario);

                        switch (menu_terciario){
                        case 1:
                            printf("\nInsira o ID a ser impresso: ");
                            scanf("%d", &id);
                            n = HashAlunosID(id);
                            DadosAluno_ID(TabelaAlunos[n], id);
                            break;

                        case 2:
                            printf("\nInsira a matricula a ser impressa: ");
                            scanf(" %[^\n]", matricula);
                            n = HashAlunosMatricula(matricula);
                            DadosAluno_Matricula(TabelaAlunos[n], matricula);
                            break;

                        case 0: ///Sair
                            break;

                        default:
                            printf("\nOpcao Invalida!\n");
                            break;
                        }
                        break;

                    case 2:
                        ///Buscar LIVRO
                        printf("\nInsira o ID a ser impresso: ");
                        scanf("%d", &id);
                        n = HashLivrosID(id);
                        DadosLivro_ID(TabelaLivros[n], id);
                        break;

                    case 3:
                        ///Buscar RECURSO
                        printf("\nInsira o ID a ser impresso: ");
                        scanf("%d", &id);
                        n = HashRecursosID(id);
                        DadosRecurso_ID(TabelaRecursos[n], id);
                        break;

                    case 0: ///Sair
                        break;

                    default:
                        printf("\nOpcao Invalida!\n");
                        break;
                }
                break;

            case 5:
                printf("\n\t1. Listar ALUNOS\n\t2. Listar LIVROS\n\t3. Listar RECURSOS\n\t0. SAIR\n");
                scanf("%d", &menu_secundario);

                switch (menu_secundario){
                    case 1:
                        ///Listar ALUNOS
                        ListarAlunos(TabelaAlunos);
                        printf("\nTodos os alunos foram listados no arquivo alunos_cadastrados.txt!\n");
                        break;     

                    case 2:
                        ///Listar LIVROS
                        printf("\n\t\t1. Listar por categoria\n\t\t2. Listar todos os livros em um arquivo\n\t\t0. SAIR\n");
                        scanf("%d", &menu_terciario);

                        switch (menu_terciario){
                            case 1: ///Lista por categoria
                                printf("\nQual categoria deseja listar?\n\t1. Ciencia da computacao, informacao e generalidades\n\t2. Filosofia e psicologia\n\t3. Religiao\n\t4. Ciencias sociais\n\t5. Linguas\n\t6. Ciencias puras\n\t7. Tecnologia e ciencias aplicadas\n\t8. Artes e recreacao\n\t9. Literatura\n\t10. Historia e geografia\n");
                                scanf("%d", &n);
                                ListarLivrosCategoria(TabelaLivros[n]);
                                break;

                            case 2: ///Lista todos
                                ListarLivros(TabelaLivros);
                                printf("\nTodos os livros foram listados no arquivo livros_cadastrados.txt!\n");
                                break;

                            case 0:
                                break;
                            default:
                                printf("\nOpcao Invalida!\n");
                                return 0;
                        }
                        break;

                    case 3:
                        ///Listar RECURSOS
                        printf("\n\t\t1. Listar por categoria\n\t\t2. Listar todos os recursos em um arquivo\n\t\t0. SAIR\n");
                        scanf("%d", &menu_terciario);

                        switch (menu_terciario){
                            case 1: ///Lista por categoria
                                printf("\nQual categoria deseja listar?\n\t1. Sala\n\t2. Computador\n\t3. Armario\n");
                                scanf("%d", &n);
                                ListarRecursosTipo(TabelaRecursos[n]);
                                break;

                            case 2: ///Lista todos
                                ListarRecursos(TabelaRecursos);
                                printf("\nTodos os recursos foram listados no arquivo recursos_cadastrados.txt!\n");
                                break;

                            case 0:
                                break;
                            default:
                                printf("\nOpcao Invalida!\n");
                                break;
                        }
                        break;

                    case 0: ///Sair
                        break;

                    default:
                        printf("\nOpcao Invalida!\n");
                        break;
                }
                break;
            case 0:
                return 0;
            default:
                printf("\nOpcao Invalida!\n");
                break;
        }
    }
    return EXIT_SUCCESS;
}