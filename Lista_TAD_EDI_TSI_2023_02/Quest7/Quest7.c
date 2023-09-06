/*
7) Implemente um TAD para representar conjuntos de elemento inteiros. Seu tipo abstrato deverá
armazenar os elemenyos(números inteiros) do conjunto e o número de elementos n. Considere que o
tamanho máximo de um conjunto é limitado pela memória principal (você deverá usar alocação dinâmica)
e deve crescer de 10 em 10 elementos. Use arranjos unidimensionais (vetores) para implementar o TAD.
Por exemplo, considerando que o seu conjunto armazena os elementos 5, 2, 3, 9, e 1, seu TAD deverá ter a
seguinte estrutura:
elementos
n = 5
obs.
a) Guarde o tamanho atual do vetor;
b) Lembre-se ainda que segundo a definição de conjuntos os elementos são únicos, ou seja, seu TAD deve
impedir a existência de elementos repetidos.
As operações que devem ser realizadas em seu TAD são:
a) criar um conjunto vazio;
b) detroi o conjunto;
c) inserir um elemento no conjunto, retornando 1 se possível e 0 senão;
d) excluir um elemento do conjunto, retornando 1 se realizado e 0 senão;
e) recuperar elemento de uma posição do conjunto, retornando em 1 caso de sucesso e 0 em caso contrário;
f) testar se um elemento está presente no conjunto, retornando sua posição ou -1 se não estiver presente;
g) comparar 2 conjuntos, retornando 1 se são iguais e 0 se são diferentes;
h) realizar a união de dois conjuntos e retornar o conjunto obtido;
i) realizar a interção de dois conjuntos e retornar o conjunto gerado;
j) subtrar dois conjuntos A e B e retornar o conjunto obtido.
Faça um programa para testar as operações do TAD desenvolvido.
*/