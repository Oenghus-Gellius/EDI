/*
9) Faça uma editor de textos, onde o texto possa ter tantas linhas quanto o usuário desejar. Use uma
estrutura de dados em memória composta por um vetor de ponteiros para strings, ou seja, cada
elemento do vetor é um ponteiro que aponta para uma cadeia de caracteres. Cada nova linha de
texto deve ser alocada dinamicamente com o comando calloc/malloc, e o ponteiro para esta linha
de texto deve ser adicionado ao vetor de ponteiros. O vetor de ponteiros deve inicialmente prever
um certo tamanho, por exemplo, 100 ponteiros (texto de 100 linhas), e quando as 100 linhas
estiverem ocupadas, você deve expandir este vetor de ponteiros. Para expandir o vetor de ponteiros
adote a seguinte estratégia: o último ponteiro do vetor, ao invés de conter o endereço de uma string
irá conter o endereço de mais uma tabela de 100 ponteiros, alocada dinamicamente. A figura
abaixo apresenta um esquema de como ficará a estrutura de dados prevista para este editor de
textos
*/