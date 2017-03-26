#include <stdio.h>
#define TAMANHO 5

// Sintese:
// Objetivo: Ordenar um vetor usando o algoritmo Selection Sort.
// Entrada: Vetor de inteiros.
// Saida: Vetor ordenado.

// preenche o vetor com entrada do usuário
void preenche(int vetor[]){
	for(int contador = 0; contador < TAMANHO; contador++)
		scanf("%d", &vetor[contador]);
}

//ordena o vetor em ordem crescente
void selection(int vetor[]){

	for(int contador1 = 0; contador1 < TAMANHO; contador1++){
		int menor_indice = contador1;
		for(int contador2 = menor_indice + 1; contador2 < TAMANHO; contador2++){
			if(vetor[contador2] < vetor[menor_indice])
				menor_indice = contador2;
		}

		if(menor_indice != contador1){
			int aux = vetor[menor_indice];
			vetor[menor_indice] = vetor[contador1];
			vetor[contador1] = aux;
		}
	}
}

//imprime vetor
void imprime(int vetor[]){
	for(int contador = 0; contador < TAMANHO; contador++)
		printf("%d ", vetor[contador]);
	printf("\n");
}


int main(){
	int vetor[TAMANHO];
	preenche(vetor);
	selection(vetor);
	imprime(vetor);
	
	return 0;
}