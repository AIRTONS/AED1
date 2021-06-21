#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{

    FILE *nomes;
    nomes = fopen("nomes.txt", "w" );// abre o arquivo.txt
    printf("Arquivo aberto para escrita.\n");

    char pessoas[100];
    char s[]="FIM";
    int retorno;

    printf("Escreva nomes e ao terminar digite FIM:\n");
            scanf("%s",pessoas);
             fprintf(nomes, "%s\n", pessoas);

    while(retorno = strcmp(s, pessoas) != 0){
            scanf("%s",pessoas);
                   fprintf(nomes, "%s\n", pessoas);

    }


     fclose(nomes);


    return 0;
}
