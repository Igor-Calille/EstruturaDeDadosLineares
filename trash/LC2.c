#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ghost -1

typedef struct Celula {
  int valor;
  struct Celula *next;
} Celula;

typedef Celula *Lista;

Lista criarLista();
int determinarTamanho(Lista);
bool listaVazia(Lista);
void mostrarLista(Lista);
Celula *buscarItem(Lista, int);
int obterItemK(Lista, int);
Lista Insere(Lista, int);
Lista removerItem(Lista, int);
Lista esvaziarLista(Lista A);

void ordenarB(Lista);
Lista inverter(Lista);
Lista removerDuplicata(Lista, int);
Celula *insereProximo(Celula *, int);
bool verificaIgual(Lista, Lista);
bool verificaDuplicata(Lista);
Lista criarListaFrequencia(Lista);
Lista trocar(Lista , Celula *, Celula *);

int main(){
    Lista TAD;
    TAD = criarLista();
    TAD = Insere(TAD, 1);
    TAD = Insere(TAD, 2);
    TAD = Insere(TAD, 3);
    TAD = Insere(TAD, 4);

    mostrarLista(TAD);
}


Lista criarLista(){
    Lista A;
    A = NULL;

    return A;
}

int determinarTamanho(Lista A){
    Celula *prox;
    int tam = 0, i=0;

    if(A != NULL){
        prox = A; i++;
        while(prox->next != A){
            prox = prox->next;
            i++;
        }
    }

    return i;
}

bool listaVazia(Lista);

void mostrarLista(Lista A){
    Celula *prox;

    if(A == NULL){
        printf("Lista vazia");
    }
    else{
        prox = A;
        printf("%d ", prox->valor);
        while(prox->next != A){
            prox = prox->next;
            printf("%d ", prox->valor);
        }
    }
}

Celula *buscarItem(Lista, int);
int obterItemK(Lista, int);

Lista Insere(Lista A, int x){
    Celula *novo, *prox;
    novo = malloc(sizeof(Celula));
    novo->valor = x;

    if(A == NULL){
        A = novo;
        novo->next = novo;
    }
    else{
        prox = A;
        while(prox->next != A){
            prox = prox->next;
        }
        novo->next = prox->next;
        prox->next = novo;
    }
    
    return A;
}

Lista removerItem(Lista, int);
Lista esvaziarLista(Lista A);
