#define ex1
#include "stdio.h"
/*
1 - Faca um programa que leia uma palavra (maximo de 20 letras) em uma funcao
    e some 1 no valor ASCII de cada caractere da palavra em outra funcao. Na sua
    funcao main() imprima a string resultante. (variavel global)
*/
//CRIAR FUNÇÃO, e MUDAR LIMITE PARA 20
#ifdef ex1
int main(void){
    char frase[50];
    int i;

    printf("Entre com o texto: ");
    gets(frase);

    for(i = 0; frase[i] != '\0'; i++)
        if(frase[i] >= 65 && frase[i] <= 90 ||frase[i] >= 97 && frase[i] <= 122)
            frase[i] += 1;

    printf("\nNovo texto: %s\n", frase);

    return 0;
}
#endif // ex1

/*

2 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
    e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4
                          nome3
*/
#ifdef ex2
char c[5][7];

main()
{

int x, i;

printf("digite 5 nomes: \n");

for(i=0; i<5; i++)

scanf("%s", &c[i]);


printf("\n as strings digitada foram: \n");

printf("        10        20        30        40        50\n");
printf("12345678901234567890123456789012345678901234567890\n");
printf("%-10s                                   %-10s\n", &c[0], &c[1]);
printf("          %-10s               %-10s\n", &c[2], &c[3]);
printf("                     %-10s ", &c[4]);

}
#endif // ex2

/*

3 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras maiusculas.
*/
#ifdef ex3
 int main(void){

    char frase[40];
    int i;

    printf("Entre com o texto: ");
    gets(frase);

    for(i = 0; frase[i] != '\0'; i++)
        if(frase[i] >= 97 && frase[i] <= 122)
            frase[i] -= 32;

    printf("\nNovo texto: %s\n", frase);

    return 0;
}
#endif // ex3

/*
4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras minusculas.
*/

#ifdef ex4
    int main(void){
    char frase[40];
    int i;

    printf("Entre com o texto: ");
    gets(frase);

    for(i = 0; frase[i] != '\0'; i++)
        if(frase[i] >= 65 && frase[i] <= 90)
            frase[i] += 32;

    printf("\nNovo texto: %s\n", frase);

    return 0;
}
#endif // ex4

/*
5 - Receba 2 string de ate 10 caracteres via teclado na funcao main() e noutra
    funcao compare-as mostrando como resultado se são IGUAIS ou DIFERENTES na funcao
    main().
*/
//CRIAR FUNCAO
#ifdef ex5
char c[10];
char a[10];

main()
{

int x, i;


printf("digite o primeiro nome: \n");
gets(c);

printf("\ndigite o segundo nome: \n");
gets(a);

for(i=0; i<c[10]; i++){
        c[i] = c[10];
    for(x=0; x<a[10]; x++){
            a[x] = a[10];
    }
}if(c[i]==a[x]){
    printf("As strings %s e %s sao iguais", &c[i], &a[x]);
}else
    printf("As strings %s e %s sao diferentes", &c[i], &a[x]);

}
#endif // ex5
