#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"
#define fantasma -1

typedef struct Celula{
    int item; 
    struct Celula *next;
}Celula;

typedef struct{
    int tamanho;
    Celula *inicio;
}Lista;

Lista criarLista();
void mostrarLista(Lista *);
void inserirLista(Lista *, int);    //Inserir no começo da lista
bool verListaVazia(Lista *);
int obterTamanho(Lista *);
void removerUltimo(Lista *);
int obterElemento( Lista *, int);
Celula* buscarItem(Lista *, int);

void buscaRemove(Lista *, int);
void buscaInsere(Lista *, int); // Insere no início uma célula com o valor y somente se esse valor não ocorre na lista.
void Inverter(Lista *);
Lista removerDuplicata(Lista, int);

int main(){
    Lista TAD = criarLista();

    inserirLista(&TAD, 1);
    inserirLista(&TAD, 2);
    inserirLista(&TAD, 3);
    inserirLista(&TAD, 5);
    inserirLista(&TAD, 3);
    inserirLista(&TAD, 4);
    inserirLista(&TAD, 3);

    mostrarLista(&TAD);

    TAD = removerDuplicata(TAD, 3);

    printf("\n\n");

    mostrarLista(&TAD);


}

Lista criarLista(){
    Lista L;
    L.tamanho = 0;
    L.inicio = NULL;

    return L;
}

void mostrarLista(Lista *A){
    Celula *aux;

    if(A->tamanho != 0){
        aux = A->inicio;
        while(aux->next != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
        printf("%d ", aux->item);
    }
    else{
        printf("Lista vazia");
    }
}

void inserirLista(Lista *ap, int y){ //Inserir no começo da lista
    Celula *novo;
    novo = malloc(sizeof(Celula));
    novo->item = y;
    novo->next = ap -> inicio;
    ap -> inicio = novo;
    ap->tamanho = ap->tamanho + 1;
}

bool verListaVazia(Lista *ap){
    bool vazia;
    if(ap->inicio==NULL){
        vazia=TRUE;
    }else{
        vazia=FALSE;
    }
    return vazia;
}

void removerPrimeiro(Lista *ap){
    Celula *prim, *seg;

    if(ap->inicio != NULL){
        prim = ap->inicio;
        seg = prim->next;
        ap->inicio = seg;
        ap->tamanho = ap->tamanho - 1;
        free(prim);
    }

}

int obterTamanho(Lista *ap){
    int tam;
    tam = ap->tamanho;

    return tam;
}

void removerUltimo(Lista *ap){
    Celula *prim, *seg;

    if(ap->inicio != NULL){
        if(ap->tamanho == 1){
            prim = ap->inicio;
            ap->inicio = NULL;
            ap->tamanho = ap->tamanho - 1;
            free(prim);
        }
        else{
            prim = ap->inicio;
            seg = prim->next;
            while(seg->next != NULL){
                prim = seg->next;
                seg = prim->next;
            }
            prim->next = NULL;
            free(seg);
        }
    }

}

int obterElemento( Lista *ap, int k){
    Celula *prim;
    int elemento = fantasma;
    int i; //contador
    

    if( k > 0 && k <= ap->tamanho){

        prim = ap->inicio; i = 1;

        while(i < k)
        {
            prim = prim->next; i++;
        }
        elemento = prim->item;
    }

    return elemento;
}

Celula* buscarItem(Lista *ap, int k){
    Celula *prim, *seg;
    Celula *end = NULL;
    int i;
    

    if(ap->inicio != NULL && ap->tamanho < k){
        if(k == 1){
            end = ap->inicio;
        }
        else{
            prim = ap->inicio;
            for(i=2; i<=k; i++){
                prim = prim->next;
            }
            end = prim;
        }
    }

    return end;
}

void buscaRemove(Lista *A, int y){
    Celula *aux, *ant;

    if(A->tamanho != 0){
        aux = A->inicio;
        if(aux->item == y){
            A->inicio = aux->next;
            A->tamanho--;
        }
        else{
            while((aux->next != NULL) && (aux->item != y)){
                ant = aux;
                aux = aux->next;
            } 
            if(aux->item == y){
                ant->next = aux->next;
                free(aux);
                A->tamanho--;
            }
        }
        

    }
}

void buscaInsere(Lista *A, int y){ // Insere no início uma célula com o valor y somente se esse valor não ocorre na lista.
    Celula *aux, *novo;
    
    aux = A->inicio;
    while((aux != NULL) && (aux->item != y)){
        aux = aux->next;
    }
    if(aux == NULL){ // N achou
        novo = malloc(sizeof(Celula));
        novo->item = y;
        novo->next = A->inicio;
        A->inicio = novo;
        A->tamanho++;
    }
    
}

void Inverter(Lista *A){
    Celula *ant = NULL, *at, *prox;

    if(A->tamanho != 0){
        at = A->inicio;
        prox = at->next;
        
        if(prox != NULL){
            while(prox != NULL){
                at->next = ant;
                ant = at;
                at = prox;
                prox = prox->next;
            }
            at->next = ant;
            A->inicio = at;
        }
    }

}

Lista removerDuplicata(Lista A, int y){
    Celula *aux, *pas, *retirar;
    bool test = FALSE;

    if(A.tamanho != 0){
        aux = A.inicio;
        while(aux != NULL){
            if(aux->item == y){
                if(test == TRUE){
                    pas->next = aux->next;
                    retirar = aux;
                    free(retirar);
                    aux = pas;
                }
                test = TRUE;
            }
            pas = aux;
            aux = aux->next;
        }
    }

    return A;
}





