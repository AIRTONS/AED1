#include <stdio.h>
#include <stdlib.h>


typedef struct Pessoa{

char nome[30];
int idade;
float altura;

}tipo_pessoa;

int main()

{
    tipo_pessoa *p1;
    p1 = (tipo_pessoa *) malloc(sizeof(tipo_pessoa));


    printf("\nNome: ");
        scanf("%s", p1->nome);

    printf("Idade: ");
        scanf("%d", &p1->idade);

    printf("Altura: ");
        scanf("%f", &p1->altura);


    printf("Todos os dados da pessoa:\n%s\n %d anos de idade\n %.2f de altura ", p1->nome, p1->idade, p1->altura);

    free(p1);


}
