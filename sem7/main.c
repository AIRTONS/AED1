//Airton dos Santos Oliveira 123118 TURMA I
#include <stdio.h>
#include <stdlib.h>


typedef struct lista // estrutura do tipo lista duplamente encadeada
{
    char palavra;
    struct lista* ant;//ponteiro para o anterior
    struct lista* prox;// ponteiro para o proximo
} TLista;

typedef TLista *PLista;
void imprimelista(PLista primeiro)
{
    PLista p;

    if (primeiro !=NULL)
    {
        p = primeiro->prox;
        /* percorre os elementos até alcançar novamente o
        início */

        do
        {

            printf("  %c",p->palavra);
            p = p->prox;

        }
        while (p != NULL);


    }
}



PLista Insere_Fim (PLista l, char v)
{
    PLista aux;
    PLista novo = (PLista) malloc(sizeof(TLista)); // faz a alocação para inserção de um novo nó
    if (novo == NULL)
    {
        return NULL;
    }
    novo->palavra = v;
    novo->prox = NULL;
    if (l == NULL)   // sera o primeiro
    {
        novo->ant = NULL;
        l = novo;
        return novo;
    }
    else



        aux = l;

    while(aux->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->prox = novo;
    novo->ant = aux;
    return l;
}


int checaletra(PLista l, char l1, char l2)
{
    PLista p;
    int cont = 0;
    for (p=l; p!=NULL; p=p->prox)//percorre a lista
    {
        if (p->palavra == l1)
        {
            p->palavra=l2;// se o elemento for igual a primeira letra. recebe a segunda
            cont++;
        }

        else if (p->palavra == l2)
        {
            p->palavra=l1;// se for igual a segunda, recebe a primeira
            cont++;
        }
    }
    if(cont<2){
            printf("letra nao encontrada\n");
    }



    return cont;
}
void  trocaletra(PLista l, char l1,char l2)
{
    PLista p;
    int cont = 0;
    for (p=l; p!=NULL; p=p->prox)//percorre a lista
    {
        if (p->palavra == l1)
        {
            p->palavra=l2;// se o elemento for igual a primeira letra. recebe a segunda
            cont++;
        }

        else if (p->palavra == l2)
        {
            p->palavra=l1;// se for igual a segunda, recebe a primeira
            cont++;
        }
    }
}

PLista remove_lista(PLista li, int mat)
{
    if(li == NULL)
        return 0;
    PLista no=li;
    while(no != NULL && no->palavra != mat)
    {
        no = no->prox;
    }
    if(no == NULL)
        return 0; //não achou
    if(no->ant == NULL)//remover o primeiro
        li = no->prox;
    else
        no->ant->prox = no->prox;
    if(no->prox != NULL) // remove do meio ou fim
        no->prox->ant = no->ant;
    free(no);
    return li;

}




int main()
{
    TLista *primeiro= (TLista *)malloc(sizeof(TLista));
    primeiro->prox = NULL;// inicia com com null
    char palavra[20],l1,l2;
    int i;



    printf("Digite uma palavra:\n");
    scanf("%s",&palavra);

    for(i=0; i<strlen(palavra); i++)
    {
        Insere_Fim(primeiro,palavra[i]);// le a palavra inserida pelo usuario e insere letra pro letra em cada nó
    }
    imprimelista(primeiro); //imprime a lista após a inserção

    printf("\n\n");

    do{
        printf("Quais letras deseja trocar:");
        scanf(" %c",&l1);
        scanf(" %c",&l2);
        trocaletra(primeiro,l1,l2);
    }while(checaletra(primeiro,l1,l2)<2);
    trocaletra(primeiro,l1,l2);
    imprimelista(primeiro);//imprime a lista após a troca de letras
    return 0;
}
