# EngCompCEFET-RJ_T-AEDS1
All the projects and assignments I completed during college.

Trabalho realizado em linguagem C para a disciplina de Estruturas e Algoritmos de Dados 1.

Enunciado:

O CEFET começou a reconstruir o acervo de sua biblioteca, e para o gerenciamento virtual da biblioteca foi decidido que seria selecionado um aluno da Engenharia de Computação para criar um novo software de gerenciamento. Na hora da seleção, você tirou a sorte grande e foi escolhido para desenvolver esse software. Agora a biblioteca do CEFET está em suas mãos e cabe a você trazê-la à sua antiga glória!

Os seus supervisores lhe mandaram um conjunto de especificações a serem seguidas. Essas especificações detalham as funcionalidades que o software de gerenciamento precisa ter para acomodar as necessidades da biblioteca:

1) Gerenciamento de Alunos: os alunos que desejam realizar atividades na biblioteca podem ter seu cadastro realizado. O cadastro é composto pelo nome e matrícula do aluno (composta de números e letras), assim como um ID gerado pela biblioteca. Deve ser possível adicionar e remover cadastros, assim como listar todos os cadastros e também buscar o cadastro de um aluno a partir de seu ID. Não deve ser possível remover o cadastro de um aluno que possui alguma pendência com a biblioteca (pegou algo emprestado e ainda não devolveu);

2) Gerenciamento de Livros: a biblioteca também possui seu acervo de livros físicos. Para gerenciar esse acervo é necessário um registro digital desses livros. Os livros possuem nome, ano de publicação, categoria e um ID gerado pela biblioteca. Deve ser possível adicionar e remover livros nesse registro, assim como listar todos os livros e também buscar os livros por ID e por categoria. Outra funcionalidade necessária é o empréstimo de livros. No empréstimo de livros, deve ser possível que alunos peguem ou devolvam um livro emprestado, mudando seu estado. Para isso, o registro do livro também deve conter um estado (disponível ou emprestado), assim como o ID de um aluno atribuído ao livro caso o estado seja emprestado. Vale lembrar que essas informações também devem aparecer na listagem ou busca dos livros, sendo que ao invés do ID do aluno deve ser mostrada a sua matrícula. Também não deve ser possível remover o registro de um livro que ainda não foi devolvido;

3) Gerenciamento de Salas, Computadores e Armários: algumas salas, computadores e armários da biblioteca podem ser emprestados para os alunos. Como a infraestrutura da biblioteca pode mudar (novas salas podem ser construídas, computadores podem quebrar, etc) logo deve haver um registro para esses recursos. Um recurso possui um ID inserido manualmente, um tipo (sala, computador ou armário), um estado (livre ou ocupado) e um ID de aluno atribuído ao recurso caso o mesmo esteja ocupado. Deve ser possível adicionar, remover e listar esses recursos, assim como buscá-los por ID. Também deve ser possível que alunos ocupem ou desocupem esses recursos, mudando seu estado. Não deve ser possível remover um recurso que está ocupado. Vale lembrar que na listagem ou busca, a matrícula do aluno que está ocupando o recurso deve ser mostrada ao invés do ID desse aluno;
