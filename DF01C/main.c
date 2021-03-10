#include <stdio.h>
#include <stdlib.h>


struct RegistroProduto{
    char produto[3][20];
    int quantidade[3];
};

typedef struct RegistroProduto RegistroProduto;


void entraDados(RegistroProduto *prod) {
    int max = 3;
    if(quantidade[3] == max)
    {
        printf("Numero maximo de produtos atingido, nao eh possivel cadastrar novo produto\n")
    }
    else
    {
       printf("\nDigite o nome do produto:\n");
        printf("Nome: ");
        scanf_s("\n%[^\n]", prod->produto, 20);
        printf("Quantidade: ");
        scanf_s("%s", prod->quantidade, 5);
     }

};

int main(){
    RegistroProduto prod;
    menuPrincipal(&prod);

    return 0;
};


