// Airton dos Santos Oliveira 123118 Turma I

#include <stdio.h>
#include <stdlib.h>
#define max_p 100

typedef struct
{
    int vet[max_p];
    int topo;

} Tpilha;

void IniciaPilha(Tpilha *p)  //  inicializa pilha e  atribui -1 ao topo
{
    p->topo = -1;
}

void push(Tpilha *p, int n)
{
    if(p->topo == max_p-1)  // verifica se a pilha esta cheia
    {
        printf("Pilha cheia!");
    }
    else
    {
        p->topo++; // aumenta o topo em um indice no vetot
        p->vet[p->topo] =n;
    }
}
int pop(Tpilha *p, int* n)
{

    if(p->topo== -1)
        return -1; //pilha vazia
    *n = p->vet[p->topo];
    p->topo--;
    return 0;



}


int main()
{

    Tpilha *pilhaA = (Tpilha*) malloc(sizeof(Tpilha));
    Tpilha *pilhaB = (Tpilha*) malloc(sizeof(Tpilha));
    int  i;
    char n,
    IniciaPilha(p);

    do
    {

        scanf("%c",&n);

        if(n<0)
        {

            break;
        }
        else
        {
            push(pilha, n);
        }




    }
    while(1);

    free(pilha);

    return 0;
}
