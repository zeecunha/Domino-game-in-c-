/**
 *  @file dominos.h
 *  @brief implementação de todas as funções do Programa.
 *
 *
 *  @author José Cunha (28018@ufp.edu.pt), Filipe Laranjeira (26388@ufp.edu.pt)
*/



#ifndef DOMINOES_H_INCLUDED
#define DOMINOES_H_INCLUDED

#define MAX_NOME 50

typedef struct peca{

int esq;    //lado esquerdo da peca
int dir;    //lado direito da peca
int estado; //estado da peca

}PECA;

typedef struct peca2{

int esq;    //lado esquerdo da peca
int dir;    //lado direito da peca
int estado; //estado da peca
struct peca2 * pnext; //proxima peca

}PECA2;

typedef struct mao
{
    char nomejogador[MAX_NOME];
    PECA2 *pfirstpeca;
    int npecas;
} MAO;

//typedef struct peca Pecas;

void create_domioes(PECA x[], int n);
void distribute_domioes(PECA x[], int nPieces, PECA y[], int n, int hSize);
void insert_peca_mao(MAO*pt, int esq, int dir);
void print_pecas_mao(MAO m);

#endif // DOMINOES_H_INCLUDED
