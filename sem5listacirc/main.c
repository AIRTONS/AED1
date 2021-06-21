//Airton dos Santos Oliveira  RA:123118 Turma I
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lista
{
    int valorcarta;
    int soma;


    struct lista *prox;
} Tlista;

typedef Tlista *PLista;

void imprimelista(PLista ultimo)
{
    PLista p;
    int i;
    if (ultimo !=NULL)
    {
        p = ultimo->prox;
        /* percorre os elementos até alcançar novamente o
        início */
        i=3;
       do
        {

            printf("Jogador %d : %d pontos\n", i,p->valorcarta);
            p = p->prox;
            i--;

        }while (p != ultimo->prox);


    }
}

PLista insere(PLista ultimo, int val)
{
    PLista novo =(PLista)malloc(sizeof(Tlista));
    novo->valorcarta=val;
    novo->soma = novo->soma+val;

    if(ultimo==NULL)
    {
        ultimo=novo;
        novo->prox=novo;
    }

        else
    {
        novo->prox=ultimo->prox;
        ultimo->prox=novo;

    }
    if(novo->soma == 21 )

    {
        printf("Jogador campeão!");
            }

            ultimo=1;


    return ultimo;

}


void libera(PLista ultimo)
{
    PLista p = ultimo->prox;
    PLista q= ultimo;

    while(p!=ultimo)
    {
        q=p;
        p=p->prox;
        free(q);
    }
    free(ultimo);
}

int main()
{
    Tlista *ultimo= (Tlista *)malloc(sizeof(Tlista));
    ultimo->prox = NULL;
    int carta, jogadores;
    int A=11,J=10,K=10,Q=10;
    int i=0;


    printf("Digite a quantidade de jogadores:\n");
    scanf("%d", &jogadores);


    while(i < jogadores)
    {

        printf("Digite uma carta (numero de 2 a 9 ou as letras A, J, K ou Q):\n");
        scanf("%d",&carta);
        if((carta!= 'A' )&& (carta!= 'J' )&& (carta!= 'K') &&(carta!= 'Q') && ( carta<2 || carta >9))
        {
            printf("Valor invalido!! Digite novamente um novo valor.");

        }

        insere(ultimo,carta);



        i++;
        printf("\n");

    }

    imprimelista(ultimo);


    free(ultimo);




    return 0;
}
