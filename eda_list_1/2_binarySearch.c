#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct _node {
  int key;
  struct _node *next;
} node;

typedef struct _header {
  node *head;
  node *foot;
  int amount;
} header;

header *create_header () {
  header *new = (header*) malloc(sizeof(header));
  new->head = NULL;
  new->foot = NULL;
  new->amount = 0;

  return new;
}

void insert_node (int key, header *h) {

  node *new = (node*) malloc(sizeof(node));

  new->key = key;

  if(h->head == NULL) {
    h->head = new;
    h->foot = new;
  }

  new->next = h->head;
  h->head = new;
  h->foot->next = h->head;
  h->amount++;

}

void print(header *head) {

  node *l = head->head;
  int i = 0;

  if (l == NULL) return;

  do {
    printf("Posicao: %d Chave: %d\n", i++, l->key);
    l = l->next;
  } while (l != head->head);
}

void fill_list (header *h) {

  int i;

  for (i = MAX-1; i >= 0; i--)
    insert_node(i + MAX, h);
}

node * binary_search(header *h, int key){

 int left = 0;
 int right = h->amount-1;
 int middle = 0, index;
 node *ptr_middle = h->head;

 printf("\nProcurando %d...\n\n", key);

 while(left <= right) {
   middle = left + (right - left)/2;

   /*printf("middle: %d  left: %d   right: %d\n", middle, left, right);*/

   ptr_middle = h->head;
   for(index = 0; index < left; index++) {
     ptr_middle = ptr_middle->next;
   }

   for(index = left; index < middle; index++) {
     ptr_middle = ptr_middle->next;
   }

   if(ptr_middle->key < key) left = middle + 1;
   else if(ptr_middle->key > key) right = middle - 1;
   else if(ptr_middle->key == key) {
     printf("Elemento encontrado na posicao %d\n", middle);
     return ptr_middle;
   }
 }

 return NULL;
}

int main () {

  header *list_header = create_header();
  node *result;
  int search;

  fill_list(list_header);

  print(list_header);

  printf("Procurar: " );
  scanf("%d", &search);

  result = binary_search(list_header, search);
  if(!result) printf("Elemeto nao encontrado.\n");
  else printf("Chave: %d\n", result->key);

  free(result);
  free(list_header);
  return 0;
}
