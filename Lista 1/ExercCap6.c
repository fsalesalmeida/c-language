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
//CRIAR FUNCAO
#ifdef ex1
int main(){
float a;
int b;
printf("\n1 - transforma graus Celsius em Fahrenheit e Kelvin\n2 - transforma graus Fahrenheit e Celsius e Kelvin\n3 - transforma graus Kelvin e Celsius e Fahrenheit\n");
scanf("%d",&b);
switch (b){
case 1 :
    printf("\nDigite o temperatura Celsius: ");
    scanf("%f",&a);
    printf("\n%.1f F\t%.2f K",(a*9/5)+32,a+273.15);
    break;
case 2 :
    printf("\nDigite o temperatura Fahrenheit: ");
    scanf("%f",&a);
    printf("\n%.1f C\t%.2f K",((a-32)*(5/9)),((a-32)*(5/9))+273.15);
    break;
case 3 :
    printf("\nDigite a temperatura Kelvin: ");
    scanf("%f",&a);
    printf("\n%.1f C\t%.2f F",a-273.15, (a-273,15)*9/5+32);
}
}
#endif // ex1
/*
2 - Escreva um programa que receba via teclado 2 numeros inteiros e
    imprima-os no video com o resultado das 4 operacoes aritmeticas.
*/
#ifdef ex2
int main()
{
int a,b,c;
do{
    printf("\nDigite 2 numeros inteiros: ");
    scanf("%d %d",&a,&b);
    printf("\nSoma: %d",sizeof(a+b));
    printf("\nSubitracao: %d",sizeof(a-b));
    printf("\nMultiplicacao: %d",sizeof(a*b));
    printf("\nDivisao: %d",sizeof(a/b));
    printf("\nQuer continuar no programa: \n\t1 para continuar! \t2 para sair!");
    scanf("%d",&c);
}while(c==1);
}
#endif // ex2
/*
3 - Reescreva o exercicio anterior utilizando operadores de atribuicao
    composta.
*/
#ifdef ex3
float main()
{
float a,b;
int c;
do{
    printf("\nDigite 2 numeros Reais: ");
    scanf("%f %f",&a,&b);
    printf("\nSoma: %.2f",sizeof(a+b));
    printf("\nSubitracao: %.2f",sizeof(a-b));
    printf("\nMultiplicacao: %.2f",sizeof(a*b));
    printf("\nDivisao: %.2f",sizeof(a/b));
    printf("\nQuer continuar no programa: \n\t1 para continuar! \t2 para sair!");
    scanf("%d",&c);
}while(c==1);
}
#endif // ex3
/*
4 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
    as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
    video no formato decimal e hexadecimal.
*/
#ifdef ex4
main()
{
int a,b;
printf("\nDigite 2 numeros: ");
scanf("%d %d",&a,&b);

printf(" Operadores bit-a-bit\n");
printf(" AND   a & b --> %3d  0x%x\n",a & b,a & b);
printf(" OU   a | b --> %3d  0x%x\n",a | b,a | b);
printf(" OU EXCLUSIVO a ^ b --> %3d  0x%x\n",a ^ b,a ^ b);
}
#endif // ex4
/*
5 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
    dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
    data (dia, mes e ano) atual.
*/
#ifdef ex5
int main(){
int a,b,c,d,e,f,ano,dia,mes;
do{
do{
printf("\nDigite o ano que vc nasceu: ");
scanf("%d",&a);}while(a<=0);
do{
printf("\nDigite o mes que vc nasceu: ");
scanf("%d",&b);}while(b<=0 || b>12);
do{
printf("\nDigite o dia que vc nasceu: ");
scanf("%d",&c);}while(c<=0||c>31);
do{
printf("\nDigite o ano atual: ");
scanf("%d",&d);}while(d<=0);
do{
printf("\nDigite o mes atual: ");
scanf("%d",&e);}while(e<=0 || e>12);
do{
printf("\nDigite o dia atual: ");
scanf("%d",&f);}while(f<=0 || f>31);
}while(d<a);
ano=d-a;
mes=e-b;
if (mes<0)
    ano-=1;
dia=f-c;
if (dia<0){
    dia+=31;
    mes-=1;}
    printf("\nSua idade dia %d Mes %d Ano %d",dia,mes,ano);
}
#endif // ex5
