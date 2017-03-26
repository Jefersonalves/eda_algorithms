#include <stdio.h>
#define QUANTIDADE 20

//Sintese:
//Objetivo: Encontrar a chave do registro que contenha o valor procurado usando a busca indexada
//Entradas: Vetor de registros
//Saidas: Chave procurada

typedef struct registro{
	int chave;
	float valor;
}REGISTRO;

typedef struct tabela_index{
	int kindex;
	float valor;
}TABELA_INDEX;

void preenche_registros(REGISTRO registros[]){
	for(int contador = 0; contador < QUANTIDADE; contador++){
		registros[contador].chave = contador; // função geradora de chaves
		printf("Digite o valor associado ao indice %d\n", contador);
		scanf("%f", &registros[contador].valor);
	}
}

void imprime_registros(REGISTRO registros[]){
	for(int contador = 0; contador < QUANTIDADE; contador++){
		printf("Chave: %d Valor: %.2f\n", registros[contador].chave, registros[contador].valor);
	}
}

int busca_sequencial(REGISTRO registros[], int index, float procurado, int final){
	for(int i = index; i < final; i++)
		if(procurado == registros[i].valor)
			return i;
	return -1;
}

void busca_indexada(TABELA_INDEX tabela[], float procurado, REGISTRO registros[]){

	int n;

	for(int i = 0; i < QUANTIDADE/5; i+=5) {
		if(tabela[i].valor > procurado) {
			n = busca_sequencial(registros, i-5, procurado,i);
			break;
		}
	}

	printf("%d. Valor: %f", n, registros[n].valor);
}

void preenche_index (REGISTRO registros[], TABELA_INDEX tabela[]){
	int m = 0;

	for(int i = 0; i < QUANTIDADE/5; i++) {
		tabela[i].kindex = m;
		tabela[i].valor = registros[m].valor;
		m+=5;
	}
}

void printTabela (TABELA_INDEX tabela[]) {
	printf("Tabela de Index\n");
	for(int i = 0; i < QUANTIDADE/5; i++) {
		printf("K = %d     Chave = %.2f\n", tabela[i].kindex, tabela[i].valor);
	}
}

int main(){
	REGISTRO registros[QUANTIDADE];
	TABELA_INDEX tabela_index[QUANTIDADE/5];
	float procurado;

	preenche_registros(registros);
	imprime_registros(registros);
	preenche_index(registros, tabela_index);
	printTabela(tabela_index);
	printf("Procurado: ");
	scanf("%f", &procurado);
	busca_indexada(tabela_index, procurado, registros);



	return 0;
}