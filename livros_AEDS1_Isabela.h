#ifndef livros_AEDS1_Isabela
#define livros_AEDS1_Isabela

///TODAS AS FUNÇÕES DE LIVROS
int HashLivros(int numero_categoria); ///HASH DE LIVROS ATRAVÉS DA CATEGORIA

int HashLivrosID(int id); ///HASH DE LIVROS ATRAVÉS DO ID

void ListarLivros(NoLivro *TabelaLivros[]); ///LISTA TODOS OS LIVROS CADASTRADOS EM UM ARQUIVO

void ListarLivrosCategoria(NoLivro *cab); ///LISTA OS LIVROS DE DETERMINADA CATEGORIA

NoLivro *ProcurarLivro_ID(NoLivro *cab, int id, NoLivro **ant); ///PROCURA OS LIVROS

void DadosLivro_ID(NoLivro *cab, int id); ///MOSTRAR DADOS DE UM LIVRO ESPECÍFICO

void AdicionarLivro(NoLivro *cab, int num_categoria, char nome[50], int ano); ///ADICIONA OS LIVROS

void RemoverLivro_ID(NoLivro *cab, int id); ///REMOVE OS LIVROS

#endif