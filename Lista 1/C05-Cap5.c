#define ex5
#include "stdio.h"
/*
OBS.: Todos os programa devem ser finalizados pelo usuario.

1 - Faca um programa que leia uma palavra (maximo de 20 letras) em uma funcao
    e some 1 no valor ASCII de cada caractere da palavra em outra funcao. Na sua
    funcao main() imprima a string resultante. (variavel global)
*/


#ifdef ex1 // OK!!
char frase[20];

main(){
    int exit;

    do{
        lerFrase();
        printf("\nNovo texto: %s\n", frase);
        do{
            printf("\nDeseja continuar? 1 = [SIM] || 2 = [NAO]\n--> ");
            scanf("%d",&exit);
        }while(exit < 1 || exit > 2);
        if(exit != 1){
            break;
        }
    }while(1==1);
}

int lerFrase(){
    printf("Entre com o texto (Maximo 20 letras): ");
    scanf("%s",&frase);
    somarCaracter();
}

int somarCaracter(){
    int i;
    for(i = 0; frase[i] != '\0'; i++){
        if(frase[i] >= 65 && frase[i] <= 90 ||frase[i] >= 97 && frase[i] <= 122)
            frase[i] += 1;
    }
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

#ifdef ex2 // OK!!

char c[5][7];

main()
{

int x, i,exit;

do{
    printf("digite 5 nomes: \n");

    for(i=0; i<5; i++)

    scanf("%s", &c[i]);


    printf("\n as strings digitada foram: \n");

    printf("        10        20        30        40        50\n");
    printf("12345678901234567890123456789012345678901234567890\n");
    printf("%-10s                                   %-10s\n", &c[0], &c[1]);
    printf("          %-10s               %-10s\n", &c[2], &c[3]);
    printf("                     %-10s ", &c[4]);

    do{
        printf("\nDeseja continuar? 1 = [SIM] || 2 = [NAO]\n--> ");
        scanf("%d",&exit);
        }while(exit < 1 || exit > 2);
        if(exit != 1){
            break;
        }
    }while(1==1);
}

#endif // ex2

/*
3 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras maiusculas.
*/

#ifdef ex3 // OK!!
char frase[10];
int i;

main(){

    int exit;

    do{
        lerPalavra();
        do{
            printf("\nDeseja continuar? 1 = [SIM] || 2 = [NAO]\n--> ");
            scanf("%d",&exit);
        }while(exit < 1 || exit > 2);
        if(exit != 1){
            break;
        }
    }while(1==1);
}

lerPalavra(){

    printf("Entre com o texto: ");
    scanf("%s",&frase);
    for(i = 0; frase[i] != '\0'; i++)
        if(frase[i] >= 97 && frase[i] <= 122)
            frase[i] -= 32;
    printf("\nNovo texto: %s\n", frase);

}

#endif // ex3

/*
4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras minusculas.
*/

#ifdef ex4 // OK!!

main(){
    char frase[10];
    int i, exit;

    do{
        printf("Entre com o texto: ");
        scanf("%s",&frase);

        for(i = 0; frase[i] != '\0'; i++)
            if(frase[i] >= 65 && frase[i] <= 90)
                frase[i] += 32;

        printf("\nNovo texto: %s\n", frase);
        do{
            printf("\nDeseja continuar? 1 = [SIM] || 2 = [NAO]\n--> ");
            scanf("%d",&exit);
        }while(exit < 1 || exit > 2);
        if(exit != 1){
            break;
        }
    }while(1==1);
}
#endif // ex4

/*
5 - Receba 2 string de ate 10 caracteres via teclado na funcao main() e noutra
    funcao compare-as mostrando como resultado se são IGUAIS ou DIFERENTES na funcao
    main().
*/


#ifdef ex5 // OK!!

char c[10];
char a[10];
int x, i;

main(){
    int exit;

    do{

        printf("digite o primeiro nome: \n");
        scanf("%s",&c);

        printf("\ndigite o segundo nome: \n");
        scanf("%s",&a);

        comparar();

        if(c[i]==a[x]){
        printf("As strings %s e %s sao iguais", &c[i], &a[x]);
        }
        else
            printf("As strings %s e %s sao diferentes", &c[i], &a[x]);

        do{
                printf("\nDeseja continuar? 1 = [SIM] || 2 = [NAO]\n--> ");
                scanf("%d",&exit);
        }while(exit < 1 || exit > 2);
        if(exit != 1){
            break;
        }

    }while(1==1);
}

int comparar(){

    for(i=0; i<c[10]; i++){
        c[i] = c[10];
    for(x=0; x<a[10]; x++){
            a[x] = a[10];
        }
    }
}

#endif // ex5

