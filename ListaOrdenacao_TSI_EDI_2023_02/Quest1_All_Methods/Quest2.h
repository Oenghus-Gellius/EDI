/*
Seu código implementa o algoritmo QuickSort em C utilizando a escolha do pivô como o elemento do meio. Vou explicar passo a passo como esse algoritmo ordenaria um vetor, considerando os vetores "ABABABA" e "QUICKSORT".

Vetor "ABABABA":

Escolha do Pivô: O pivô é o elemento do meio, que é "B".
Particionamento Inicial: O vetor é dividido em duas partes: à esquerda, elementos menores ou iguais a "B"; à direita, elementos maiores que "B". O vetor após o particionamento inicial pode ser "AAAAABB".
Recursão nos Subvetores: O algoritmo é aplicado recursivamente aos subvetores resultantes.
Subvetor à esquerda ("AAAAA"): O pivô é escolhido como "A" (meio do subvetor). O subvetor já está ordenado.
Subvetor à direita ("B"): O subvetor com um elemento já está ordenado.
Vetor "QUICKSORT":

Escolha do Pivô: O pivô é o elemento do meio, que é "S".
Particionamento Inicial: O vetor é dividido em duas partes: à esquerda, elementos menores ou iguais a "S"; à direita, elementos maiores que "S". O vetor após o particionamento inicial pode ser "ICKQOSRTU".
Recursão nos Subvetores: O algoritmo é aplicado recursivamente aos subvetores resultantes.
Subvetor à esquerda ("ICKQO"): Pivô escolhido como "K". Os subvetores resultantes podem ser "CIOKQ" e "OQTU". Aplicamos o mesmo processo a ambos.
Subvetor à direita ("SRTU"): Pivô escolhido como "T". Os subvetores resultantes podem ser "RSTU". Aplicamos o mesmo processo a ambos.
O processo continua até que todos os subvetores tenham apenas um elemento, e o vetor esteja ordenado.

Lembre-se de que o desempenho real do QuickSort pode variar dependendo da escolha do pivô e de outros fatores de implementação. Essa implementação que você forneceu é uma versão clássica do QuickSort que utiliza a estratégia de divisão e conquista.
*/
