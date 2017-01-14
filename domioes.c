/**
 *  @file dominos.c
 *  @brief implementação de todas as funções do Programa.
 *
 *
 *  @author José Cunha (28018@ufp.edu.pt), Filipe Laranjeira (26388@ufp.edu.pt)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominoes.h"

/**
     * FUNÇÃO para criar as pecas;
     *
	 * @param PECA - PECA iniciais[28]
	 * @param n - 28 pecas
     * @return
     */


void create_domioes(PECA x[], int n)
{
    int i, j=0, c=1, w=2, y=3, s=4, a=5;

    for(i=0;i<=6;i++)   //criar peças esq = 0 dir = 0 ate 6
    {
        x[i].estado=1;
        x[i].esq=0;
        x[i].dir=j;
        j++;
    }
    for(i=7;i<=12;i++)  //criar peças esq = 1 dir = 1 ate 6
    {
        x[i].estado=1;
        x[i].esq=1;
        x[i].dir=c;
        c++;
    }
    for(i=13;i<=17;i++) //criar peças esq = 2 dir = 2 ate 6
    {
        x[i].estado=1;
        x[i].esq=2;
        x[i].dir=w;
        w++;
    }
    for(i=18;i<=21;i++) //criar peças esq = 3 dir = 3 ate 6
    {
        x[i].estado=1;
        x[i].esq=3;
        x[i].dir=y;
        y++;
    }
    for(i=22;i<=24;i++) //criar peças esq = 4 dir = 4 ate 6
    {
        x[i].estado=1;
        x[i].esq=4;
        x[i].dir=s;
        s++;
    }
    for(i=25;i<=26;i++) //criar peças esq = 5 dir = 5 ate 6
    {
        x[i].estado=1;
        x[i].esq=4;
        x[i].dir=a;
        a++;
    }

        x[27].estado=1; //criar peças esq = 6 dir = 6
        x[27].esq=6;
        x[27].dir=6;

}


/**
     * FUNÇÃO para distribuir as pecas;
     *
	 * @param PECA x - PECA iniciais[28]
	 * @param nPieces - numero de pecas
	 * @param PECA Y - armazenar pecas para o jogador
	 * @param n - 28 pecas
	 * @param hSize - tamanh pretendido
     * @return
     */



void distribute_domioes(PECA x[], int nPieces, PECA y[], int n, int hSize)
{
    int i, nRandom;

    for(i=0;i<hSize;i++)    //ate ao tamanho da mao
    {
        int nPieces=0;

        do{
            srand(time(NULL));
            nRandom= rand() % 28;   //random
            if(x[nRandom].estado==1)    //peca inicial
            {
                y[i].dir=x[nRandom].dir;    //peca direita jogador
                y[i].esq=x[nRandom].esq;    //peca esquerda jogador
                x[nRandom].estado=0;    //estado da peca inicial a zero
                y[i].estado=1;  //peca jogador
                nPieces=1;
            }
        }while(nPieces==0);
    }
}


/**
     * FUNÇÃO para inserir as pecas nas maos;
     *
	 * @param MAO*pt - estrutura mao
	 * @param esq - lado esq
	 * @param dir - lado dir
     * @return
     */

void insert_peca_mao(MAO*pt, int esq, int dir)
{
    PECA2* pnew=NULL;
    pnew=(PECA2*)malloc(sizeof(PECA2)); //alocar espaço para a peca
    pnew->esq=esq;  //lado esq
    pnew->dir=dir;  //lado direiro
    pnew->pnext=NULL;   //pnext =null

    if(pt->pfirstpeca==NULL)    //se for a primeira
    {
        pt->pfirstpeca=pnew;    //pfirstpeca = pnew
        pt->npecas++;   //aumenta o numero de pecas
        return;
    }   //caso ja exista
    pnew->pnext=pt->pfirstpeca; //a proxima peca passa a ser a primeira
    pt->pfirstpeca=pnew;
    pt->npecas++;

}
/**
     * FUNÇÃO para imprimir as maos;
     *
	 * @param MAO*pt - estrutura mao
     * @return
     */
void print_pecas_mao(MAO m)
{
    PECA2* paux= m.pfirstpeca;  //apontar para a primeira peca
    while(paux!=NULL)   //enquanto houver pecas
    {
        printf(" [%d|%d]\n", paux->esq, paux->dir); //imprime lado esq lado dir
        paux=paux->pnext;   //apontar para proximo
    }
}
