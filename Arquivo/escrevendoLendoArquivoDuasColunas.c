#include <stdio.h>

int main(int argC,char *argV[]){
    FILE *arq;
    int i,matricula;
    float salario;
    const int N=1;

    arq = fopen("funcionarios.txt","r+");

    if(arq==NULL)
        arq = fopen("funcionarios.txt","w+");

    if(arq!=NULL){
        fseek(arq,0,SEEK_END);
        for(i=1;i<=N;i++){
            printf("\nDados do %do. Funcionário\n",i);
            printf("Matrícula:");
            scanf("%d",&matricula);
            printf("Salário:");
            scanf("%f",&salario);
            fprintf(arq,"%d %f\n",matricula,salario);

        }

        printf("\nListagem de Funcionários\n");
        printf("Matrícula\tSalário\n");
        fseek(arq,0,SEEK_SET);
        //rewind(arq);
        while(fscanf(arq,"%d %f",&matricula,&salario)==2)
            printf("%d\t%.2f\n",matricula,salario);
        fclose(arq);
    }
    else
        printf("\nErro na Abertura do Arquivo!!!\n");
    return 0;
}
