#define ex1
#include "stdio.h"

/*
1 - Escreva um programa que tenha o menu abaixo.
       1 - transforma graus Celsius em Fahrenheit e Kelvin
       2 - transforma graus Fahrenheit e Celsius e Kelvin
       3 - transforma graus Kelvin e Celsius e Fahrenheit
    Cada opcao de menu deve chamar uma funcao que retorna o resultado da
    conversao. O resultado deve ser mostrado na funcao main().
*/

#ifdef ex1 // OK!!

float a;

int main(){
    int b;
    int exit;

    do{
        printf("\n1 - transforma graus Celsius em Fahrenheit e Kelvin\n2 - transforma graus Fahrenheit e Celsius e Kelvin\n3 - transforma graus Kelvin e Celsius e Fahrenheit\n");
        scanf("%d",&b);
        switch (b){
        case 1 :
            transformaCelsius();
            break;
        case 2 :
            transformaFahrenheit();
            break;
        case 3 :
            transformaKelvin();
            break;
        }
        printf("\nQuer continuar no programa? \n\tDigite 1 para continuar! \n\tDigite 2 para sair!\n");
        scanf("%d",&exit);
        }while(exit==1);
    return 0;
}

int transformaCelsius(){
    printf("\nDigite o temperatura Celsius: ");
            scanf("%f",&a);
            printf("\n%.1f F\t%.2f K",(a*9/5)+32,a+273.15);
}

int transformaFahrenheit(){
    printf("\nDigite o temperatura Fahrenheit: ");
            scanf("%f",&a);
            printf("\n%.1f C\t%.2f K",((a-32)*(5/9)),((a-32)*(5/9))+273.15);
}

int transformaKelvin(){
    printf("\nDigite a temperatura Kelvin: ");
            scanf("%f",&a);
            printf("\n%.1f C\t%.2f F",a-273.15, (a-273,15)*9/5+32);
}
#endif // ex1

/*
2 - Escreva um programa que receba via teclado 2 numeros inteiros e
    imprima-os no video com o resultado das 4 operacoes aritmeticas.
*/
#ifdef ex2 // OK!!

int main()
{
    int a,b,exit;
        do{
            printf("Digite o 1° numero inteiro: ");
            scanf("%d",&a);
            printf("Digite o 2° numero inteiro: ");
            scanf("%d",&b);
            printf("\nSoma: %d",sizeof(a+b));
            printf("\nSubitracao: %d",sizeof(a-b));
            printf("\nMultiplicacao: %d",sizeof(a*b));
            printf("\nDivisao: %d",sizeof(a/b));
            printf("\nQuer continuar no programa? \n\tDigite 1 para continuar! \n\tDigite 2 para sair!\n");
            scanf("%d",&exit);
        }while(exit==1);
}

#endif // ex2
/*
3 - Reescreva o exercicio anterior utilizando operadores de atribuicao
    composta.
*/
#ifdef ex3 // OK!!

float main()
{
float a,b;
int exit;
do{
    printf("Digite o 1° numero real: ");
    scanf("%f",&a);
    printf("Digite o 2° numero real: ");
    scanf("%f",&b);
    printf("\nSoma: %.2f",sizeof(a+b));
    printf("\nSubitracao: %.2f",sizeof(a-b));
    printf("\nMultiplicacao: %.2f",sizeof(a*b));
    printf("\nDivisao: %.2f",sizeof(a/b));
    printf("\nQuer continuar no programa? \n\tDigite 1 para continuar! \n\tDigite 2 para sair!\n");
    scanf("%d",&exit);
}while(exit==1);
}

#endif // ex3
/*
4 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
    as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
    video no formato decimal e hexadecimal.
*/

#ifdef ex4 // OK!!
main()
{
int a,b;
int exit;

    do{
    printf("Digite o 1° numero: ");
    scanf("%d",&a);
    printf("Digite o 2° numero: ");
    scanf("%d",&b);

    printf(" \nOperadores bit-a-bit\n");
    printf(" AND  a & b --> %3d  0x%x\n",a & b,a & b);
    printf(" OU   a | b --> %3d  0x%x\n",a | b,a | b);
    printf(" OU   EXCLUSIVO a ^ b --> %3d  0x%x\n",a ^ b,a ^ b);
    printf("\nQuer continuar no programa? \n\tDigite 1 para continuar! \n\tDigite 2 para sair!\n");
    scanf("%d",&exit);
    }while(exit==1);
}

#endif // ex4
/*
5 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
    dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
    data (dia, mes e ano) atual.
*/

#ifdef ex5 // OK!!!

int main(){
    int a=0,b=0,c=0,d=0,e=0,f=0,ano=0,dia=0,mes=0;
    int exit;

    do{
        do{
            do{
            printf("\nDigite o ano que vc nasceu: ");
            scanf("%d",&a);
            }while(a<=0 || a>2021);
        do{
            printf("\nDigite o mes que vc nasceu no formato numero: ");
            scanf("%d",&b);
            }while(b<=0 || b>12);
        do{
            printf("\nDigite o dia que vc nasceu: ");
            scanf("%d",&c);
            }while(c<=0||c>31);
        do{
            printf("\nDigite o ano atual: ");
            scanf("%d",&d);
            }while(d<=0 || d>2021);
        do{
            printf("\nDigite o mes atual no formato numero: ");
            scanf("%d",&e);
            }while(e<=0 || e>12);
        do{
            printf("\nDigite o dia atual: ");
            scanf("%d",&f);
            }while(f<=0 || f>31);
        }while(d<a);
        ano=d-a;
        mes=e-b;
        if (mes<0)
            ano-=1;
            dia=f-c;
        if (dia<0){
            dia+=31;
            mes-=1;}
            printf("\nSua idade: %d Dias %d Meses %d Anos",dia,mes,ano);

    printf("\n\n      Quer continuar no programa? \n\tDigite 1 para continuar! \n\tDigite 2 para sair!\n");
    scanf("%d",&exit);
    }while(exit==1);
}

#endif // ex5
