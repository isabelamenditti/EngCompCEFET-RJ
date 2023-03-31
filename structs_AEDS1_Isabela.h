#ifndef structs_AEDS1_Isabela
#define structs_AEDS1_Isabela

///ESTRUTURA DOS DADOS DOS ALUNOS
/**Consideramos que cada aluno pode pegar no máximo 5 livros e 1 recurso de cada tipo.
*/
typedef struct{
    char matricula_aluno[12];
    int ID_aluno;
    char nome_aluno[50];
    int pendencia_aluno[8]; ///o vetor pendencia recebe os IDs dos livros e recursos que o aluno está utilizando
}Aluno;

///ESTRUTURA DA LISTA ENCADEADA DOS ALUNOS
typedef struct no_aluno{
    Aluno aluno;
    struct no_aluno *prox;
}NoAluno;

///TABELA HASH DE ALUNOS
/**O tamanho 11 foi considerado em virtude de cada aluno poder ter sua matrícula ativa por apenas 10 anos, que é o tempo máximo para a formação.
*Com base nisso, a lista encadeada gerada em cada posição da tabela Hash armazenará os alunos matriculados por ano.
*/
#define tam_alunos 11

///ESTRUTURA DOS DADOS DOS LIVROS
typedef struct{
    int ID_livro;
    char nome_livro[60];
    int ano_livro;
    int numero_categoria; ///De acordo com a classificação abaixo:
    ///Ciência da computação, informação e generalidades(1); Filosofia e psicologia(2); Religião(3); Ciências sociais(4); Línguas(5);
    ///Ciências puras(6); Tecnologia e ciências aplicadas(7); Artes e recreação(8); Literatura(9); História e geografia(10).
    char categoria_livro[60];
    char livro_emprestimo[12]; ///registra a Matrícula do aluno que está com o livro
}Livro;

///ESTRUTURA DA LISTA ENCADEADA DOS LIVROS
typedef struct no_livro{
    Livro livro;
    struct no_livro *prox;
}NoLivro;

///TABELA HASH DE LIVROS
/**O tamanho 10 foi considerado em virtude dos tipos de livros existentes.
*Com base nisso, a lista encadeada gerada em cada posição da tabela Hash armazenará os livros por gênero literário.
*/
#define tam_livros 10

///ESTRUTURA DOS DADOS DOS RECURSOS
typedef struct{
    int ID_recurso;
    int numero_recurso; 
    char tipo_recurso[11]; /// sala(1), computador(2) e armário(3)
    char emprestimo_recurso[12]; ///registra o ID do aluno que está utilizando o recurso
}Recurso;

///ESTRUTURA DA LISTA ENCADEADA DOS RECURSOS
typedef struct no_recurso{
    Recurso recurso;
    struct no_recurso *prox;
}NoRecurso;

///TABELA HASH DE RECURSOS
/**O tamanho 3 foi considerado em virtude dos tipos de recursos existentes: sala(1), computador(2) e armário(3).
*Com base nisso, a lista encadeada gerada em cada posição da tabela Hash armazenará recursos por tipo.
*/
#define tam_recursos 3

#endif