#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
int main(){
    TPonto *ponto1,*ponto2;
    ponto1= criaPonto(3,1);
    ponto2= criaPonto(2,4);
    printf("\nDistância = %f\n",distancia(ponto1,ponto2));
    printf("\nValores das coordenadas X = %f  e Y =%f\n",getX(ponto1),getY(ponto1));
    terminaPonto(ponto1);
    terminaPonto(ponto2);
    return 0;
}
