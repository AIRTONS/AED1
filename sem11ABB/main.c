

//Airton dos Santos Oliveira 123118 Turma - I
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arv
{
    int info;
    struct arv* esq;//estrutura de um nó
    struct arv*dir;
} TArv;

typedef TArv *PArv;// ponteiro para acessar as informações do nó



// verifica se uma arvore, a mesma é binaria de busca

int  verif_se_ABB(PArv raiz)
{

    if(raiz->esq)  verif_se_ABB(raiz->esq);

    if(raiz->esq && raiz->info < raiz->esq->info ) return 0;

    if(raiz->dir && raiz->info > raiz->dir->info) return 0;

    if(raiz->dir)  return verif_se_ABB(raiz->dir);

    return 1;
}

//faz a uniao entre duas arvores binarias de busca

PArv uniaoAB(PArv a,PArv b,)
{
    if(a==NULL && b==NULL)
    {
        printf("Arvores vazias\n\n");
    }
    else
    {
        insere(a, b->info);
    uniaoAB(a, b->esq);
    uniaoAB(a, b->dir);

    return a;

    }
}

