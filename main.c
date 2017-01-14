///
///  @file main.c
///  @brief main for LP1 project2
///
///  José Cunha (28018@ufp.edu.pt), Filipe Laranjeira (26388@ufp.edu.pt)
///

#include <stdio.h>
#include <stdlib.h>
#include "dominoes.h"
#include <time.h>

/// MENU DE JOGO

int main(int argc, char *argv[])
{

    PECA iniciais[28], jogador[28];
    int i, j,nPieces=28, opcao, nHand, hSize;

    do
    {
        printf("\n----- PROJETO LP1 : DOMINO -----\n");
        printf("\n-----  Escolha uma opcao:  -----\n");
        printf("1 - Uma mao\n");
        printf("2 - Duas ou mais maos\n");
        printf("3 - Imprimir uma mao em int e char\n");
        printf("4 - Gerar N peças e gravar em .TXT\n");
        printf("5 - Gerar N peças e gravar em .BIN\n");
        printf("6 - Gerar N peças e juntar a estrutura mao\n");
        printf("0 - Exit\n");
        printf("\n----- PROJETO LP1 : DOMINO  JOSE CUNHA - FILIPE LARANJEIRA -----\n");

        scanf("%d", &opcao);

        switch(opcao)
        {

        case 1:
        {
            printf("QUANTAS PECAS QUER?\n");
            scanf("%d", &hSize);    //tamanho da mao
            if (hSize != 7)
            {
                create_domioes(iniciais, nPieces);  //criar dominos
                distribute_domioes(iniciais, nPieces, jogador, 28, hSize); //distibuir dominos

                for(i=0; hSize>i; i++)
                {
                    printf("\tPECA[%d]:\t[%d|%d]",i, jogador[i].esq, jogador[i].dir); //imprimir
                }
            }
            else
            {
                printf("INSIRA UM NUMERO VALIDO");
            }
            break;
        }

        case 2:
        {
            printf("QUANTAS MAOS QUER?\n");
            scanf("%d", &nHand);    //n de mao
            printf("QUANTAS PECAS QUER?\n");
            scanf("%d", &hSize);    //tamanho da mao
            if (nHand * hSize < 28)
            {
                for(j=0; j<nHand; j++)  //ate ao numero de maos pretendido , faz o ciclo
                {
                    create_domioes(iniciais, nPieces);  //criar pecas
                    distribute_domioes(iniciais, nPieces, jogador, 28, hSize); //distribuir pecas
                    printf("\n Mao [%d]\n", j);
                    for(i=0; hSize>i; i++)
                    {
                        printf("\tPECA[%d]:\t[%d|%d]\n", i, jogador[i].esq, jogador[i].dir);  //imprimir
                    }
                }
            }
            else
            {
                //se passar as 28 peças e tamanho 7
                return printf("N MAOS X N PECAS > 28. POR FAVOR INSERIR NOVAS OPCOES!");
            }
        }
        break;

        case 3:
        {
            int ascii='0';  //ascii do zero
            printf("QUANTAS MAOS QUER?\n");
            scanf("%d", &nHand);    //n de mao
            printf("QUANTAS PECAS QUER?\n");
            scanf("%d", &hSize);    //tamanho da mao
            if (nHand * hSize < 28)
            {
                for(j=0; j<nHand; j++)  //ate ao numero de maos pretendido , faz o ciclo
                {
                    create_domioes(iniciais, nPieces);  //criar pecas
                    distribute_domioes(iniciais, nPieces, jogador, 28, hSize); //distribuir
                    printf("\n Mao(%d): \n", j);

                    for(i=0; hSize>i; i++)
                    {
                        printf("Inteiro: \n");
                        printf("PECA[%d]:\t[%d|%d]\n", i, jogador[i].esq, jogador[i].dir);
                        printf("Char: \n");
                        printf("PECA[%d]:\t[%c %c]\n", i, (jogador[i].esq) + ascii, (jogador[i].dir)+ascii);
                    }
                }
            }
            else
            {
                //se passar as 28 peças e tamanho 7
                return printf("N MAOS X N PECAS > 28. POR FAVOR INSERIR NOVAS OPCOES!");
            }
        }
        break;

        case 4:
        {
            FILE *fp = NULL;
            printf("QUANTAS PECAS QUER?\n");
            scanf("%d", &hSize);    //tamanho da mao
            if (hSize != 7)
            {
                create_domioes(iniciais, nPieces);  //criar dominos
                distribute_domioes(iniciais, nPieces, jogador, 28, hSize); //distribuir
                if ((fp=fopen("/Users/ZeeCunha/Desktop/project2/path.txt", "w"))!= NULL)    //caminho, escrever
                {

                    for(i=0; hSize>i; i++)
                    {
                        fprintf(fp, "PECA[%d] : [%d|%d]\n", i, jogador[i].esq,jogador[i].dir);    //gravar no txt
                        fprintf(stdout, "%d : [%d|%d]\n", i, jogador[i].esq,jogador[i].dir);    //IMPRIMRI O QUE GRAVOU NO TXT
                    }

                }
                fclose(fp);
            }
        }
        break;

        case 5:
        {
            FILE *fp = NULL;
            printf("QUANTAS PECAS QUER?\n");
            scanf("%d", &hSize);    //tamanho da mao
            if (hSize != 7)
            {
                create_domioes(iniciais, nPieces);  //criar pecas
                distribute_domioes(iniciais, nPieces, jogador, 28,hSize); //distribuir pecas
                if ((fp=fopen("/Users/ZeeCunha/Desktop/project2/path.bin", "wb"))!= NULL)   //caminho, escrever em bin
                {

                    for(i=0; hSize>i; i++)
                    {
                        fwrite(&i, sizeof(int),1,fp);   //conteudo, tamanho do inteiro, 1 , para gravar 1 inteiro, file pointer
                        fwrite(&jogador[i].esq, sizeof(int), 1, fp);    //conteudo, tamanho do inteiro, 1 , para gravar 1 inteiro, file pointer
                        fwrite(&jogador[i].dir, sizeof(int),1,fp);  //conteudo, tamanho do inteiro, 1 , para gravar 1 inteiro, file pointer
                    }

                }
                fclose(fp);
            }
        }
        break;

        case 6:
        {
           MAO m= {"DOMINO", NULL, 0};
           insert_peca_mao(&m, 0,0); //PECA [0|0]
           insert_peca_mao(&m, 0,1);  //PECA [0|1]
           insert_peca_mao(&m, 0,2);//PECA [0|2]
           print_pecas_mao(m); //IMPRIMIR PECA
        }
        break;
        }
    }
    while(opcao!=0);
    system("PAUSE");
    return 0;
}
