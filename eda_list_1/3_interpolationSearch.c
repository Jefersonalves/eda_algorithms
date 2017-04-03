#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500

void fill_array (int *array) {

  int i;
  for (i = 0; i < MAX; i++)
    array[i] = 10*i + 2; //função geradora de valores
}

void print(int *array) {

  int i;
  for(i = 0; i < MAX; i++)
    printf("Posicao: %d Chave: %d\n", i, array[i]);
}

int interpolation_search(int *array, int search_value){

  int left = 0;
  int right = MAX - 1;
  int middle = 0;

  while(left < right) {

    //fórmula para aplicar a interpolacao linear
    middle = left + ((right - left) * (search_value - array[left])) / (array[right] - array[left]);

    printf("middle: %d, left: %d, array[left]: %d, right: %d, array[right]: %d\n", middle, left, array[left], right, array[right]);

    if(middle > right || middle < left){  //caso a chave calculada extrapole os limites do vetor
      return -1;
    }else{ //caso não extrapole, reajustar o intervalo de busca
      if(array[middle] == search_value){
        return middle;
      }else{
        if(array[middle] > search_value){
          right = middle - 1;
        }else{
          left = middle + 1;
        }
      }
    }

  }
  return -1;
}

int main () {

  int search, result;
  int array[MAX];
  clock_t time_start, time_stop;
  double total_time;

  fill_array(array);

  print(array);

  printf("Procurar: " );
  scanf("%d", &search);

  //contagem do tempo de atuação da função de busca binária
  time_start = clock();
  result = interpolation_search(array, search);
  time_stop = clock();

  //imprime resultado da busca
  if(result == -1) printf("Elemeto nao encontrado.\n");
  else printf("Elemento encontrado na posicao %d\nChave: %d\n", result, array[result]);

  //imprime resultado da contagem de tempo
  total_time = ((double)(time_stop - time_start))/CLOCKS_PER_SEC;
  printf("Vetor de %d posicoes - Tempo de Execucao: %f\n", MAX, total_time);
  return 0;
}
