#ifndef LABIRINTO_H
#define LABIRINTO_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define QuantMatriz 7
#include <unistd.h>
#include <ctype.h>

typedef struct Matriz{
char matrix[100][100];
char caminho[100][100];	
	} Matriz;
typedef struct Garoto{	
int hp;
int passos;
int itens;
int perigos;
int sacola;
int Inexplorado;

}Personagem;
	
		
Matriz Matrizes[QuantMatriz];
void Initiation();
int GenerateMatrix(int n,int k);
void PrintMatrix(int n,int k);
void ReadMatriz();
int Jornada(int n,int k);
void Finalization(int n,int k);
 
#endif
