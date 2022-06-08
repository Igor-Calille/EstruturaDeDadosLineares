#include <stdio.h>
#include "Booleano.h"

#define Max 10
#define sinal -1
#define fantasma -1

typedef struct Celula{
    unsigned char item;
    struct Celula *next;
}Celula;

typedef Celula *Pilha;

Pilha criarPilha();
void mostrarPilha(Pilha);
bool pilhaVazia(Pilha);
int acessarTopo(Pilha);
Pilha pushPilha(Pilha , int);
Pilha popPilha(Pilha);
bool pilhaCheia(Pilha);
Pilha esvaziarPilha(Pilha);
void removerDuplicata(Pilha, int);

Pilha criarPilha(){
    Pilha A;
    A = NULL;

    return A;
}

void mostrarPilha(Pilha A){
    Celula *aux;

    if(A == NULL){
        printf("Pilha vazia");
    }
    else{
        aux = A;
        while(aux->next != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
    }
}

bool pilhaVazia(Pilha A){
    bool test = FALSE;
    if(A==NULL){
        test = TRUE;
    }

    return test;
}

int acessarTopo(Pilha A){
    Celula *aux;
    int el = fantasma;

    if(A != NULL){
        aux = A;
        el = aux->item;
    }

    return el;
}

Pilha pushPilha(Pilha A , int x){
    Celula *aux, *novo;
    novo = malloc(sizeof(Celula));
    novo->item = x;

    if(A == NULL){
        A = novo;
    }
    else{
        aux = A;
        A = novo;
        novo->next = aux; 
    }

    return A;
}

Pilha popPilha(Pilha A){
    Celula *aux;
    
    if(A != NULL){
        aux = A;
        A = aux->next;
    }

    return A;
}





/*
bool pilhaCheia(Pilha A){
    Celula *aux;
    int tam = 0;
    bool test = FALSE;

    if(A != NULL){
        aux = A;tam++;
        while(aux->next != NULL){
            aux = aux->next; tam++;
        }
        if(tam == Max){
            test = TRUE;
        }

    }
}
*/


