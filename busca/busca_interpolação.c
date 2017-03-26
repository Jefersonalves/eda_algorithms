#include <stdio.h>
#define DIMENSAO 4 // tamanho do vetor de registros

//Sintese:
//Objetivo: Encontrar a chave do registro que contenha o valor procurado usando a busca por interpolação
//Entradas: Não possui entradas
//Saidas: Chave do registro que contem o valor procurado

typedef struct registro{
	int chave;
	int valor;
}REGISTRO;

int buca_interpolacao(REGISTRO registros[], int valor_procurado){
// aplica a busca por interpolação no vetor de registros
	int x0 = registros[0].chave; 
	int x1 = registros[DIMENSAO].chave;
	int y0 = registros[0].valor;
	int y1 = registros[DIMENSAO].valor;

// funçao de interpolação linear:
// chave_procurada = x0 + (x1 - x0)*(valor_procurado - y0)
//                        --------------------------------
//                                  (y1 - y0)

	int aux = (x1 - x0) * (valor_procurado - y0); 
	int chave_procurada = x0 + aux / (y1 - y0);

	return chave_procurada;
}

int main(){
	REGISTRO registros[DIMENSAO] = {{2, 20}, {3, 30}, {4, 40}, {5, 50}};
	int chave = buca_interpolacao(registros, 40);

	printf("Coordenada x do valor procurado: %d\n", chave);

	return 0;
}