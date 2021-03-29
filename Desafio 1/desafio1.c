#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char produto[3][20];
int quantidade[3];

FILE *arquivo;

void WriteFile();
void ReadFile();

void CreateProduct();
void FindAllProducts();
void FindByName();
void FindByFirstLetter();
void AlterProduct();
void DeleteByName();

void main() {
    short menu;

    setlocale(LC_ALL, "portuguese");

    do{
        system("cls");
        printf("============= DESAFIO 01 - BEATRIZ, FABIO E JOAO =============\n\n");
        printf("1 Ц Entrada de dados\n");
        printf("2 Ц Lista todos os dados na tela\n");
        printf("3 Ц Pesquisa um produto com o nome completo e mostra na tela\n");
        printf("4 Ц Pesquisa os produtos pela 1к Letra e mostra todos na tela\n");
        printf("5 Ц Altera dados com pesquisa pelo produto com o nome completo\n");
        printf("6 Ц Exclui dados com pesquisa pelo produto com o nome completo\n");
        printf("7 - Sair\n");
        printf("\nDigite sua opчуo: ");
        scanf("%d", &menu);
        system("cls");

        switch(menu){
            case 1:
                CreateProduct();
                break;

            case 2:
                FindAllProducts();
                break;

            case 3:
                FindByName();
                break;

            case 4:
                FindByFirstLetter();
                break;

            case 5:
                getch();
                exit(0);
                break;

            case 6:
                getch();
                exit(0);
                break;

            case 7:
                printf("Obrigado! Pressione qualquer tecla para sair...");
                getch();
                exit(0);
                break;

        }

    }while(menu != 7);

}

void WriteFile(){
    arquivo = fopen("arquivo", "w");

    fwrite(&produto, sizeof(produto), 1, arquivo);
    fwrite(&quantidade, sizeof(quantidade), 1, arquivo);

    fclose(arquivo);
}

void ReadFile(){
    arquivo = fopen("arquivo", "r");

    if(arquivo == NULL){
        printf("\nErro de Leitura no arquivo! Arquivo inexistente!");
        exit(1);
    }

    fread(&produto, sizeof(produto), 1, arquivo);
    fread(&quantidade, sizeof(quantidade), 1, arquivo);

}

void CreateProduct() {
    printf("CADASTRO DE PRODUTOS\n");

    for(int i = 0; i<3 ; i++){
        getchar();
        printf("\nDigite o produto %d: ", i+1);
        gets(produto[i]);

        do{
            printf("Digite a quantidade do produto %d: ", i+1);
            scanf("%d", &quantidade[i]);

            if (quantidade[i] <= 0) {
                printf("Quantidade deve ser maior que zero!\n\n");
            }

        }while(quantidade[i] <= 0);

    }

    WriteFile();

    printf("\n\nPressione qualquer tecla para voltar ao menu...");
    getch();
}

void FindAllProducts() {
    ReadFile();
    printf("LISTA DE PRODUTOS SALVOS NO ARQUIVO\n\n");

    for (int i = 0; i < 3; i++){
        printf("Produto %d: %s\n", i+1, produto[i]);
        printf("Quantidade do Produto %d: %d\n\n", i+1, quantidade[i]);
    }

    fclose(arquivo);

    printf("Pressione qualquer tecla para voltar ao menu...");
    getch();
}

void FindByName() {
    short i=0, j=0, cont=0;
    char search_produto[30];

    printf("PESQUISA DE PRODUTOS POR NOME COMPLETO\n\n");
    printf("Digite o nome do produto que deseja pesquisar: ");
    getchar();
    gets(search_produto);

    ReadFile();

    for (i = 0; i < 3; i++){

        for (j = 0; search_produto[j] != '\0'; j++){
            if(search_produto[j] != produto[i][j]){
                break;
            }
        }

        if(search_produto[j] == '\0' && produto[i][j] == '\0'){
            printf("\nNome: %s\nQuantidade: %d\n", produto[i], quantidade[i]);
            fclose(arquivo);
        }
        else{
            cont++;
        }
    }
    if(cont == 3){
        printf("\nNenhum produto com o nome digitado foi encontrado!\n");
    }
    printf("\nPressione qualquer tecla para voltar ao menu...");
    getch();

}

void FindByFirstLetter() {
    short i=0, cont=0;
    char search_letra;

    printf("PESQUISA DE PRODUTOS PELA PRIMEIRA LETRA\n\n");
    printf("Digite a primeira letra do produto que deseja pesquisar: ");
    getchar();
    search_letra = getchar();

    ReadFile();

    for (i = 0; i < 3; i++) {
        if(search_letra == produto[i][0]) {
            printf("\nNome: %s\nQuantidade: %d\n", produto[i], quantidade[i]);
            cont++;
        }
    }
    if(cont == 0) {
        printf("\nNenhum produto com a letra digitada foi encontrado!\n\n");
    }

    fclose(arquivo);

    printf("\nPressione qualquer tecla para voltar ao menu...");
    getch();
}
