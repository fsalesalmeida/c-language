#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char produto[3][20];
int quantidade[3];

FILE *arquivo;

void WriteFile();
int ReadFile();

void CreateProduct();
void FindAllProducts();
int FindByName();
void FindByFirstLetter();
void UpdateProduct();
void DeleteProduct();

void main() {
    short menu;

    setlocale(LC_ALL, "portuguese");

    do{
        printf("\n============= DESAFIO 01 - C05 - BEATRIZ, FABIO E JOAO =============\n\n");
        printf("1 � Entrada de dados\n");
        printf("2 � Lista todos os dados na tela\n");
        printf("3 � Pesquisa um produto com o nome completo e mostra na tela\n");
        printf("4 � Pesquisa os produtos pela 1� Letra e mostra todos na tela\n");
        printf("5 � Altera dados com pesquisa pelo produto com o nome completo\n");
        printf("6 � Exclui dados com pesquisa pelo produto com o nome completo\n");
        printf("7 - Saida\n");
        printf("\nDigite sua op��o: ");
        scanf("%d", &menu);

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
                UpdateProduct();
                break;

            case 6:
                DeleteProduct();
                break;

            case 7:
                exit(0);

            default:
                printf("\n============= Op��o Inv�lida - Escolha de 1 a 7! =============\n\n");

        }

    }while(menu != 7);

}

void WriteFile(){
    arquivo = fopen("c05", "w");

    fwrite(&produto, sizeof(produto), 1, arquivo);
    fwrite(&quantidade, sizeof(quantidade), 1, arquivo);

    fclose(arquivo);
}

int ReadFile(){
    arquivo = fopen("c05", "r");

    if(arquivo == NULL){
        printf("\nErro de Leitura no arquivo ou Arquivo inexistente! ");
        return(1);
    }

    fread(&produto, sizeof(produto), 1, arquivo);
    fread(&quantidade, sizeof(quantidade), 1, arquivo);

    return(0);

}

void CreateProduct() {
    printf("\n==================== CADASTRO DE PRODUTOS ====================\n");

    for(int i = 0; i<3 ; i++){
        do {
            getchar();
            printf("\nDigite o produto %d: ", i+1);
            gets(produto[i]);
            if (produto[i][0] == '*'){
                printf("\nNome do produto n�o pode come�ar com o caracter '*' - reservado pelo sistema!\n");
            }
        }while(produto[i][0] == '*');


        do{
            printf("Digite a quantidade do produto %d: ", i+1);
            scanf("%d", &quantidade[i]);

            if (quantidade[i] <= 0) {
                printf("Quantidade deve ser maior que zero!\n\n");
            }

        }while(quantidade[i] <= 0);

    }

    WriteFile();

}

void FindAllProducts() {
    int cont = 0;
    int status = ReadFile();

    if (status == 0) {

        printf("\n============= LISTA DE PRODUTOS SALVOS NO ARQUIVO =============\n\n");

        for (int i = 0; i < 3; i++){
            if(produto[i][0] != '*'){
                printf("Produto %d: %s\n", i+1, produto[i]);
                printf("Quantidade do Produto %d: %d\n\n", i+1, quantidade[i]);
            }
            else{
                cont++;
            }
        }
        if (cont == 3) {
            printf("N�o h� produtos para exibir, cadastre novos produtos.\n");
        }

    }
    else {
        printf("\nProdutos n�o foram cadastrados. Entre com os dados antes de consultar.\n");
    }

    fclose(arquivo);
}

int FindByName() {

    int status = ReadFile();

    if (status == 0) {

        int i=0, j=0, cont=0;
        char search_produto[30];

        printf("\n=========== PESQUISA DE PRODUTOS POR NOME COMPLETO ===========\n\n");
        printf("Digite o nome do produto que deseja pesquisar: ");
        getchar();
        gets(search_produto);

        for (i = 0; i < 3; i++){

            for (j = 0; search_produto[j] != '\0'; j++){
                if(search_produto[j] != produto[i][j]){
                    break;
                }
            }

            if(search_produto[j] == '\0' && produto[i][j] == '\0' && produto[i][0] != '*'){
                printf("\nNome: %s\nQuantidade: %d\n", produto[i], quantidade[i]);
                cont++;
                return i;
            }

        }
        if(cont == 0){
            printf("\nNenhum produto com o nome digitado foi encontrado!\n");
            return -1;
        }
    }
    else {
        printf("\nProdutos n�o foram cadastrados. Entre com os dados antes de consultar.\n");
    }

    fclose(arquivo);

}

void FindByFirstLetter() {
    int status = ReadFile();

    if (status == 0) {

        int i=0, cont=0;
        char search_letra;

        printf("\n=========== PESQUISA DE PRODUTOS PELA PRIMEIRA LETRA ==========\n\n");
        do{
            printf("Digite a primeira letra do produto que deseja pesquisar: ");
            getchar();
            search_letra = getchar();
            if (search_letra == '*')
                printf("\nNome do produto n�o pode come�ar com o caracter '*' - reservado pelo sistema!\n\n");
        }while(search_letra == '*');

        for (i = 0; i < 3; i++) {
            if(search_letra == produto[i][0] && produto[i][0] != '*') {
                printf("\nNome: %s\nQuantidade: %d\n", produto[i], quantidade[i]);
                cont++;
            }
        }
        if(cont == 0) {
            printf("\nNenhum produto com a letra digitada foi encontrado!\n\n");
        }
    }
    else {
        printf("\nProdutos n�o foram cadastrados. Entre com os dados antes de consultar.\n");
    }

    fclose(arquivo);

}

void UpdateProduct() {
    int getid = FindByName();
    int getposicao;

    if(getid != -1) {
        printf("\nO registro %d ser� alterado...\n",getid+1);

        arquivo = fopen("c05","r+");

        getposicao = sizeof(produto[0]) * getid;
        fseek(arquivo, getposicao, 0);
        fread(&produto, sizeof(produto),1,arquivo);

        getposicao = sizeof(produto[0])*3 + sizeof(quantidade[0])* getid;
        fseek(arquivo, getposicao, 0);
        fread(&quantidade, sizeof(quantidade),1,arquivo);

        printf("\nDigite novo produto: ");
        scanf("%s",&produto);

        printf("Digite nova quantidade: ");
        scanf("%d",&quantidade);

        getposicao = sizeof(produto[0]) * getid;
        fseek(arquivo, getposicao, 0);
        fwrite(produto, sizeof(produto),1,arquivo);

        getposicao = sizeof(produto[0])*3 + sizeof(quantidade[0])* getid;
        fseek(arquivo, getposicao, 0);
        fwrite(quantidade, sizeof(quantidade),1,arquivo);

        fclose(arquivo);

        printf("Registro alterado com sucesso!\n");

    }
    else{
        printf("Registro n�o encontrado, n�o � poss�vel executar altera��o\n");
    }


}

void DeleteProduct() {
    int getid = FindByName();
    int getposicao;

    if(getid != -1) {
        printf("\nO registro %d ser� exclu�do...\n",getid+1);

        arquivo = fopen("c05","r+");

        getposicao = sizeof(produto[0]) * getid;
        fseek(arquivo, getposicao, 0);
        fread(&produto, sizeof(produto),1,arquivo);

        getposicao = sizeof(produto[0])*3 + sizeof(quantidade[0])* getid;
        fseek(arquivo, getposicao, 0);
        fread(&quantidade, sizeof(quantidade),1,arquivo);

        produto[0][0] = '*';

        getposicao = sizeof(produto[0]) * getid;
        fseek(arquivo, getposicao, 0);
        fwrite(produto, sizeof(produto),1,arquivo);

        fclose(arquivo);

        printf("Registro exclu�do com sucesso!\n");

    }
    else{
        printf("Registro n�o encontrado, n�o � poss�vel executar exclus�o\n");
    }
}


