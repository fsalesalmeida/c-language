#define ex5
#include "stdio.h"

/*****************************************************************************

			EXERCICIOS

*****************************************************************************
OBS.: Todos os programa devem ser finalizados pelo usuario.

1 - Faça um programa receba dois números inteiros e execute as seguintes funções:
    - Verificar se o número digitado é positivo ou negativo. Sendo que o valor de
      retorno será 1 se positivo, 0 se negativo ou -1 se for igual a 0.
    - Se os 2 números são positivos, retorne a soma dos N números existentes entre
      eles.
    - Se os 2 números são negativos, retorne a multiplicação dos N números existente
      entre eles.
*/

#ifdef ex01 // OK!!!

int verifica(int x, int y);
int retornar_soma(int x, int y);
int retornar_multiplica(int x, int y);

int retornar_multiplica(int x, int y){
int menor, maior, i, multiplica=1;
    if(x < y){
    menor = x;
    maior = y;
    }
    else{
    menor = y;
    maior = x;
    }

    x = menor;
    y = maior;
    i = x;

    while(i >= x && i <= y){

        multiplica = multiplica * i;
        i++;
    }
    return multiplica;

}

int retornar_soma(int x, int y){
    int menor, maior, i, soma=0;
    if(x < y){
    menor = x;
    maior = y;
    }
    else{
    menor = y;
    maior = x;
    }

    x = menor;
    y = maior;
    i = x;

    while(i >= x && i <= y){

        soma = soma + i;
        i++;
    }
    return soma;

}

int verifica(int x, int y){
    int res= 0;
    if(x>0 && y>0){
        res = 1;
    }else if (x<0 && y<0){
        res = 0;
    }else
    res = -1;

    return res;
}

 int main(){
    int a, b, res, exit;

    do{
    printf("Digite dois numeros:\n");
    scanf("%d", &a);
    scanf("%d", &b);


    res = verifica(a, b);
    if(res == 1){
        res = retornar_soma(a, b);
        printf("A soma entre os intervalos entre %d e %d eh...%d", a, b, res);
    }else if (res == 0){
        res = retornar_multiplica(a,b);
        printf("A multiplicacao entre os intervalos entre %d e %d eh...%d", a, b, res);
    }
    printf("\nDeseja continuar? 1 = [SIM] || Qualquer tecla = [NAO]\n--> ");
        scanf("%d",&exit);
        if(exit != 1){
            break;
            return 0;
        }
    }while(1==1);

}
#endif // ex01


/**
2 - Escreva um programa que receba uma letra via teclado. Escreva uma funcao que
    pesquise esta letra dentro do vetor abaixo. Imprima o resultado da pesquisa
    no video na funcao main(). Passe como informacao para a funcao a letra
    digitada.(utilize o comando return). O vetor deve ser uma variavel global.

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y

*/

#ifdef ex02 // OK!

int find_index(int a[], int num_elements, char valor);

void main(void)
{
    int exit;
do{
   int a[13] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};
   int index;
   char valor;

   printf("\nDigite uma letra:");
   scanf("%c", &valor);

   index = find_index(a, 13, valor);
   if (index != valor){
	 printf("A letra %c nao foi encontrada.\n", valor);
   }
   else
	 printf("A letra %c foi encontrada em %d\n", valor, index);

    printf("\nDeseja continuar? 1 = [SIM] || 2 = [NAO]\n--> ");
    scanf("%d",&exit);
        if(exit == 2){
        printf("Programa encerrado!");
          break;
          return 0;
        }
    }while(exit==1);
}

int find_index(int a[], int num_elements, char valor)
{
   int i;
   for (i=0; i<num_elements; i++)
   {
	 if (a[i] == valor)
	 {
	    return(valor);
	 }
   }
   return(-1);
}

#endif // ex02

/* 3 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
    uma funcao para cada operacoes aritmeticas e passe como parametro os 2
    valores recebidos na funcao main(). Retorne os resultados usando o comando
    return e imprima-os no video na funcao main().

*/

#ifdef ex03 // OK!

//declaração
int soma(int x, int y);
int subt(int x, int y);
int multi(int x, int y);
float divis(int x, int y);

main() {
    int num1, num2, exit;
    do{
        printf("Digite um numero: ");
        scanf("%d",&num1);
        printf("\nDigite outro numero: ");
        scanf("%d",&num2);
        printf("\nSoma: %d\nSubtracao: %d\nMultiplicacao: %d\nDivisao: %.2f", soma(num1,num2), subt(num1,num2), multi(num1, num2), divis(num1,num2));

        printf("\nDeseja continuar? 1 = [SIM] || Qualquer tecla = [NAO]\n--> ");
        scanf("%d",&exit);
        if(exit != 1){
            break;
        }
    }while(1==1);
}
//Funções
int soma(int x, int y) {
    return x + y;
}

int subt(int x, int y) {
    return x - y;
}

int multi(int x, int y) {
    return x * y;
}

float divis(int x, int y) {
    return (float) x / (float) y;
}

#endif // ex03
/*

4 - Aproveitando o programa anterior inclua a selecao das operacoes aritmeticas
    para transforma-lo em uma calculadora. (utilize o comando switch). As operacoes
    aritmeticas devem estar em funcoes. O resultado deve ser mostrado na
    funcao main()

*/

#ifdef ex04 // OK!!

int soma(int x[], int n);
int subtrai(int x[], int n);
int multiplica(int x[], int n);
double divide(int x[], int n);


main()
{
int c,i=0, n=0,a, opc;
int exit;
    do{
        printf("Digite a quantidade de valores a ser calculado\n");
        scanf("%d", &n);

        int a[n];

        printf("\nDigite os valores para calculo\n");
        for(i=0; i<n; i++)
        scanf("%d", &a[i]);

        printf("\nDigite o valor 1 para soma\n");
        printf("\nDigite o valor 2 para subtracao\n");
        printf("\nDigite o valor 3 para multiplicacao\n");
        printf("\nDigite o valor 4 para divisao\n");
        scanf("%d", &opc);

        printf("\n=======chamando as funcoes===== \n");

        switch(opc){

        case 1:{

        c = soma(a,n);

        printf("\nSoma dos termos = %d\n", c);
            break;
        };

            case 2:{

            c = subtrai(a, n);

            printf("\nSubtracao dos termos = %d\n", c);
            break;
            };

        case 3:{

        c = multiplica(a, n);

        printf("\nMultiplicacao dos termos = %d\n", c);
            break;
        };
        case 4:{

        c = divide(a,n);
        printf("\nDivisao dos termos = %.1lf", c);
            break;
        };
        default: printf("Valor invalido");
        }


        printf("\nDeseja continuar? 1 = [SIM] || Qualquer tecla = [NAO]\n--> ");
        scanf("%d",&exit);
        if(exit != 1){
            break;
        }
    }while(1==1);
}
int soma(int x[], int n)
{
    int res = 0, i;
    for (i = 0; i < n; i++)
        res = res+x[i];
            return(res);
}

int subtrai(int x[], int n)
{
 int res = x[0], i;

    for (i = 0; i < n; i++)
        printf("%d\n", x[i]);
        res = x[i] - res;
            return(res);
}

int multiplica(int x[], int n)
{
int res = 0, i;
    for (i = 0; i < n; i++)
        res = soma(x,n)*soma(x,n);
            return(res);
}

double divide(int x[], int n)
{
double res = 0, i;
    for (i = 0; i < n; i++)
        res = (subtrai(x,n))/(soma(x,n));
            return(res);
}

#endif // ex04


/*

5 - Escreva um programa que receba um numero N. Escreva uma função que
    retorne a soma dos algarismos de N!. O resultado deve ser mostrado na funcao
    main().
    Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos ´e 2 + 4 = 6.

*/
#ifdef ex05

int n = 0, res=0;
int somaDigitos (int digitos);
int fatorial(int x);

int fatorial(int x){

int CONT = 1;
int FAT = 1;
do
{
    FAT*= CONT;
    //FAT = FAT * CONT
    CONT+= 1;
    //CONT+= 1
    // CONT = CONT + 1
    }
while(CONT <= x);
printf("Resultado: %d", FAT);
return FAT;
}


int somaDigitos (int digitos)
{
    int resto, valor, i, resultado, soma = 0;

    resultado = digitos;

    while (resultado != 0)
    {
          soma += resultado % 10;
          resultado = resultado / 10;
    }

    return soma;
}

int main(){
    int res1, exit;

    do{
    printf("Digite um numero para calculo de algarismos\n");
    scanf("%d", &n);
    res = fatorial(n);
    res1 = somaDigitos(res);

    printf(" O fatorial de %d eh %d e a soma de seus algarismos eh %d", n, res, res1);

    printf("\nDeseja continuar? 1 = [SIM] || Qualquer tecla = [NAO]\n--> ");
    scanf("%d",&exit);
    if(exit != 1){
            break;
        }
    }while(1==1);

    return 0;
}

#endif // ex05



