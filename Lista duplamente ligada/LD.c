/*
Arquivo: Lucas_Graziano_ListaLL.c

Autores: Lucas Costa Pessoa Graziano - RA00297851
		 Julio Cesar Barboza Filho   - RA00297586
		 Gustavo Scacchetti de Souza- RA00301499

Data: 20/05/22 09:26

Descricao: implementacao de funcoes envolvendo lista duplamente ligada, em ordem decrescente e sem duplicatas
*/

#define ghost -1
#include "Booleano.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Celula{
	int valor;
	struct Celula* next;
	struct Celula* pre;
} Celula;

typedef struct {
	int tam;
	Celula* inicio;
	Celula* fim;
} Lista;

Lista criarLista(); //feito
int determinarTamanho(Lista); //feito
bool listaVazia(Lista); //feito
void mostrarListaED(Lista); //Feito
void mostrarListaDE(Lista); //Feito
Celula* buscarItem(Lista, int); //feito
int obterItemK(Lista, int); //feito
Lista buscaInsere(Lista, int); //feito
Lista removerItem(Lista, int);//feito
Lista esvaziarLista(Lista); //feito

int main (){
	Lista A;
	int k;
	Celula *aux;
	bool vazio = FALSE;
	
	A = criarLista();
	
	A = buscaInsere(A, 3);
	//A = buscaInsere(A, 2);
	//A = buscaInsere(A, 1);
	//A = buscaInsere(A, 5);
	//A = buscaInsere(A, 5);
	//A = buscaInsere(A, 2);
	//A = buscaInsere(A, 7);
	//A = buscaInsere(A, 7);
	//A = buscaInsere(A, 5);
	
	mostrarListaED(A);
	/*A = removerItem(A, 2);
	printf("\n\n");
	
	mostrarListaED(A);
	k = obterItemK(A, 3);
	printf ("\n%d", k);
	aux = buscarItem(A, 1);
	printf("\n%d", aux->valor);
	*/
	printf("\n\n");
	A = esvaziarLista(A);
	
	vazio = listaVazia(A);
	
	//fiz isso aqui só pra confirmar q o esvaziar funcionou :)
	if(vazio == TRUE){
		printf("vazio");
	} else{
		printf("nao vazio");
	}
	
	A = buscaInsere(A, 2);
	//A = buscaInsere(A, 7);
	//A = buscaInsere(A, 7);
	//A = buscaInsere(A, 5);
	A = esvaziarLista(A);
	mostrarListaED(A);
	
	return 0;
}

Lista criarLista(){
	Lista ap;
	//comeca as variaveis como null
	ap.inicio= NULL; 
	ap.fim= NULL;
	ap.tam= 0;
	return ap;
} 

int determinarTamanho(Lista A){
	int tamanho;
	tamanho = A.tam; //apenas pega o tamanho da lista
	return tamanho;
}


Celula* buscarItem(Lista A, int pos){
  Celula *cel = NULL; 
  int i = 0;

  if(A.tam != 0){
    if(pos > 0 && pos <= A.tam){ //A posicao precisa ser maior do que 0 e menor que o tamanho da lista
      cel = A.inicio ; //coloca o valor da celula como o inicio da lista

      for(i = 2; i <= pos; i++){ //Ele comeca na posicao 2 porque a celula ja esta com o valor inicial
        cel = cel->next;
      }
    }
  }
  return cel;
}

bool listaVazia(Lista A){
	bool veri;
	if(A.inicio != NULL){ //faz a verificacao se a lista esta vazia
		veri = FALSE;
	} else veri = TRUE;
	
	return veri;
}



Lista buscaInsere(Lista A, int ch){
	Celula* novo, *p, *ant;
	novo = malloc(sizeof(Celula));
	novo->valor = ch; //passa o valor digitado pelo usuario na celula nova
	bool achouDuplicata = FALSE;
	bool veri = FALSE;
	
	if(A.inicio == NULL){ //se a lista tiver vazia, ele entra nessa funcao
		A.inicio = novo; 
		A.fim = novo;	
		novo->pre = NULL;
		novo->next = NULL;
		A.tam = A.tam + 1;
	} else {
		p = A.inicio;
		
		// verifica se o valor eh maior, se tem duplicata e se o valor nao eh null
		while(p != NULL && p->valor >= ch && achouDuplicata == FALSE){ 
			if(p->valor == ch){
				achouDuplicata = TRUE;
			}
			p = p->next;
		} 

		//O ch eh o menor numero
		if(p == NULL){
			//a celula nova ira entrar como ultima da lista
			ant = A.fim; //celula comeca na ultima posicao
			ant->next = novo;
			novo->pre = ant;
			novo->next = NULL; //terra
			
			A.fim = novo; //atualiza o endereco do fim
			A.tam = A.tam + 1; //atualiza o tamanho
			
		//se nao achou duplicata	
		} else if(achouDuplicata == FALSE){
			if(p != A.inicio){
				ant = p->pre; //<-- esta variavel esta sendo inicializada com o valor anterior
				novo->next = p; //<-- esta variavel esta apontando para o valor achado no while 
				p->pre = novo; //<-- se apontando de volta
				novo->pre = ant; // <-- ant esta apontando para o valor anterior
				ant->next = novo; //<-- se apontando de volta
			}else{ //<-- se o ch maior que o A.inicio, ele entra nessa funÃ§Ã£o
				p->pre = novo;
				novo->pre = NULL;
				novo->next = p;
				A.inicio = novo;
			}	
				A.tam = A.tam + 1;
		} 
		
	}
	return A;

}

void mostrarListaED(Lista A){ //mostra a lista da esquerda para a direita
    Celula * aux = A.inicio;
    if (A.inicio == NULL) printf("Lista Vazia\n");
    else{
        while (aux != NULL){
            printf(" %d ", aux->valor);
            aux = aux->next; //esta fazendo de A.inicio ate o fim
        }
    }
}

void mostrarListaDE(Lista A){ //mostra a lista da direita para a esquerda
    Celula * aux = A.fim;
    if (A.inicio == NULL) printf("Lista Vazia\n");
    else{
        while (aux != NULL){
            printf(" %d ", aux->valor);
            aux = aux->pre; //esta fazendo de A.fim ate o inicio
        }
    }
}

int obterItemK(Lista A, int n){
    Celula* p;
    int item = ghost; //ja inicializa o valor como fantasma

    if(A.inicio != NULL){ //se a lista nao tiver vazia, ele entra
        p = A.inicio; //coloca o valor como inicio da lista
        while((p->valor != n) && (p-> next != NULL)){ //enquanto o p->valor for diferente de n e o p->next for diferente de null, ele vai rodar a lista
            p=p->next;
        }
        if(p->valor == n) item = p->valor; //quando o valor igualar, ele passa o valor para o item 
    }

    return item;
}

Lista removerItem(Lista A, int pos){
  Celula *cel , *celAnt, *celPos;
  int i;

  if(A.tam != 0){ //so entra se a lista estiver vazia
    if(pos > 0 && pos <= A.tam){ //so entra se a posicao for maior que 0 e menor ou igual que A.tam
      cel = A.inicio; //inicializa a celula com o A.inicio

      for(i = 2; i <= pos; i++){ // comeca na segunda posicao pois a primeira ja esta na celula
        cel = cel->next;
      }
      if(cel == A.inicio){ //se a celula for igual a inicio, ele so remove o item que existe 
        A.inicio = NULL;
        A.fim = NULL;
        free(cel);
      }else { //se nao, pegamos tanto o valor anterior e posterior da celula e simplesmente removemos a celula
        celPos = cel->next;
        celAnt = cel->pre;
        celAnt->next = celPos;
        celPos->pre = celAnt;
        free(cel);
      }
      A.tam --;	 //atualizamos o tamanho da lista
    } 
  }
  return A;
}

Lista esvaziarLista(Lista A){
    Celula *cel, *prox;
    cel = A.inicio;
    prox = cel->next;
    if(A.inicio != NULL){
        while (prox != NULL){
            prox = cel->next;
            free(cel);
            A.tam = A.tam - 1;
            cel = prox;
                
        }
    A.inicio = NULL;
    A.fim = NULL;

    }
    return A;
}
/*
Lista esvaziarLista(Lista A){
	Celula *cel, *aux; //foi necessario um auxiliar para dar o free, senao ele nao consegue correr a lista pra limpar
	int tam = A.tam;
	int i;
	cel = A.inicio;
	while(cel != NULL){
		aux = cel;
		cel = cel -> next; 
		free(aux);
	}
	A.inicio = NULL;
	A.tam = 0;
	return A;
}
*/