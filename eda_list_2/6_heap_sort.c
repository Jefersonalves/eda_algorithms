#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 11

void random_numbers(int *heap){

  int index = 1;
  heap[0] = MAX-1;

  do {
    srand(clock());
    heap[index++] = rand() % 100;
  }while (index != MAX);
}

int _left(int index) {
  return 2*index;
}

int _right(int index) {
  return 2*index+1;
}

void heapfy (int *heap, int index) {

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
    heapfy(heap, max);
  }
}

void building_heap (int *heap, int heap_size) {

  int index;
  /*Chama o heapfy pra cada raiz, comecando da ultima*/
  for(index = heap_size; index > 0; index--) {
    heapfy(heap, index);
  }
}

void print_heap (int *heap){

  int index = 0;

  while(index < heap[0]) {
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
    print_heap(heap);
  }
  printf("\n");
}

int main () {

  /*int heap[] = {9, 15, 8, 4, 7, 5, 3, 1, 2, 6};*/
  int heap[MAX] = {10, 16, 4, 10, 14, 7, 9, 3, 2, 8, 1};

/*  random_numbers(heap);*/

  print_heap(heap);
  heapsort(heap);
  print_heap(heap);

  return 0;
}
