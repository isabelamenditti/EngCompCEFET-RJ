#ifndef alunos_AEDS1_Isabela
#define alunos_AEDS1_Isabela

///TODAS AS FUNÇÕES DE ALUNOS

int HashAlunosID(int id); ///HASH DOS ALUNOS ATRAVES DO ID

int HashAlunosMatricula(char matricula[12]); ///HASH DOS ALUNOS ATRAVES DA MATRÍCULA

void ListarAlunos(NoAluno *TabelaAlunos[]); ///LISTA TODOS OS ALUNOS MATRICULADOS EM UM ARQUIVO

NoAluno *ProcurarAluno_ID(NoAluno *cab, int id, NoAluno **ant); ///PROCURA OS ALUNOS PELO ID

NoAluno *ProcurarAluno_Matricula(NoAluno *cab, char matricula[12], NoAluno **ant); ///PROCURA OS ALUNOS PELA MATRÍCULA

void DadosAluno_ID(NoAluno *cab, int id); ///MOSTRAR DADOS DE UM ALUNO ESPECÍFICO PROCURANDO PELO ID

void DadosAluno_Matricula(NoAluno *cab, char matricula[12]); ///MOSTRAR DADOS DE UM ALUNO ESPECÍFICO PROCURANDO PELA MATRÍCULA

void AdicionarAluno(NoAluno *cab, char matricula[12], char nome[50]); ///ADICIONA OS ALUNOS

void RemoverAluno_Matricula(NoAluno *cab, char matricula[12]); ///REMOVE OS ALUNOS PELA MATRÍCULA

void RemoverAluno_ID(NoAluno *cab, int id); ///REMOVE OS ALUNOS PELO ID

#endif