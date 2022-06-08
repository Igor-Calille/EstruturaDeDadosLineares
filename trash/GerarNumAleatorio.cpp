/* 
Arquivo: GerarNumALeatorio
Autor: Igor Masson Calille
Data:18/03/2022 7:20
Descriçâo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main(){
	int V[N];
	int k, g;
	srand((int)time(NULL));
	for(k=0;k<N;k++){
		g = rand();
		V[k] = g;
	}
	for(k=0;k<N;k++)
	printf("\n %d	", V[k]);

	printf("\n\n Termino do programa");	
	return 0;
}

