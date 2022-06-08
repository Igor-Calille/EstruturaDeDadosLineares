#include <stdio.h>
#include <boolean.h>

#define MAX 10

typedef struct{
    int tamanho;
    int tab[MAX];
}Heap;

Heap criarHeapMaxima();
void inserirHeap(Heap *, int);
void retirarHeap(Heap *);
int obterMaximo(Heap *);
void aumentarChave(Heap *, int, int);
void diminuirChave(Heap *, int, int);
void restaurarHeapAcima(Heap *, int, int);
void mostarHeap(Heap *);

int main(){
    Heap TAD = criarHeapMaxima();
    TAB.tamanho = 7;
    TAB.tab[1] = 8;
    TAB.tab[2] = 7;
    TAB.tab[3] = 2;
    TAB.tab[4] = 5;
    TAB.tab[5] = 4;
    TAB.tab[6] = 3;
    TAB.tab[7] = 6;

    mostrarHeap(&TAD);
}

Heap criarHeapMaxima(){
    Heap A;
    A.tamanho = 0;

    return A;
}

void inserirHeap(Heap *A, int x){
    int tam = A->tamanho;
    int k = tam + 1;

    A->tab[k] = x;
    while(K> 1)


}

void restaurarHeapAcima(Heap *A, int u, int k){
    bool fim = false;
    int pai, aux;

    while(k >1 && fim == false){
        pai = k / 2;
        if(A->tab[pai] < A->[k]){
            aux = A->tab[pai];
            A->tab[pai] = A->tab[k];
            A->tab[k] = aux;
        }else{
            fim = true;
        }
    }
}

void mostarHeap(Heap *A){
    int k = 1, i;

    for(i = 1; i<=A->tamanho; i++){
        printf("%d", A->tab[i]);

        if(K = i){
            printf("\n");
            k = k * 2;
        }
    }
}