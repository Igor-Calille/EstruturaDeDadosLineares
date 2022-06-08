/* producao do pacote de operacoes em pilhas*/

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


typedef struct 
{
	
int topo;  //armazena a posicao do ultimo elemento da pilha
unsigned char Vetor[Max];  //armazena os elementos da pilha

}Pilha;

//interface
Pilha criarPilha();
void mostrarPilha(Pilha);
bool pilhaVazia(Pilha);
unsigned char acessarTopo(Pilha);
Pilha pushPilha(Pilha , unsigned char);
Pilha popPilha(Pilha);
bool pilhaCheia(Pilha);
Pilha esvaziarPilha(Pilha);



//implementacao

Pilha criarPilha(){
	Pilha A;
	A.topo = sinal;
	return A;
}

bool pilhaVazia(Pilha A){
	bool vazio = FALSE;
	if (A.topo == sinal){
		vazio = TRUE;
	}
	return vazio;
}

bool pilhaCheia(Pilha A){
	
	bool cheio = FALSE;
	if (A.topo == Max-1){
		cheio = TRUE;
	}
	return cheio;
}

Pilha pushPilha(Pilha A, unsigned char x){
	int pos;
	if(A.topo < Max-1){
		pos = A.topo+1;
		A.Vetor[pos] = x;
		A.topo = A.topo + 1;
	}
	return A;
}

Pilha popPilha(Pilha A){
	if(A.topo > sinal){
		A.topo = A.topo - 1;
	}
	return A;
}

unsigned char acessarTopo(Pilha A){
	int top, pos, i;

	if(A.topo > sinal){
		pos = A.topo;
		top = A.Vetor[pos];	
	}else{
		top = fantasma;
	}
	return top;
}

Pilha esvaziarPilha(Pilha A){
	A.topo = sinal;
	return A;
}

void mostrarPilha(Pilha A){
	int t, k;
	t = A.topo;
	if(t == sinal){
		printf("Pilha Vazia");
	} else{
		for(k = t; k>=0; k--){
			printf("\n %d", A.Vetor[k]);
		}
	}
}