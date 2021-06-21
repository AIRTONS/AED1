//Airton Dos Santos Oliveira-123118 Turma I

#include <stdio.h>
#include <stdlib.h>


int main()
{

    int *votos,n,i;
    int vencedor,aux;


    printf("Qual o numero de canditados?\n" ); //pergunte ao usuario a quantidade N de candidatos existentes
        scanf("%d",&n);
        if(n == 0){
        printf("Nao existem candidatos!");
        }
        else {
        votos = (int *) malloc(n*sizeof(int));//alocação dinâmica para o vetor que armazenará os votos
         if (votos==NULL){

        printf("Não foi possivel alocar o vetor\n");//  mensagem caso ocorra erro na alocação
        exit(0);
        }

        printf("Escolha um canditado de 1 à %d:\n", n);

         scanf("%d",&aux);
         if(aux>n){
         printf("Canditado invalido!\n");
         }
           (*(votos+aux-1))++;

     while(aux>=0)
     {
        printf("Escolha um canditado de 1 à %d:\n",n);

          scanf("%d",&aux);
           if(aux>n){
         printf("Canditado invalido!\n");
         }
            (*(votos+aux-1))++;// vai até a posição de referencia do candidato e incrementa 1 voto;
      }
        printf("Fim da votação:\n");

         vencedor=0;

        for(i=0; i<n;i++)
    {
        if(votos[i]>=votos[vencedor])// caso de empate o candidato de maior referencial ganha

          vencedor = i;
    }

    printf("O candidato  vencedor é o de numero: %d\n", vencedor+1);//imprima candidato com mais votos, ou seja, o vencedor da eleição.




   free(votos);
}
    return 0;

}
