#define ex1
#include "stdio.h"
/*
1 - Escreva um programa que receba um vetor e o decomponha em dois outros vetores.
    Um contendo as componentes de ordem ímpar e o outro contendo as componentes
    de ordem par. Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7},
    o programa deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3}.
*/


#ifdef ex1
int a[10], i, j[10], s[10];
int x, y;

int main(){

    printf("COLOQUE OS 10 ELEMENTOS DO VETOR:\n");

    for(i=0; i<9; i++){
        scanf("%d", &a[i]);

        if(a[i]% 2 != 0){
        j[i] = a[i];

        }
        else{
        s[i] = a[i];
        }

    }

        for(i=0; i<9; i++)
            printf("Vetor ordem impar %d\n ", j[i]);
        for(i=0; i<9; i++)
            printf("Vetor ordem par %d \n", s[i]);

            return 0;
}
#endif // ex1

/*
2 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
    3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
*/
#ifdef ex2
int A[3];
float B[3];
long C[3];
double D[3];
unsigned E[3];

main(){
    printf("INSIRA NUMEROS NOS VETORES\n");
    printf("\nDIGITE 3 VALORES INTEIROS E APERTE ENTER\n");
    scanf("%d", &A[0]);
    scanf("%d", &A[1]);
    scanf("%d", &A[2]);
    printf("\nDIGITE 3 VALORES REAIS E APERTE ENTER\n");
    scanf("%f", &B[0]);
    scanf("%f", &B[1]);
    scanf("%f", &B[2]);
    printf("\nDIGITE 3 VALORES LONGOS E APERTE ENTER\n");
    scanf("%ld", &C[0]);
    scanf("%ld", &C[1]);
    scanf("%ld", &C[2]);
    printf("\nDIGITE 3 VALORES DOUBLE E APERTE ENTER\n");
    scanf("%lf", &D[0]);
    scanf("%lf", &D[1]);
    scanf("%lf", &D[2]);
    printf("\nDIGITE 3 VALORES SEM SINAL E APERTE ENTER\n");
    scanf("%u", &E[0]);
    scanf("%u", &E[1]);
    scanf("%u", &E[2]);

    printf("\n        10        20        30        40        50\n");
    printf("\n12345678901234567890123456789012345678901234567890\n");
    printf("  %-6d              %-11ld               %-5u\n", A[0], C[0], E[0]);
    printf("\n        %-8.1e             %-9.e\n", B[0], D[0]);
    printf("  %-6d              %-11ld               %-5u\n", A[1], C[1], E[1]);
    printf("\n        %-8.1e             %-9.e\n", B[1], D[1]);
    printf("  %-6d              %-11ld               %-5u\n", A[2], C[2], E[2]);
    printf("\n        %-8.1e             %-9.e\n", B[2], D[2]);

}
#endif // ex2

/*

3 - Receba via teclado dez valores inteiros e ordene por ordem crescente assim
    que sao digitados. Guarde-os em um vetor. Mostre ao final os valores ordenados.
*/

#ifdef ex3
int a[10], i, j[10], s[10];
int x, y;

int main(){

    printf("COLOQUE OS 10 ELEMENTOS DO VETOR:\n");

    for(i=0; i<9; i++)
        scanf("%d", &a[i]);

    for (i=0;i<10; i++)
    for(x=i+1;x<10;x++)
        if (a[i]>a[x]){
    {
            y=a[i];
            a[i]=a[x];
            a[x]=y;
                            }

        }
        printf("Vetor em ordem crescente: \n");
        for(i=0;i<10;i++)
        printf(" %d",a[i]);


            return 0;
    }
#endif // ex3

/*
4 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
    que recebe os dados via teclado para esses 2 vetores. Usando o operador
    subtracao "-", subtraia os elementos de mesmo indice dos 2 vetores
    e guarde o resultado num 3. vetor. Imprima na tela o indice, os valores e
    o resultado dos 6 elementos dos vetores.
*/
// ESTÁ COM MULTIPLICACAO, TEM QUE ALTERAR
#ifdef ex4
int tabelax [2] [3];
int tabelay [2] [3];
int resultado [2] [3];
int i, x;

main()
{

for (i=0; i<=2; i++){
    printf(" Insira linha 1 coluna %d da tabela x ->\t", i);
    scanf("%d",&tabelax[0] [i]);}

for (i=0; i<=2; i++){
        x=1;
    printf(" Insira linha 2 coluna %d da tabela x ->\t", i);
    scanf("%d",&tabelax[x] [i]);}

printf(" valor da linha 1 coluna 1-> %d\n",tabelax[0] [0]);
printf(" valor da linha 1 coluna 2-> %d\n",tabelax[0] [1]);
printf(" valor da linha 1 coluna 3-> %d\n",tabelax[0] [2]);

printf(" valor da linha 2 coluna 1-> %d\n",tabelax[1] [0]);
printf(" valor da linha 2 coluna 2-> %d\n",tabelax[1] [1]);
printf(" valor da linha 2 coluna 3-> %d\n",tabelax[1] [2]);

for (i=0; i<=2; i++){
    printf(" Insira linha 1 coluna %d da tabela y ->\t", i);
    scanf("%d",&tabelay[0] [i]);}

for (i=0; i<=2; i++){
        x=1;
    printf(" Insira linha 2 coluna %d da tabela y ->\t", i);
    scanf("%d",&tabelay[x] [i]);}

printf(" valor da linha 1 coluna 1-> %d\n",tabelay[0] [0]);
printf(" valor da linha 1 coluna 2-> %d\n",tabelay[0] [1]);
printf(" valor da linha 1 coluna 3-> %d\n",tabelay[0] [2]);

printf(" valor da linha 2 coluna 1-> %d\n",tabelay[1] [0]);
printf(" valor da linha 2 coluna 2-> %d\n",tabelay[1] [1]);
printf(" valor da linha 2 coluna 3-> %d\n",tabelay[1] [2]);

for(i=0; i<=2; i++){
        for(x=0; x<=1; x++){
        resultado[x][i] = tabelax[x][i];
        resultado[x][i] = resultado[x][i] * tabelay[x][i];
                                                            }

        }
        printf("%d\n", resultado[0][0]);
        printf("%d\n", resultado[0][1]);
        printf("%d\n", resultado[0][2]);
         printf("%d\n", resultado[1][0]);
        printf("%d\n", resultado[1][1]);
        printf("%d\n", resultado[1][2]);





}
#endif // ex4

/*
5 - Receba via teclado valores do tipo int para uma matriz 5 x 5. Receba via
    teclado um valor x. O programa dever fazer a busca desse valor x na matriz
    e, ao final escrever a localizacao (linha e coluna) ou uma mensagem de
    ”nao encontrado”.
*/

#ifdef ex5
int tabelax [5][5];
int i, x, y, z, num, notfound = 0;

int main()
{

for (i=0; i<=4; i++){
    printf(" Insira linha 1 coluna %d da tabela x ->\t", i);
    scanf("%d",&tabelax[0] [i]);}

for (i=0; i<=4; i++){
        x=1;
    printf(" Insira linha 2 coluna %d da tabela x ->\t", i);
    scanf("%d",&tabelax[x] [i]);}

for (i=0; i<=4; i++){
        x=2;
    printf(" Insira linha 3 coluna %d da tabela x ->\t", i);
    scanf("%d",&tabelax[x] [i]);}

for (i=0; i<=4; i++){
        x=3;
    printf(" Insira linha 4 coluna %d da tabela x ->\t", i);
    scanf("%d",&tabelax[x] [i]);}

for (i=0; i<=4; i++){
        x=3;
    printf(" Insira linha 5 coluna %d da tabela x ->\t", i);
    scanf("%d",&tabelax[x] [i]);}

    printf("\n ESCREVA UM NUMERO PARA PESQUISAR NO VETOR \n");
    scanf("%d", &num);

    for(y=0; y < 4; y++){
       for(z=0; z < 4; z++)
    if(tabelax[y][z] == num){
    printf("\n numero %d foi encontrado na posicao %d %d", num, tabelax[y][z] );
    notfound = 1;
    }
                    }

    if(notfound == 0)
    printf(" O valor nao existe no vetor.\n");



    return 0;
}

#endif // ex5
