#include <stdio.h>
#include "Booleano.h"

#define max 10
#define sinal -1
#define fantasma '*'

typedef struct{
    int inicio;
    int fim;
    int vetor[max];
} Fila;

Fila criarFila( );
void mostrarFila(Fila);//
bool FilaVazia( Fila );
int acessarPrimeiro( Fila );
Fila pushFila( Fila, int x);
Fila popFila( Fila );

Fila criarFila( ){
    Fila A;
    A.inicio = sinal;
    A.fim = sinal;

    return A;
}

void mostrarFila(Fila A){
    int i = A.inicio, f = A.fim;

    if(i == sinal){
        printf("lista vazia");
    }
    else{
        while(i != f){
            printf("%d ", A.vetor[i]);
            i = (i+1) % max;
        }
        printf("%d ", A.vetor[i]);
    }
}

bool FilaVazia( Fila A){
    bool test = FALSE;
    if(A.inicio == sinal){
        test =  TRUE;
    }

    return test;
}

int acessarPrimeiro( Fila A){
    int ele = fantasma;

    if(A.inicio != sinal){
        ele = A.vetor[A.inicio];
    }

    return ele;
}

Fila pushFila( Fila A, int x){
    int seg;
    seg = (A.fim + 1) % max;
    if(seg != A.inicio){
        A.vetor[seg] = x;
        if(A.inicio = sinal){
            A.inicio = seg;
        }
        A.fim = seg;
    }

    return A;
}

Fila popFila( Fila A){
    if(A.inicio != sinal){
        
    }
}



