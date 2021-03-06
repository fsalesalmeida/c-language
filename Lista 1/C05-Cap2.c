#define ex2
#include "stdio.h"
/*****************************************************************************
			EXERCICIOS
******************************************************************************
OBS.: Fa�a um loop infinito e defina uma saida em todos os exerc�cios.

1 - Um posto est� vendendo combust�veis com a seguinte tabela de descontos:
     �lcool
         at� 20 litros, desconto de 3% por litro
         acima de 20 litros, desconto de 5% por litro
     Gasolina
          at� 20 litros, desconto de 4% por litro
          acima de 20 litros, desconto de 6% por litro
     Escreva um programa que leia o n�mero de litros vendidos e o tipo de
     combust�vel (codificado da seguinte forma: A-�lcool, G-gasolina). Calcule e
     imprima o valor a ser pago pelo cliente sabendo-se que o pre�o do litro da
     gasolina � R$ 4,88 e o pre�o do litro do �lcool � R$ 3,18. */

#ifdef ex1

main()
{
    float L,G=3.88,A=3.18,vt;
    char opcao;
    int exit;

    do{
        opcao: ' ';
        printf("Digite G para Gasolina ou A para Alcool: \n");
        do{
            printf("\nTipo de Combustivel: ");
            scanf(" %c",&opcao);
            getchar();

            if((opcao!='g')&&(opcao!='a')&&(opcao!='G')&&(opcao!='A'))
            {
                printf("\nCaracter Invalido, escolha G ou A!!!");
            }

        }while((opcao!='g')&&(opcao!='a')&&(opcao!='G')&&(opcao!='A'));

        if(opcao=='g'||opcao=='G')
        {
            do{
                printf("\nQtde de Litros: ");
                scanf("%f",&L);
                if(L<=0)
                {
                    printf("Deve ser maior que zero!!\n");
                }
            }while(L<=0);

            if(L<=20)
            {
               vt = (L * 4.88) * 0.96;
                    printf("%.2f Litro de gasolina com 4%% de desconto = %.2f",L,vt);
            }
            else if(L>20)
            {
               vt = (L * 4.88) * 0.94;
                printf("%.2f litros de gasolina com 6%% de desconto = %.2f",L,vt);
            }
        }
        else if (opcao=='a'||opcao=='A')
        {
            do{
                printf("\nQtde de Litros:: ");
                scanf("%f",&L);
                if(L<=0)
                {
                    printf("Deve ser maior que zero!!\n");
                }
            }while(L<=0);

            if(L<=20)
            {
                vt = (L * 3.18) * 0.97;
                printf("%.2f litro de alcool com 4%% de desconto = %.2f",L,vt);
                }
             else if(L>20)
            {
               vt = (L * 3.18) * 0.95;
                printf("%.2f litros de alcool com 5%% DE desconto  = %.2f",L,vt);
            }
        }
        printf("\nDeseja continuar? 1 = [SIM] || 2 = [NAO]\n--> ");
        scanf("%d",&exit);
        if (exit == 2)
            break;
            if (exit != 1 && exit != 2)
                printf("Invalido, encerrando programa");


    }while(exit==1);
}
#endif // ex1

/*
2 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
    pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
    comando if-else.
*/
#ifdef ex2 //  ok

main(){
    int maior=99,menor=1,t=0,media=50;
    char sinal;
    int exit;

    do{
    sinal = ' ';
    printf("Pense em um numero no intervalo de 0 a 99\n\n");

    while(sinal != '='){
        printf("O numero que voce pensou e %d? = , > ou < \n",media);
        scanf(" %c",&sinal);
        getchar();

        if (sinal == '<'){
            maior=media;
        }
        else if(sinal=='>'){
            menor=media;
        }

        media=(maior+menor)/2;
        t++;
    }
    if(t==1){
        printf("Acertei em %d tentativa\n",t);
    }

    if(t>1){
        printf("Acertei em %d tentativas\n",t);
    }
    printf("\nDeseja continuar? 1 = [SIM] || Qualquer tecla = [NAO]\n--> ");
    scanf("%d",&exit);
    getchar();
        if(exit != 1){
        break;
        }
    }while(1==1);
}
#endif // ex2

/*
3 - Resecreva o programa do execicio anterior agora utilizando o comando switch.
    Conte o n. de tentativas e imprima o resultado no video.
*/

#ifdef ex3 // OK!!

main(){
    int maior=99,menor=1,t=1,media=50, exit;
    char sinal;

    do{
    sinal = ' ';
    printf("Pense em um numero no intervalo de 1 a 99\n\n");

    do{
        printf("O numero que voce pensou e %d? = , > ou < \n",media);
        scanf(" %c",&sinal);
        getchar();

        switch(sinal){
            case '<':maior=media; break;
            case '>':menor=media; break;
            case '=':printf("Acertei na %d tentativa\n",t); break;
            default: printf("caractere invalido\n"); break;
        }
        media=(maior+menor)/2;
        t++;
    }while(sinal != '=');
    printf("\nDeseja continuar? 1 = [SIM] || Qualquer tecla = [NAO]\n--> ");
    scanf("%d",&exit);
        if(exit != 1){
            break;
            return 0;
        }
    }while(exit==1);
}
#endif // ex3

/*
4 - As ligacoes telefonicas s�o cobradas pela sua duracao. O sistema registra os
    instantes em que a ligacao foi iniciada e concluida.
    Escreva um programa que recebe via teclado dois instantes dados em
    horas, minutos e segundo e determina o intervalo de tempo
    (em horas, minutos e segundos) decorrido entre eles.
*/

#ifdef ex4 // OK!!

main()
{
    int H,M,S,A,B;
    int exit;

    do{
        do{
            do{
                printf("Digite a hora de inicio: ");
                scanf("%d",&H);
                if(H<0 || H>24)
                {
                    printf("Valor deve ser entre 0 e 23\n");
                }
            }while(H<0 || H>24);

            do{
                printf("Digite minutos de inicio: ");
                scanf("%d",&M);
                if(M<0 || M>59)
                {
                    printf("Valor deve ser entre 0 e 59\n");
                }
            }while(M<0 || M>59);

            do{
                printf("Digite segundos de inicio: ");
                scanf("%d",&S);
                if(S<0 || S>59)
                {
                    printf("Valor deve ser entre 0 e 59\n");
                }
            }while(S<0 || S>59);

            H = H*3600;   /*Converte horas pra segundos */
            M = M*60;     /*Converte minutos pra segundos*/
            A = H+M+S;   /*Soma todos os segundos*/

            do{
                printf("Digite a hora final: ");
                scanf("%d",&H);
                if(H<0 || H>24)
                {
                    printf("Valor deve ser entre 0 e 23\n");
                }
            }while(H<0 || H>24);

            do{
                printf("Digite os minutos finais: ");
                scanf("%d",&M);
                if(M<0 || M>59)
                {
                    printf("Valor deve ser entre 0 e 59\n");
                }
            }while(M<0 || M>59);

            do{
                printf("Digite os segundos finais: ");
                scanf("%d",&S);
                if(S<0 || S>59)
                {
                    printf("Valor deve ser entre 0 e 59\n");
                }
            }while(S<0 || S>59);

            H = H*3600;
            M = M*60;
            B = H+M+S;

            if(A>B)
            {
                printf("Horario Inicial Maior que o horario final\n");
            }
            else
            {
                A = B-A;
                H = A/3600;     /*Calculo de numero de horas*/
                S = A%3600;     /*PEGA O RESTO DE SEGUNDOS PARA USAR NO CALCULO DE MINUTOS*/
                M = S/60;       /*DIVIDE OS SEGUNDOS POR 60 PARA ACHAR OS MINUTOS*/
                S = S-(M*60);

                if(H==0)
                {
                    printf("A ligacao teve duracao de %dmin %dseg\n",M,S);
                }
                else if(H==1)
                {
                    printf("A ligacao teve duracao de %dhr %dmin %dseg\n",H,M,S);
                }
                else
                {
                    printf("A ligacao teve duracao de %dhrs %dmin %dseg\n",H,M,S);
                }
             }
        }while(A>B);
        printf("\nDeseja continuar? 1 = [SIM] || Qualquer tecla = [NAO]\n--> ");
        scanf("%d",&exit);
        if(exit != 1){
            break;
        }
    }while(1==1);
}

#endif ex4
/*
5 - Escreva um programa que receba via teclado numeros inteiros positivos.
    Quando o numero digitado for negativo o programa deve parar e calcula a
    media dos valores positivos digitados.
*/

#ifdef ex5 // OK!!

main()
{
    int num,acc=0,cont=0, exit;

    do{
        do{
            printf("Digite um numero: ");
            scanf("%d",&num);

            if(num>0)
            {
                acc += num;
                cont++;
            }
        }while(num>0);

    if(cont==0){
        printf("\nNao foi digitado nenhum numero positivo");
    }
    else {
        acc = acc/cont;
        printf("\nMedia dos %d numeros digitados = %d",cont,acc);
    }
     printf("\nDeseja continuar? 1 = [SIM] || Qualquer tecla = [NAO]\n--> ");
        scanf("%d",&exit);
        if(exit != 1){
            break;
            return 0;
        }
    }while(1==1);
}

#endif // ex5
