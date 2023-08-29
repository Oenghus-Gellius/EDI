#include <stdio.h>

int main(int argC,char *argV[]){
    FILE *arq;
    int i,matricula;
    float salario;
    char nome[100];

    arq = fopen("funcionarios.txt","r+");


    if(arq!=NULL){
        printf("\nListagem de Funcionários\n");
        printf("Matrícula\t\tNome\t\t\t\tSalário\n");
        fseek(arq,0,SEEK_SET);
        //rewind(arq);
        while(1){
            fgets(nome,18,arq);
            if (fscanf(arq,"%d %f",&matricula,&salario)!=2)
               break;
            printf("%d\t\t%s\t\t\t\t%.2f\n",matricula,nome,salario);
            getc(arq);
        }
        fclose(arq);
    }
    else
        printf("\nErro na Abertura do Arquivo!!!\n");
    return 0;
}
