//Airton dos Santos Oliveira 123118 Turma - I
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct no
{
    char info;
    struct no *esq;
    struct no *dir;
} Tno;


int main()
{
    FILE *arq;


    Tno *raiz = (Tno *)malloc(sizeof(Tno)); //inicializa a raiz
    raiz->esq = NULL;
    raiz->dir = NULL;
    raiz->info = '0'; //com '0'

    int i = 0;
    char lintxt[20]; //aguenta arvores genericas com ate 20 filhos por nó

    arq = fopen("arv.txt", "r");

    while (!feof(arq)) //enquanto nao houver um erro no arquivo
    {
        if (fgets(lintxt, 20, arq) != NULL)
        {
            //se existir uma proxima linha
            if (i == 0)
            {
                criaArvore(raiz, lintxt); //se i == 0, entao é a primeira inserção, não há necessidade de busca na arvore
                i++;
            }
            else
            {
                if (lintxt[1] != '0')
                    busca(raiz, lintxt); //se lintxt[1] == 0, o nó então nao possui filhos, sem necessidade de busca e inserção
            }
        }
    }


    int j;
    char nob;
    printf("Escolha uma das opções de 1 á 5\n");
    printf("1) Imprimir a árvore resultante em pré-ordem;\n");
    printf("2) Imprimir a árvore resultante em ordem infixa;\n");
    printf("3) Imprimir os filhos de um dado nó\n");
    printf("4) Imprimir os irmão de um dado nó\n");
    printf("5) Sair\n\n");

    scanf("%d",&j);

    switch(j)
    {
    case 1:

        mostra_arvore(raiz);
         printf("\n\n");
        break;

    case 2:
        mostra_arvorei(raiz);
         printf("\n\n");
        break;

    case 3:
         printf("\n\n");
        break;
    case 4:

         printf("\n\n");
        break;
    case 5:
        exit(0);
        break;

    }


    fclose(arq);
    return 0;
}

void criaArvore(Tno *raiz, char *info)
{

    char *num_filhos = &info[1];   //pega o numero de filhos (em  string)
    int filhos = atoi(num_filhos); //transforma esse numero para int
    int i = 2;                     //posição do primeiro filho

    if (raiz->info == '0')
    {
        //primeira inserção, raiz com valor '0'
        raiz->info = info[0]; //insere o valor da raiz
        raiz->dir = NULL;
    }

    Tno *novo = (Tno *)malloc(sizeof(Tno));
    novo->esq = NULL;
    novo->info = info[i]; //cria o novo elemento com o primeiro filho [pos 2 do array]

    i++;      //proxima posição
    filhos--; //1 filho ja foi

    Tno *percorre = novo;
    Tno *novo2;

    while (filhos > 0)
    {
        //enquanto existerem filhos, vao sendo colocados e direita de seu irmao, formando uma 'lista', o ponteiro 'novo' aponta para o primeiro dessa lista
        novo2 = (Tno *)malloc(sizeof(Tno));
        novo2->info = info[i];
        novo2->esq = NULL;
        percorre->dir = novo2;
        percorre = novo2;
        filhos--;
        i++;
    }

    percorre->dir = NULL; //o ultimo irmao nao aponta para ninguem

    raiz->esq = novo; //o primeiro filho, que é o começo da lista de irmãos, é colocado a esquerda de seu pai.
}

void busca(Tno *raiz, char *info)
{
    if (raiz->info == info[0])
    {
        criaArvore(raiz, info); //se encontrou o valor, ele é o pai a receber filhos a esquerda
    }

    if (raiz->esq)
        busca(raiz->esq, info); //busca na sub arvore esquerda
    if (raiz->dir)
        busca(raiz->dir, info); //busca na sub arvore direita
}



void mostra_arvore(Tno *raiz)
{
   if(raiz!=NULL){

   printf(" %c",raiz->info);
   mostra_arvore(raiz->esq);
    mostra_arvore(raiz->dir);
    }}

void mostra_arvorei(Tno *raiz)
{
    //mostra a arvore em ordem
    if (raiz->esq)
        mostra_arvorei(raiz->esq);
    printf(" %c ", raiz->info);
    if (raiz->dir)
        mostra_arvorei(raiz->dir);
}





