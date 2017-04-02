#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500

void fill_array (int *array) {

  int i;
  for (i = 0; i < MAX; i++)
    array[i] = i + MAX;
}

void print(int *array) {

  int i;
  for(i = 0; i < MAX; i++)
    printf("Posicao: %d Chave: %d\n", i, array[i]);
}


int binary_search(int *array, int key){

 int left = 0;
 int right = MAX - 1;
 int middle = 0, cont = 0;

 printf("\nProcurando %d...\n\n", key);

 while(left <= right) {
   middle = left + (right - left) * ((key - array[left])/(array[right] - array[left]));

   /*printf("middle: %d  left: %d   right: %d\n", middle, left, right);*/

   if(array[middle] < key) left = middle + 1;
   else if(array[middle] > key) right = middle - 1;
   else if(array[middle] == key) return middle;
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

  time_start = clock();
  result = binary_search(array, search);
  time_stop = clock();
  if(result == -1) printf("Elemeto nao encontrado.\n");
  else printf("Elemento encontrado na posicao %d\nChave: %d\n", result, array[result]);

  total_time = ((double)(time_stop - time_start))/CLOCKS_PER_SEC;
  printf("Vetor de %d posicoes - Tempo de Execucao: %f\n", MAX, total_time);
  return 0;
}
