/*
Seu c�digo implementa o algoritmo QuickSort em C utilizando a escolha do piv� como o elemento do meio. Vou explicar passo a passo como esse algoritmo ordenaria um vetor, considerando os vetores "ABABABA" e "QUICKSORT".

Vetor "ABABABA":

Escolha do Piv�: O piv� � o elemento do meio, que � "B".
Particionamento Inicial: O vetor � dividido em duas partes: � esquerda, elementos menores ou iguais a "B"; � direita, elementos maiores que "B". O vetor ap�s o particionamento inicial pode ser "AAAAABB".
Recurs�o nos Subvetores: O algoritmo � aplicado recursivamente aos subvetores resultantes.
Subvetor � esquerda ("AAAAA"): O piv� � escolhido como "A" (meio do subvetor). O subvetor j� est� ordenado.
Subvetor � direita ("B"): O subvetor com um elemento j� est� ordenado.
Vetor "QUICKSORT":

Escolha do Piv�: O piv� � o elemento do meio, que � "S".
Particionamento Inicial: O vetor � dividido em duas partes: � esquerda, elementos menores ou iguais a "S"; � direita, elementos maiores que "S". O vetor ap�s o particionamento inicial pode ser "ICKQOSRTU".
Recurs�o nos Subvetores: O algoritmo � aplicado recursivamente aos subvetores resultantes.
Subvetor � esquerda ("ICKQO"): Piv� escolhido como "K". Os subvetores resultantes podem ser "CIOKQ" e "OQTU". Aplicamos o mesmo processo a ambos.
Subvetor � direita ("SRTU"): Piv� escolhido como "T". Os subvetores resultantes podem ser "RSTU". Aplicamos o mesmo processo a ambos.
O processo continua at� que todos os subvetores tenham apenas um elemento, e o vetor esteja ordenado.

Lembre-se de que o desempenho real do QuickSort pode variar dependendo da escolha do piv� e de outros fatores de implementa��o. Essa implementa��o que voc� forneceu � uma vers�o cl�ssica do QuickSort que utiliza a estrat�gia de divis�o e conquista.
*/
