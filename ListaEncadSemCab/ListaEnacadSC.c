#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"
#define fantasma -1

typedef struct Celula{
    int item; 
    struct Celula *next;
}Celula;

typedef Celula *Lista;

Lista newLista( );
bool ListaVazia(Lista);
int obterTamanho(Lista);
int obterElemento(Lista, int);
Celula* buscarItem(Lista, int);
void mostrarLista(Lista);
Lista inserirListaUlt(Lista, int);
Lista inserirListaPrim(Lista, int);
Lista removerPrimeiro(Lista);
Lista removerUltimo(Lista);
Lista esvaziarLista(Lista);
Lista inverterLista(Lista);
Lista inverter(Lista A);

int main(){
    Lista TAD;
    TAD = newLista();

    TAD = inserirListaUlt(TAD, 1);
    TAD = inserirListaUlt(TAD, 2);
    TAD = inserirListaUlt(TAD, 3);
    TAD = inserirListaUlt(TAD, 4);

    mostrarLista(TAD);

    TAD = inverter(TAD);

    mostrarLista(TAD);
    printf("\n%d ", obterTamanho(TAD));

    TAD =  esvaziarLista(TAD);

    printf("\n%d ", obterTamanho(TAD));

    mostrarLista(TAD);


    return 0;
}

Lista newLista(){
    Lista novaLista;
    novaLista = NULL;

    return novaLista;
}

bool ListaVazia(Lista A){
    bool test = FALSE;

    if(A == NULL){
        test = TRUE;
    }

    return test;
}

int obterTamanho(Lista A){
    Celula *prim;
    int tam = 0;

    if(A != NULL){
        prim = A; tam++;
        while(prim->next != NULL){
            prim = prim->next;
            tam++;
        }
    }

    return tam;
}

int obterElemento(Lista A, int x){//obtem o elemento da posicao x
    Celula *prim;
    int i, elemento;

    if(A != NULL){
        prim = A;
        i = 1;
        while(prim->next != NULL && i != x){
            prim = prim->next;
        }
        elemento = prim->item;
    }

    return elemento;
}

Celula* buscarItem(Lista A, int x){
    Celula *prim, *end;
    int i;

    if(A != NULL){
        prim= A;
        i=1;
        while(prim->next != NULL && i != x){
            prim = prim->next;
            i++;
        }
        end = prim;
    }

    return end;
}


void mostrarLista(Lista A){
    Celula *prim;

    if(A == NULL){
        printf("Lista Vazia");
    }
    else{
        prim = A;
        printf("\n%d ", prim->item);
        while(prim->next != NULL){
            prim = prim->next;
            printf("%d ", prim->item);
        }
    }
}

Lista inserirListaUlt(Lista A, int el){
    Celula *prim, *novo;

    novo = malloc(sizeof(Celula));

    if(A == NULL){
        novo->item = el;
        novo->next = NULL;
        A = novo;
    }
    else{
        prim = A;
        while(prim->next != NULL){
            prim = prim->next;
        }
        novo->item = el;
        novo->next = NULL;
        prim->next = novo;
    }

    return A;
}

Lista inserirListaPrim(Lista A, int el){
    Celula *prim, *novo;

    novo = malloc(sizeof(Celula));

    if(A == NULL){
        novo->item = el;
        novo->next = NULL;
        A = novo;
    }
    else{
        novo->item = el;
        novo->next = A;
        A = novo;

    }

    return A;
}

Lista removerPrimeiro(Lista A){
    Celula *prim, *seg;

    if(A != NULL){
        prim = A->next;

        if(prim->next == NULL){
            A = NULL;
            free(prim);
        }
        else{
            seg = prim->next;
            A = seg;
            free(prim);
        }
        
    }

    return A;
}

Lista removerUltimo(Lista A){
    Celula *prim, *ant, *novo;
    novo = malloc(sizeof(Celula));

    if(A != NULL){
        prim = A;
        if(prim->next == NULL){
            A = NULL;
            free(prim);
        }
        else{
            while(prim->next != NULL){
                ant = prim;
                prim = prim->next;
            }
            ant->next = NULL;
            free(prim);
        }

    }

    return A;
}

Lista esvaziarLista(Lista A){
    Celula *prim, *seg;

    if(A != NULL){
        prim = A;
        while(prim->next != NULL){
            seg = prim->next;
            free(prim);
            prim = seg;
        }
        A = NULL;
    }

    return A;
}

Lista inverterLista(Lista A){
    Celula *prim, *seg, *terc = NULL;

    if(A != NULL){
        prim = A;
        if(prim->next != NULL){
            seg = prim->next;
            while(prim != NULL){
                terc = seg->next;
                seg->next = prim;
                prim = terc;
                if(prim != NULL){
                    prim->next = seg;
                    seg = terc->next;
                }

            }
            prim = A;
            prim->next = NULL;
            A = seg;
        }
    }

    return A; 
}

Lista inverter(Lista A){

    Celula *ant, *atual, *seg;

    if(A != NULL){
        ant = NULL;
        atual = A;
        seg = atual->next;

        if(seg != NULL){

            while(seg != NULL){
                atual->next = ant;
                ant = atual;
                atual = seg;
                seg = seg->next;
                
            }
            atual->next = ant;
            A = atual;
        }
    }
    return A;
}
