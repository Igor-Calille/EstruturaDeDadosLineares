#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>

#define sinal -1
#define fantasma 0
#define max	10

typedef struct{
	int topo;
	unsigned char Vetor[max];
}Pilha;

Pilha criarPilha();
bool PilhaVazia(Pilha);
unsigned char acessarPilha(Pilha);
Pilha pushPilha(Pilha, unsigned char);
Pilha popPilha(Pilha);
Pilha esvaziarPilha(Pilha);
void mostrarPilha(Pilha);

int main(){
	Pilha TAD;
	TAD = criarPilha();
	TAD = pushPilha(TAD, A);
	TAD = pushPilha(TAD, M);
	TAD = pushPilha(TAD, O);
	TAD = pushPilha(TAD, R);
	
	mostrarPilha(TAD);
	
	TAD = popPilha(TAD);
	
	mostrarPilha(TAD);
	
	return 0;
}

Pilha criarPilha(){
	Pilha A;
	A.topo = sinal;
	
	return A;
}

bool PilhaVazia(Pilha A){
	bool test = false
	
	if(A.topo == sinal){
		test = true;
	}
	
	return test;
}

unsigned char acessarPilha(Pilha A){
	unsigned char elemento;
	
	if(PilhaVazia(A) == false){
		elemento = A.Vetor[A.topo];
	
	}
	
	return elemento;
}

Pilha pushPilha(Pilha A, unsigned char c){
	
	if(A.topo < max){
		A.topo =+ 1;
		A.Vetor[A.topo] = c;
	}
	
	return A;
}

Pilha popPilha(Pilha A){
	
	if(PilhaVazia(A) == false){
		A.topo =- 1;
	}
	
	return A;
}

void mostrarPilha(Pilha A){
	unsigned char elemento;
	
	criarPilha aux;
	aux = A;
	
	do{
		elemento = acessarPilha(aux);
		printf("%c", (char)elemento);
		aux = popPilha(aux);
		
	}while(PilhaVazia(aux) == false)
}