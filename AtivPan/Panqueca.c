#include "Pilha.h"
#include "Fila.h"
#include "Booleano.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Pilha construirPilha(int );
Pilha inverter(Pilha, int);

int main(){
	Pilha TAD;
	Pilha TAD2;
	TAD = criarPilha();
	TAD2 = criarPilha();
	
	
	TAD = construirPilha(5);
	
	mostrarPilha(TAD);
	
	//TAD2 = inverter(TAD, 5);
	
	//mostrarPilha(TAD2);
	
}

Pilha inverter(Pilha A, int x){
	int i = 0;
	unsigned char c;
	Fila Q = criarFila();
	
	
	while(pilhaVazia(A) == FALSE && i < x){
		c = acessarTopo(A);
		A = popPilha(A);
		Q = pushFila( Q, c);
		i++;
	}	
	
	while(filaVazia( Q ) == FALSE){
		c = acessarPrimeiro( Q );
		Q = popFila( Q );
		A = pushPilha(A, c);
	}
	
	return A;
}

Pilha construirPilha(int n){
	Pilha A;
	A = criarPilha();
	int aux, j, i;
	unsigned char vet[Max], temp, aux2;
	
	for(i=0; i<n; i++){
		aux = i+1;
		vet[i] = (unsigned char)aux;
	}
	
	srand(time(NULL));
	
	for(i=n-1; i>=0; i--){
		j = rand() % (i+1);
		temp = vet[i];
		vet[i] = vet[j];
		vet[j] = temp; 
		aux2 = vet[i];
	}
	
	for(i=n-1; i>=0; i--){
		A = pushPilha(A, vet[i]);
	}

	return A;
}