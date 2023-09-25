/*Faça um programa que possua o menu:
1 – Cadastro
2 – Consulta
3 – Alterar
4 - Listar
5 – Fim
caso a opção selecionada seja:
1 – Permitir que se cadastre a matrícula, nome e salário de no máximo 30 funcionários.
Obs.:
a) A matrícula é única
b) Aceitar apenas valores positivos para o campo salário
2 – Pedir ao usuário uma valor e mostrar os dados do funcionário que possua matrícula igual ao valor
fornecido.
3 – Pedir ao usuário uma valor e alterar os dados do  funcionário que possua matrícula igual ao valor fornecido.
4 – Listar os dados de todos os funcionários*/

#include <stdio.h>
#include <locale.h>
#include <string.h>

typedef struct{
   int matricula;
   char nome[100];
   float salario;
}TFuncionario;

void retiraEnter(char *s){
   if(s[strlen(s)-1]=='\n')
      s[strlen(s)-1]='\0';
}
/*retorna a "posição" do registro ou -1 se não existir um funcionário
com matrícula igual a parâmetro mat.*/
int pesquisa(FILE *arq,int mat){
   TFuncionario rf;
   int posicao=0;
   /*posicionando no início do arquivo*/
   fseek(arq,0,SEEK_SET);
   /*rewind(arq);*/

   while(fread(&rf,sizeof(TFuncionario),1,arq)==1){
      if(rf.matricula==mat)
         return posicao;
      else
         posicao++;
   }
   return -1;
}
void cadastro(FILE *arq){
   int mat,sair;
   TFuncionario r;
   do{
     printf("\nForneça a Matrícula:");
     scanf("%d",&mat);
     if(pesquisa(arq,mat)==-1){
       r.matricula=mat;
       setbuf(stdin,NULL);
       printf("Forneça o Nome:");
       fgets(r.nome,100,stdin);
       retiraEnter(r.nome);
       setbuf(stdin,NULL);
       printf("Forneça o Salário:");
       scanf("%f",&r.salario);
       /*posicionando no final do arquivo*/
       fseek(arq,0,SEEK_END);
       fwrite(&r,sizeof(TFuncionario),1,arq);
     }
     else
       printf("\nMatrícula Repetida!!!!!");
     printf("\nDeseja Sair? 1 - Sim 2 - Não");
     scanf("%d",&sair);

   }while (sair!=1);
}

void listar(FILE *a){
   TFuncionario rf;
   fseek(a,0,SEEK_SET);/*posiciona no início do arquivo*/
   printf("\nListagem de Funcionários\n");
   printf("\nMatrícula\t\tNome\t\t\t\t\tSalário");
   while(fread(&rf,sizeof(TFuncionario),1,a))
      printf("\n%d\t\t\t%s\t\t\t\t%.2f",rf.matricula,rf.nome,rf.salario);
}

 /*conmsulta pela matrícula*/

void consulta(FILE *arq){
   int mat, sair,posicao;
   TFuncionario r;
   fseek(arq,0,SEEK_END);
   if(ftell(arq)>0){
     do{
       printf("Forneça a matrícula:");
       scanf("%d",&mat);
       posicao = pesquisa(arq,mat);
       if(posicao!=-1){
         fseek(arq,posicao*sizeof(TFuncionario),SEEK_SET);
         fread(&r,sizeof(TFuncionario),1,arq);
         printf("\n Dados do Funcionário\n");
         printf("\nMatrícula = %d",r.matricula);
         printf("\nNome = %s",r.nome);
         printf("\nMatrícula = %.2f",r.salario);
       }
       else
        printf("\nMatrícula não Cadastrada!!!");

       printf("\nDeseja Sair da Consulta? 1-Sim 2-Não");
       scanf("%d",&sair);
     }while(sair !=1);
   }
   else
      printf("\nNenhum Funcionário Cadastrado!!!!");
}

 /*altera o nome e o salário de um  funcionário com determinada matrícula*/

void alteracao(FILE *arq){
   int mat, sair,posicao;
   TFuncionario r;
   do{
      printf("Fçorneça a matrícula:");
      scanf("%d",&mat);
      posicao = pesquisa(arq,mat);
      if(posicao!=-1){
         r.matricula=mat;
         printf("\nForneça o Nome:");
         setbuf(stdin,NULL);
         fgets(r.nome,100,stdin);
         setbuf(stdin,NULL);
         printf("Forneça o Salário:");
         scanf("%f",&r.salario);
         fseek(arq,posicao*sizeof(TFuncionario),SEEK_SET);
         fwrite(&r,sizeof(TFuncionario),1,arq);
      }
      else
        printf("\nMatrícula não Cadastrada!!!");

      printf("\nDeseja Sair da Ateração? 1-Sim 2-Não");
      scanf("%d",&sair);
   }while(sair !=1);
}

int main(){
   FILE *a;
   int opcao;
   setlocale(LC_ALL,"Portuguese");
   a=fopen("dados.dat","rb+");

   if(a==NULL){
      a= fopen("dados.dat","wb+");

   }
   /*número de registros do arquivo*/
   fseek(a,0,SEEK_END);
   printf("\nNúmero de Registros = %d",ftell(a)/sizeof(TFuncionario));

   if(a!=NULL){
     do{
       printf("\n1-Cadastro\n2-Consulta\n3-Aterar\n4-Listar\n5-sair");
       printf("\nFlorneça sua opção:");
       scanf("%d",&opcao);

       switch(opcao){
       case 1:
         cadastro(a);
         break;
       case 2:
         consulta(a);
         break;
       case 3:
         alteracao(a);
         break;
       case 4:
         listar(a);
         break;
       }
     }while(opcao!=5);
     fclose(a);
   }
   else
      printf("\nErrro na abertura do arquivo!!!\n");

   return 0;
}
