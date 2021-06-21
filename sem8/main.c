//Airton dos Santos Oliveira 123118 Turma I
#include <stdio.h>
#include <stdlib.h>
#define MAX_LINHA 10


typedef struct no *pme; //ponteiro para struct nó
struct no
{
    int  codigof,col;
    char genero;
    pme prox;
};
typedef pme matriz[MAX_LINHA];

/* inicializa a matriz m */
void inicializa(matriz m, int l)
{
    int i;
    for (i=0; i<l; i++)
        m[i] = NULL;
}

/* insere um elemento na matriz m */
void insere(matriz m, int i,int j, int codigof, char gen)
{
    pme novo, p;
    novo = (pme)malloc(sizeof(struct no));
    novo->col=j;
    novo->codigof= codigof ;
    novo->genero=gen;
    novo->prox = NULL;
    if (m[i]==NULL)
        m[i] = novo; //insere caso seja o primeiro elemento
    else
    {
        for(p = m[i]; p->prox!=NULL; p=p->prox)
            ;
        p->prox = novo;//caso nao seja o primeiro
    }
}
/* imprime a matriz incluindo */
void ImprimeI(matriz m, int lin, int col )
{
    int i,j;
    pme p;
    for(i=0; i<lin; i++)
    {
        p = m[i];
        for(j=0; j<col; j++)
        {
            if ((p!=NULL) && (p->col==j))// imprime a matriz de forma inteira
            {
                printf(" 0\t ");
                p = p->prox;
            }
            else
                printf(" 1\t");

        }
        printf("\n");
    }
    printf("\n");

}

void ImprimeC(matriz m, int lin, int col )
{
    int i,j;
    pme p;
    for(i=0; i<lin; i++)
    {
        p = m[i];
        for(j=0; j<col; j++)
        {
          if(p!=NULL && p->col==j)//imprime  a matriz de forma condensada
            {
                printf(" Cliente %d \nFilmes assistidos (filme e genero):\n", i+1);
                printf(" %d %c", p->codigof,p->genero);
                p = p->prox;
            }

            printf("\n");
        }
    }

}



/* libera os espaços de memória alocados para armazenar
as listas */
void libera(matriz m, int l)
{
    pme p, q;
    int i;
    for(i=0; i<l; i++)
    {
        p = m[i];
        while (p!=NULL)//percorre linha a linha e libera uma a uma
        {
            q = p;
            p = p->prox;
            free(q);
        }
    }
}

void VerificaGen(matriz m, int lin, int col )
{
    int i,maior=0;
    pme p,j;
    int a=0,s=0,c=0,po=0,mu=0,f=0,r=0,dr=0;// variaveis que representam os generos

    for(i=0; i<lin; i++)
    {
        p = m[i];
        for(j= m[i]; j!=NULL; j=j->prox)// percorre a matriz e verifica o genero de cada nó
        {
            if (p->genero=='a')
            a++; //incrementa conforma o genero identificado
            if (p->genero=='s')
            s++;
            if (p->genero=='c')
            c++;
            if (p->genero=='p')
            po++;
            if (p->genero=='m')
            mu++;
            if (p->genero=='f')
            f++;
            if (p->genero=='r')
            r++;
            if (p->genero=='d')
            dr++;



        }
    }
    int  vet[8] = {a, s, c, po, mu, f, r, dr};//  atribui os generos a um vetor
    for (i=0; i<8; ++i)
    {
        if (vet[i] > maior)
            maior = vet[i];//e verifica qual o maior
    }
    if(maior == a){
    printf("o Genero mais assistido é  Ação\n\n");}
   else if(maior == s){
    printf("o Genero mais assistido é Suspense\n ");}//imprime o genero mais assistido
    else if(maior == r){
    printf("o Genero mais assistido é Romance\n");}
    else if(maior == dr){
    printf("o Genero mais assistido é  Drama\n");}
    else if(maior == po){
    printf("o Genero mais assistido é Policial\n");}
   else if(maior == c){
    printf("o Genero mais assistido é Comedia\n");}
   else if(maior == mu){
    printf("o Genero mais assistido é Musical\n");}
    else if(maior == f){
    printf("o Genero mais assistido é Ficcão\n");}
}
int main()
{
    matriz m;
    int clientes, filmes, fc, i, j, codf;
    char gen;

    printf("Quantidade de clientes da plataforma:");
    scanf("%d", &clientes);

    printf("Quantidade de filmes disponiveis:");
    scanf("%d", &filmes);
    inicializa(m,clientes);

    for(i=0; i<clientes; i++)
    {
        printf("Quantos filmes o cliente %d assistiu:", i+1);
        scanf(" %d",&fc);
        while(fc<0  || fc>filmes)// verifica se o numero de filmes assistido esta dentro do permitido
        {
            printf("Quantidade invalida:");
            scanf(" %d",&fc);
        }

        for(j=0; j<fc; j++)
        {
            printf("Digite o numero do %dº filme assistido:", j+1);
            scanf(" %d",&codf);
            while(codf<0  || codf>filmes) // verifica se se o codigo do filme esta no catalogo
            {
                printf("Filme invalido, insira outro:");
                scanf(" %d",&codf);
            }
            printf("Genero do filme:");
            scanf(" %c",&gen);
        }
        if(codf!=0) insere(m,i,j,codf,gen);// se o valor de entrada for diferente de zero faz a inserção
    }
    printf("-------Matriz inteira:-----\n");
    ImprimeI(m,clientes,filmes); // função imprime inteira

    printf("-------Matriz condensada:-----\n");
    ImprimeC(m,clientes,filmes);// função imprime condensada

   VerificaGen(m,clientes,filmes);// verifica genero + assistido





    libera(m,clientes);// libera a matriz
    return(0);
}
