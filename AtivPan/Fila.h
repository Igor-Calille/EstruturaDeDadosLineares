/*
	Arquivo: Igor Masson Calille
	Autor: 
	Date: 
	Descricao: 
*/
#include <stdio.h>
#include "Booleano.h"

#define Max 10
#define sinal -1
#define fantasma '*'

typedef struct{
	int inicio;
	int fim;
	int Vetor[Max];
} Fila;

Fila criarFila( );
void mostrarFila(Fila);//
bool FilaVazia( Fila );
unsigned char acessarPrimeiro( Fila );
Fila pushFila( Fila, unsigned char);
Fila popFila( Fila );

Fila criarFila( ){
	Fila Q;
	Q.inicio = sinal;
	Q.fim = sinal;
	return Q;
}

void mostrarFila(Fila Q){
	int i, f;
	i = Q.inicio;
	f = Q.fim;
	
	if(i == sinal){
		printf("\nFila vazia");
	}
	else{
		while(i != f){
			printf(" %c ", Q.Vetor[i]);
			i = (i + 1) % Max;
		}
		printf(" %c", Q.Vetor[Q.fim]);
	}
	
}

bool filaVazia( Fila Q ) {
	bool vazia;
	vazia = FALSE;
	if( Q.inicio== sinal ){
		vazia = TRUE;
	} 
	return vazia;
}

unsigned char acessarPrimeiro( Fila Q ) {
	unsigned char y, p;
	y = fantasma; 
	if( Q.inicio!= sinal ){
		p = Q.inicio;
		y = Q.Vetor[ p ];
	}
	return y;
}

Fila pushFila( Fila Q, unsigned char y ){
	int seg;
	seg= (Q.fim+ 1) % Max;
	if( seg!= Q.inicio){
		Q.Vetor[seg] = y;
		if( Q.inicio== sinal ){
			Q.inicio= seg;
		}  
		Q.fim= seg;
	}
	return Q;
}

Fila popFila( Fila Q ){
	int seg;
	if( Q.inicio!= sinal ){
		if( Q.inicio == Q.fim) {
			Q.inicio = sinal; 
			Q.fim = sinal; 
		} 
		else{ 
			seg = (Q.inicio + 1) % Max;
			Q.inicio = seg;
		}
	}
	return Q;
}