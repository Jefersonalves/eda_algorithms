#include <stdio.h>
#define TAMANHO 5

// Sintese:
// Objetivo: Ordenar um vetor usando o algoritmo Insertion Sort.
// Entrada: Vetor de inteiros.
// Saida: Vetor ordenado.

void preenche(int vetor[]){
// preenche o vetor com entrada do usuário
	for(int contador = 0; contador < TAMANHO; contador++)
		scanf("%d", &vetor[contador]);
}

void insertion(int vetor[]){
// aplica insertion sort no vetor
	for(int contador1 = 1; contador1 < TAMANHO; contador1++){
		for(int contador2 = contador1; contador2 > 0; contador2--){
			if(vetor[contador2] < vetor[contador2 - 1]){
				int aux = vetor[contador2];
				vetor[contador2] = vetor[contador2 - 1];
				vetor[contador2 - 1] = aux;
			}
		}
	}
}

void imprime(int vetor[]){
// imprime vetor
	for(int contador = 0; contador < TAMANHO; contador++)
		printf("%d ", vetor[contador]);
	printf("\n");
}


int main(){
	int vetor[TAMANHO];
	preenche(vetor);
	insertion(vetor);
	imprime(vetor);
	
	return 0;
}