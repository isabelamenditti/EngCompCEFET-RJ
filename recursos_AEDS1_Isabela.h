#ifndef recursos_AEDS1_Isabela
#define recursos_AEDS1_Isabela

///TODAS AS FUNÇÕES DE RECURSOS

int HashRecursos(int numero_recurso); ///HASH ATRAVÉS DO TIPO DE RECURSO

int HashRecursosID(int id); ///HASH DE RECURSOS ATRAVÉS DO ID

void ListarRecursos(NoRecurso *TabelaRecursos[]); ///LISTA TODOS OS RECURSOS CADASTRADOS EM UM ARQUIVO

void ListarRecursosTipo(NoRecurso *cab); ///LISTA OS RECURSOS DE DETERMINADO TIPO

NoRecurso *ProcurarRecurso_ID(NoRecurso *cab, int id, NoRecurso **ant); ///PROCURA OS RECURSOS

void DadosRecurso_ID(NoRecurso *cab, int id); ///MOSTRAR DADOS DE UM RECURSO ESPECÍFICO

void AdicionarRecurso(NoRecurso *cab, int tipo); ///ADICIONA OS RECURSOS

void RemoverRecurso_ID(NoRecurso *cab, int id); ///REMOVE OS RECURSOS

#endif