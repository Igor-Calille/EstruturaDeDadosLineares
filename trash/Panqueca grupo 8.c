/* GRUPO 8
	pasta extra
*/

/*
    Arquivo: Panqueca.c
    Nomes: Mateus Assalti Santana, Luis Felipe Almeida Beserra Matos, Igor Masson Calille
    Data: 18/05/2022
    Descricao: Produzir  um  programa  para  colocar  a  pilha  em  ordem  crescente,  
    com  o  menor  numero  no  topo  da  pilha, usando a estrategia apresentada no esboco do algoritmo PS.
    O programa deve conter o pacote do tipo Pilha e o pacote do tipo Fila, veja interface no final do texto.

*/

#include "Pilha.h"
#include "Fila.h"
#include <stdlib.h>
#include <time.h>

int contarPilha(Pilha , unsigned char );
Pilha inverter(Pilha , int );
Pilha construirPilha(int);

int main(){
    int n = Max;
    Pilha A = construirPilha(n);
    mostrarPilha(A);
	int qtd;
	

	do{
		qtd = contarPilha(A, n);
		//printf("%d\n", qtd);
		if(qtd != n){
			if(qtd != 1){
				A = inverter(A, qtd);
			}
			A = inverter(A, n);
		}
		n--;
	}while(n != 1);
	
	mostrarPilha(A);
    return 0;
}


Pilha construirPilha(int n){
	
    int i,  aleatorio;
	unsigned char vet[n], temp;
	unsigned char item;
	Pilha A = criarPilha();
	
	for(i = 0; i < n; i++){
		vet[i] = i + 1;		
	}
	
	srand(time(NULL));
	//Fisher-Yates
	for(i = n - 1; i >= 0; i--){
		aleatorio = rand() % (i + 1); // Resto = i,...,0
		temp = vet[aleatorio];
		vet[aleatorio] = vet[i];
		vet[i] = temp;
	} 
	
	for(i = 0; i < n; i++){
		temp = vet[i];
		A = pushPilha(A, temp);
	}
	
	return A;
}

Pilha inverter(Pilha S, int qtd){

    Fila temp;
    temp = criarFila();
    int i = 0;
    unsigned char item;
    
    while(pilhaVazia(S) == FALSE && i < qtd){
        item = acessarTopo(S);
        S = popPilha(S);
        temp = pushFila(temp, item);
        i = i + 1;
    }

    while(filaVazia(temp) == FALSE){

        item = acessarPrimeiro(temp);
        S = pushPilha(S, item);
        temp = popFila(temp);
    }

    return S;

}

int contarPilha(Pilha pilha, unsigned char valor){
	int qtd = 0, cont = pilha.topo;
	bool achou = FALSE;
	unsigned char item;
	

	while((pilhaVazia(pilha) == FALSE) && (achou == FALSE)){
		item = acessarTopo(pilha);
		
		if(valor == item){ 
            achou = TRUE;
        }
		qtd++;
		pilha = popPilha(pilha);
	}
	if(!achou){ 
        qtd = 0; 
    }
	return qtd;
}