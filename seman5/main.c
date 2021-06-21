//Airton dos Santos Oliveira  123118
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    int cod_produto;
    char nome_produto[30];//struct que armazena os itens do produto
    float preco_produto;
    struct lista *prox;
} Tlista;

typedef Tlista *PLista;// ponteiro que aponta para struct

PLista inicializa_lista()
{
    return NULL;;//inicializa alista
}

void mostra_lista(Tlista* cabeca)
{
    Tlista *percorre = cabeca->prox;//percorre será o primeiro elemento da lista

    while (percorre != NULL)  //enquanto existir um elemento sucessor
    {
        printf("itens da lista : %s %d %.2f\n", percorre->nome_produto, percorre->cod_produto, percorre->preco_produto); //printa os valores do produto
        percorre = percorre->prox; //percorre agr recebe o produto sucessor
    }

}

void insere_na_lista(Tlista* cabeca, char nome_produto[30],int cod_produto,float preco_produto)
{

    Tlista *novo;
    novo = (Tlista *)malloc(sizeof(Tlista));//cria um novo produto vazio

    strcpy(novo->nome_produto, nome_produto);
    novo->cod_produto = cod_produto;
    novo->preco_produto = preco_produto;

    if(cabeca->prox == NULL)
    {
        cabeca->prox = novo;
        novo->prox = NULL;
        return;
    }



    Tlista *percorre = cabeca->prox;

    if(cabeca->prox->cod_produto > novo->cod_produto)
    {
        novo->prox = cabeca->prox;
        cabeca->prox = novo;
    }
    else
    {
        while(1)
        {
            if(percorre->prox != NULL && percorre->prox->cod_produto < novo->cod_produto)
            {
                percorre = percorre->prox;
            }

            else if(percorre->prox == NULL || percorre->prox->cod_produto > novo->cod_produto)
            {
                novo->prox = percorre->prox;
                percorre->prox = novo;
                return;
            }
        }
    }

}






PLista busca (Tlista* l, int cod)
{



    PLista p;
    for (p=l; p!=NULL; p=p->prox)//percorre a lista e verifica se o item da lista é igual ao informado pelo usuario


        if (p->cod_produto == cod)
            printf("o  preço desse produto é %.2f R$\n\n", p->preco_produto);
    return p;




    return NULL; /* não achou o elemento */

}
PLista retira (PLista l, char v)
{
    PLista ant = NULL; /* ponteiro para elemento anterior */
    PLista p; /* ponteiro para percorrer a lista*/
    /* procura elemento na lista, guardando anterior */
    for (p=l; p!=NULL && p->cod_produto!=v; p = p->prox)

        ant = p;

    /* verifica se achou elemento */
    if (p == NULL)
        return l; /* não achou: retorna lista original */
    /* retira elemento */
    if (ant == NULL)
        /* retira elemento do inicio */
        l = p->prox;
    else
        /* retira elemento do meio da lista */
        ant->prox = p->prox;
    free(p);
    return l;
}


void libera (PLista l)
{

    PLista p = l, t;
    while (p != NULL)
    {

        t = p->prox; /* guarda referência para o próximo elemento*/
        free(p);
        p = t; /* faz p apontar para o próximo */

    }
}

PLista insere_ord(PLista l, int dado)
{
    PLista novo; //novo elemento
    PLista ant = NULL; //ponteiro auxiliar para a posição anterior
    PLista ptaux = l; //ponteiro auxiliar para percorrer a lista
    /*aloca um novo nodo */
    novo = (Tlista*) malloc(sizeof(Tlista));
    /*insere a informação no novo nodo*/
    novo->cod_produto = dado;
    /*procurando a posição de inserção*/
    while ((ptaux!=NULL) && (ptaux->cod_produto)<dado)
    {

        ant = ptaux;
        ptaux = ptaux->prox;

    }
    /*encadeia o elemento*/
    if (ant == NULL) /*o anterior não existe, será inserido na 1a posição*/
    {
        novo->prox = l;
        l = novo;
    }
    else /*elemento inserido no meio da lista*/
    {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}





int main()
{
    Tlista *cabeca = (Tlista *)malloc(sizeof(Tlista));
    cabeca->prox = NULL;
    int cod_produto, i = 0;
    char nome_produto[30];
    float preco_produto;
    int n_prod;


    printf("Numero de produtos a ser inseridos:\n");
    scanf("%d", &n_prod);


    while(i < n_prod)
    {

        printf("Nome do produto:\n");
        scanf("%s", nome_produto);
        printf("Codigo do produto:\n");
        scanf("%d", &cod_produto);
        printf("Preço do produto:\n");
        scanf("%f", &preco_produto);

        insere_na_lista(cabeca,nome_produto, cod_produto,preco_produto );
        i++;
        printf("\n");
        printf("Produto inserido!\n");


    }
    mostra_lista(cabeca);

    printf("Deseja saber o preço de qual produto?\n");

    scanf("%d",&cod_produto);

    busca(cabeca, cod_produto);

    mostra_lista(cabeca);

    printf("Deseja excluir qual produto?\n");

    scanf("%s", nome_produto);

    retira(cabeca, nome_produto);

    printf("produto removido da lista\n\n");








    return 0;
}5
