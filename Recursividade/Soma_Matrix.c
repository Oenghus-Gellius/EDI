#include <stdio.h>

double potenciaNR(double a,int b){
    double pot=1;
    int i;
    for(i=1;i<=b;i++){
       pot*=a;//pot=pot*a;
    }
    return pot;
}

double potenciaR(double a,int b){
    if(b==0)
       return 1;
     else
       return a*potenciaR(a,b-1);
}

double potenciaDC(double a, int b){
    double aux;
    if(b==0)
       return 1;
    else{   
         aux = potenciaDC(a,b/2);
         if(b%2==0)
            return aux*aux;
         else
            return a*aux*aux;
    }
}
int soma(int n){
    int i,valor=0;
    for(i=1;i<=n;i++)
       valor+=i;
       
    return valor;   
}

//implementem uma funÃ§Ã£o recursiva para calcular a
//soma dos elementos de uma matriz bidimensional de inteiros
int somaMat(int m[][2],int nl,int nc,int linha,int coluna){
    if(linha==nl)
       return 0;
    else
        if(coluna ==nc)
          return somaMat(m,nl,nc,linha+1,0);
        else
           return m[linha][coluna] +somaMat(m,nl,nc,linha,coluna+1);
}

int somaMatriz(int m[][2],int nl,int nc){
    return somaMat(m,nl,nc,0,0);
}
int main(){
    int mat[2][2]={{1,2},{-1,2}};
    //printf("\n Resultado de 2 elavado a 3  = %lf\n",potenciaR(2,3));
    printf("\nSoma = %d\n",somaMatriz(mat,2,2));

    return 0;
}
