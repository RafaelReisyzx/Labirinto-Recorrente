#ifndef LABIRINTO_H
#define LABIRINTO_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define QuantMatriz 7
#include <unistd.h>
#include <ctype.h>

typedef struct Matriz{
char map[100][100];
char caminho[100][100];	
	} Matriz;
	
	typedef struct Mapa{
  Matriz Matrizes[QuantMatriz];
	} Mapa;
	
typedef struct Garoto{	
int hp;
int passos;
int itens;
int perigos;
int sacola;
int Inexplorado;

}Personagem;
			
void Initiation(Mapa *mat);
int GenerateMatrix(int n,int k,Mapa *mat);
void PrintMatrix(int n,int k,Mapa *mat);
void ReadMatriz(Mapa *mat);
int Jornada(int n,int k,Mapa *mat);
void Finalization(int n,int k,Mapa *mat);
 
#endif
