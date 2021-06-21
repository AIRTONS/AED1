
//Airton dos Santos Oliveira 123118

#include <stdio.h>
#include <stdlib.h>
#define MAX_FILA 100
//declaração de fila vazia
typedef struct
{
    int itens[MAX_FILA];
    int n; /* numeoro de elementos armazenados na fila*/
    int inicio; /* inicio da fila*/


} TFila;

typedef TFila *Pfila;

Pfila cria_fila()
{
    Pfila fila = (Pfila) malloc(sizeof(TFila)); // alocação pra Fila

    fila->inicio = 0;

    return(fila);

}

int insere (Pfila p, int val)
{

    int fim;
    if (p==NULL )// Verifica se a fila foi ou nao inicializada
{
    printf("Fila nao inicializada!\n");

        return -1;
    }
    if (p->n == MAX_FILA )
{

    printf("Fila cheia!\n");
        return -1;
    }
    fim = (p->inicio+p->n)%MAX_FILA;
          p->itens[fim] = val;
          p->n++;
          return 0;

}

int incr_indice(int i)
{
    if (i==MAX_FILA-1)
        return 0;
    else
        return i+1;

}
int retira (Pfila p, int* val)
{
    if (p==NULL)
    {

        printf("fila nao inicializada!\n");
        return -1;
    }
    if (p->n == 0)
    {
        printf("Fila vazia!\n");
        return -1;
    }
    *val = p->itens[p->inicio];
    p->inicio = incr_indice(p->inicio);
    p->n--;
    return 0;
}

int main()
{

    Pfila filanotas, filacand;

    int cand[MAX_FILA],n,i;
    int  notas[MAX_FILA];
    int vagas;
    char resposta;

    filacand  = cria_fila();// cria fila
    filanotas = cria_fila();


    printf("Qual a quantidade de candidatos:\n");
    scanf("%d",&n);

    printf("Quantidade de vagas:\n");
    scanf("%d",&vagas);

    i=0;
    while(i<n)
    {
        printf("Numero Identificador do candidato:");
        scanf("%d",&cand[i]);

        if(insere(filacand,cand[i])==-1)// insere e verifica o valor que volta da função
            printf("canditado nao inserido\n");

        printf("Nota do candidato:");
        scanf("%d",&notas[i]);

        if(insere(filanotas,notas[i])==-1)
            printf("nota nao inserida\n");

        printf("Candidato inserido.\n\n\n");
        i++;

    }

    printf("Candidatos inseridos\n");

    i=0;
    while(i<n)
    {

        if(retira(filacand,&cand[i])==-1 || retira(filanotas,&notas[i])==-1)
        {
            printf ("Não foi possivel retirar o elemento da fila.\n");
            break;
        }

        else
        {

            printf("Candidato %d, Nota: %d\n" ,cand[i],notas[i]);
        }
        i++;
    }

    for(i=0; i<n; i++)
    {
        printf("Resposta  do candidato de id %d (s/n):",cand[i]);
        scanf(" %c",&resposta);

        if(resposta == 's')
        {
            insere(filacand,cand[i]) && insere(filacand,notas[i]);
        }
        else
            retira(filacand,&cand[i]) && retira(filacand,&notas[i]);

    }

    printf("-Lista de Novos Alunos:\n\n ");

    i=0;
    while(i<vagas)
    {

        if(retira(filacand,&cand[i])==-1)
        {
            printf ("Não foi possivel retirar o elemento da fila.\n");
            break;
        }
        else
        {
            printf("Candidato %d\n" ,filacand->itens[i]);
        }
        i++;
    }

    free(filacand);
    free(filanotas); // libera o espaço alocado



    return 0;
}
