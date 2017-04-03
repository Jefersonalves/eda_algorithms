#include <stdio.h>
#define SIZE 20
#define PARTITION 2
#define REASON (SIZE/PARTITION) 

typedef struct record{
	int value;
}RECORD;

typedef struct index{
	int index_position;
	int index_value;
}INDEX;

//realiza busca sequencia dentro do intervalo [first, last]
int sequential_search(RECORD *record, int search, int first, int last){
	for(int count = first; count <= last; count++){
		printf("Searching... %d\n", count);
		if(search == record[count].value){
			return count;
		}
	}
	return -1;
}

//realiza busca no vetor index para diminuir intervalo da busca binária
int indexed_search(RECORD *record, INDEX *index, int search){
	int position;
	for(int count = 0; count <= REASON; count++){
		if(index[count].index_value >= search){
			position = sequential_search(record, search, index[count - 1].index_position, index[count].index_position);
			return position;
		}
	}

	return -1;
}

int main(){
	RECORD record[SIZE];
	INDEX index[REASON + 1];

	//preenche o vetor record
	for(int count = 0; count < SIZE; count++){
		record[count].value = count * 10; //função geradora de valores
		printf("Value: %d\n", record[count].value);
	}

	//preenche o vetor index
	int m = 0;
	for(int i = 0; i < REASON; i++) {
		index[i].index_position = m;
		index[i].index_value = record[m].value;
		m += PARTITION;
		printf("Value position = %d, index_value = %d\n", index[i].index_position, index[i].index_value);
	}
	index[REASON].index_position = SIZE - 1; //ultima posicao de index armazena informacoes da ultima posicao de record
	index[REASON].index_value = record[SIZE-1].value;
	printf("Value position = %d, index_value = %d\n", index[REASON].index_position, index[REASON].index_value);

	int search = 0;
	printf("Search for: ");
	scanf("%d", &search);

	int result = indexed_search(record, index, search);
	printf("Result: %d\n", result);

	return 0;
}