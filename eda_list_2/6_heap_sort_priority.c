#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

void random_numbers(int *heap){

  int index = 1;
  heap[0] = MAX-1;

  do {
    srand(clock());
    heap[index++] = rand() % MAX;
  }while (index != MAX);
}

int _left(int index) {
  return 2*index;
}

int _right(int index) {
  return 2*index+1;
}

int parent(int index){
  if(index != 1) return index/2;
  return index;
}

void heapfy_up (int *heap, int index) {

  int aux;

  if(index == 1) return;

  int father = parent(index);
  if(heap[index] > heap[father]){
    aux = heap[index];
    heap[index] = heap[father];
    heap[father] = aux;
    heapfy_up(heap, father);
  }
}

void heapfy_down(int *heap, int index){

  int left = _left(index);
  int right = _right(index);
  int max = index;
  int aux;

  if(left <= heap[0] && heap[left] > heap[index]) max = left;
  if(right <= heap[0] && heap[right] > heap[max]) max = right;
  if(max != index) {
    aux = heap[index];
    heap[index] = heap[max];
    heap[max] = aux;
    heapfy_down(heap, max);
  }
}

void insert(int *heap, int value) {
  heap[0]++;
  heap[heap[0]] = value;
  heapfy_up(heap, heap[0]);
}

void print_heap (int *heap){

  int index = 0;

  while(index <= heap[0]) {
    printf("%3d ", heap[index++]);
  }
  printf("\n");
}

int delete(int *heap){

  int aux;
  aux = heap[1];
  heap [1] = heap[heap[0]];
  heap[0]--;
  heapfy_down(heap, 1);
  return aux;
}

int main () {

  int heap[MAX];
  int vector[MAX];
  int index = 1;
  heap[0] = 0;
  clock_t time_start, time_stop;
  double total_time;
  int cont;

  while(cont < 15) {

    random_numbers(vector);

    printf("Vetor Gerado:   ");
    print_heap(vector);

    time_start = clock();
    while(index <= vector[0]){
      insert(heap, vector[index++]);
    }
    printf("Heap:           ");
    print_heap(heap);

    vector[0] = heap[0];
    index = 1;
    while(heap[0] != 0){
      vector[index++] = delete(heap);
    }
    time_stop = clock();

    printf("Vetor Ordenado: ");
    print_heap(vector);

    total_time = ((double)(time_stop - time_start))/CLOCKS_PER_SEC;
    printf("Vetor de %d posicoes - Tempo de Execucao: %f\n", MAX, total_time);
    cont++;
  }
  return 0;
}
