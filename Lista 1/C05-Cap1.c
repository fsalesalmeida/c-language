#define ex5
#include "stdio.h"
/*****************************************************************************
			EXERCICIOS
******************************************************************************

1 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este
    multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
    teclado.
    Ex: menor multiplo de 13 maior que 100. Resultado: 104.
*/

#ifdef ex1
main()
{
    int a,b,c,cont=1;
    do
    {
        printf("Digite um numero inteiro positivo: ");
        scanf("%d",&a);
        if (a<=0)
            printf("O numero deve ser positivo\n\n");
    }while(a<=0);
    do
    {
        printf("Digite o limite minimo para calculo do menor multiplo: ");
        scanf("%d",&b);
        if (b<=a)
            printf("O limite deve ser maior que o numero digitado\n\n");
    }while(b<=a);
    do
    {
        c=a*cont;
        cont++;
    }
    while(c<b);
    printf("\nMenor multiplo de %d com limite %d: %d",a,b,c);

}

#endif // ex1


/*
2 - Escreva um programa que receba dados via teclado para variaveis do tipo short,
    long, int, float, double e um char e imprima-os no video no seguinte
    formato:

             10        20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
         short               long                int
                   float               double              char
*/

#ifdef ex2
main()
{
    short a;
    long b;
    int c;
    float d;
    double e;
    char f;
    printf("Digite um valor do tipo short: ");
    scanf("%hd",&a);
    printf("Digite um valor do tipo long: ");
    scanf("%ld",&b);
    printf("Digite um valor do tipo int: ");
    scanf("%ld",&c);
    printf("Digite um valor do tipo float: ");
    scanf("%e",&d);
    printf("Digite um valor do tipo double: ");
    scanf("%e",&e);
    printf("Digite um valor do tipo char: ");
    scanf("%c",&f);
    printf("        10        20        30        40        50        60\n");
    printf("12345678901234567890123456789012345678901234567890123456789012345\n");


}

#endif // ex2

/*

3 - Escreva um programa que receba via teclado um tempo em segundos e converta
    para horas, minutos e segundos.
    Ex.: recebe 3850 segundos que converte para 1h 4min 10s.
*/


main()
{
    int h=0,m=0,s=0,a;
    printf("Digite a qtde de segundos a serem convertidos: ");
    scanf("%d",&a);
    h=a/3600;
    if ((a%3600)!=0)
    {
        m=((a%3600)/60);
        if ((m%60)!=0)
            s=(a%60);
    }
    printf("%.0d hora\n",h);
    printf("%.0d\ minuto\n",m);
    printf("%.0d\ segundo\n",s);
}


/*
4 - Escreva um programa que permute o conteúdo de duas variáveis sem utilizar uma
    variável auxiliar.
*/

#ifdef ex4
main()
{
    int a;
    int b;
    printf("Digite um numero inteiro: ");
    scanf("%d",&a);
    printf("Digite um numero inteiro: ");
    scanf("%d",&b);
    printf("Conteudo da variavel a: %d",a);
    printf("\nConteudo da variavel b: %d",b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("\n\nPermuta das variaveis: ");
    printf("\nConteudo da variavel a: %d",a);
    printf("\nConteudo da variavel b: %d",b);
}

#endif // ex4

/*
5 - Escreva um programa que lê um valor em reais e calcula qual o menor número
    possível de notas de $100, $50, $20, $10, $5, $2 e $1 em que o valor lido pode
    ser decomposto. Escrever o valor lido e a relação de notas necessárias.
*/

/*
#ifdef ex5
main()
{
    int valor;
    do
    {
        printf("Digite um valor positivo: ");
        scanf("%d",&valor);
        if (valor<=0)
            printf("O numero deve ser positivo e maior que 0\n\n");
    }while(valor<=0);

    int N100,N50,N20,N10,N5,N2,N1;

	N100=valor/100;
	valor=valor-N100*100;

	N50=valor/50;
	valor=valor-N50*50;

	N20= valor/20;
	valor=valor-N20*20;

	N10=valor/10;
	valor=valor-N10*10;

	N5=valor/5;
	valor=valor-N5*5;

	N2=valor/2;
	valor=valor-N2*2;

	N1=valor;

	printf("\n\nO numero de notas de R$100 : %d", (N100));
	printf("\nO numero de notas de R$50 : %d", (N50));
	printf("\nO numero de notas de R$20 : %d", (N20));
	printf("\nO numero de notas de R$10 : %d", (N10));
	printf("\nO numero de notas de R$5 : %d", (N5));
	printf("\nO numero de notas de R$2 : %d", (N2));
	printf("\nO numero de notas de R$1 : %d", (N1));
}

#endif // ex5
*/
