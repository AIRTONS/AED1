#include <stdio.h>
#include <stdlib.h>
#define MAX_LINHA 10


/*********Airton dos Santos Oliveira 132118 turma N  ******************/

typedef struct no *Grf;
struct no
{
    int col;
    Grf prox;
};

typedef Grf grafo[MAX_LINHA];

void inicializa(grafo g, int l)
{
    int i;
    for (i = 0; i < l; i++)
    {
        g[i] = (Grf)malloc(sizeof(struct no));
        g[i]->prox = NULL;
    }
}
/* insere um elemento na matriz m */
void insere(Grf g, int valcol)
{
    Grf novo, p;
    novo = (Grf)malloc(sizeof(struct no));
    novo->prox = NULL;

    novo->col = valcol;
    if (g->prox == NULL)
    {
        g->prox = novo;
    }
    else
    {
        p = g->prox;
        while (p->prox != NULL)
        {
            p = p->prox;
        }

        p->prox = novo;
    }
}

/* imprime a matriz incluindo */
void imprime(grafo g, int vertices)
{
    int i = 0;
    Grf p;
    for (i = 0; i < vertices; i++)
    {
        p = g[i]->prox;
        printf("vertice [%d] : ", i+1);
        while (p != NULL)
        {
            printf("%d ", p->col);
            p = p->prox;
        }
        printf("\n");
    }
}



/*  imprime o os vertices adjacentes ao vertice inserido*/
void imprime_vertice(Grf vertice, int indice)
{
    Grf p = vertice->prox;

    printf("vertice [%d] : ", indice);
    while (p != NULL)
    {
        printf("%d ", p->col);
        p = p->prox;
    }
    printf("\n");
}

int main()
{
    grafo *g;

    int  vertlin, vertcol;
    int i,n,d;


    scanf("%d %d", &n,&d);
 inicializa(n, d);



    while (i<d)
    {
        scanf("%d", &vertlin);
        if (vertlin == 0)
            break;
        scanf("%d", &vertcol);
        insere(g[vertlin - 1], vertcol);

        insere(g[vertcol - 1], vertlin);

    }

    imprime(g, n);

    imprime_vertice(g,n);

    return (0);
}
