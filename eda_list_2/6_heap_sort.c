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

void heapfy (int *heap, int index, int heap_size) {

  int left = _left(index);
  int right = _right(index);
  int max = index;
  int aux;

  if(left <= heap_size && heap[left] > heap[index]) max = left;
  if(right <= heap_size && heap[right] > heap[max]) max = right;
  if(max != index) {
    aux = heap[index];
    heap[index] = heap[max];
    heap[max] = aux;
    heapfy(heap, max, heap_size);
  }
}

void building_heap (int *heap, int heap_size) {

  int index;
  /*Chama o heapfy pra cada raiz, comecando da ultima*/
  for(index = heap_size; index > 0; index--) {
    heapfy(heap, index, heap_size);
  }
}

void print_heap (int *heap){

  int index = 0;

  while(index <= heap[0]) {
    printf("%d ", heap[index++]);
  }
  printf("\n");
}

void heapsort(int *heap) {

  int index = heap[0];
  int aux;

  building_heap(heap, heap[0]);

  printf("\n");
  while(index > 0){
    aux = heap[index];
    heap[index] = heap[1];
    heap[1] = aux;
    building_heap(heap, --index);
  }
  printf("\n");
}

int main () {

  int heap[MAX];

  random_numbers(heap);

  print_heap(heap);
  heapsort(heap);
  print_heap(heap);
  printf("teste");

  return 0;
}
