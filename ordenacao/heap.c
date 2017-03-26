#include <stdio.h>
#define TAMANHO 5

// Sintese:
// Objetivo: Ordenar um vetor usando o algoritmo Buble Sort.
// Entrada: Vetor de inteiros.
// Saida: Vetor ordenado.

void preenche(int vetor[]){
// preenche o vetor com entrada do usuário
	for(int contador = 0; contador < TAMANHO; contador++)
		scanf("%d", &vetor[contador]);
}

void imprime(int vetor[]){
// imprime vetor
	for(int contador = 0; contador < TAMANHO; contador++)
		printf("%d ", vetor[contador]);
	printf("\n");
}

int menor(int valor1, int valor2, int valor3){

}

void heapfy(int valor, int vetor[]){
//
	pai_valor = valor/2;
	irmao_valor = 
	
}

void build_heap(int vetor[]){
// transforma vetor em heap
	int metade = TAMANHO/2;
	for(int contador = metade; contador >= 0; contador--){
		heapfy(vetor[contador], vetor);
	}
}

int main(){
	int vetor[TAMANHO];
	preenche(vetor);
	build_heap(vetor);
	imprime(vetor);
	
	return 0;
}