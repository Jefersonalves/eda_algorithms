#include <stdio.h>
#define MAX 10

typedef struct record{
	int key;
	float value;
}record;

typedef struct index{
	int kindex;
	float value;
}INDEX;

void fill_record(record record[]){
	for(int count = 0; count < MAX; count++){
		record[count].key = count; // função geradora de keys
		record[count].value = count * 10; //função geradora de valuees
	}
}

void imprime_record(record record[]){
	for(int count = 0; count < MAX; count++){
		printf("key: %d value: %.2f\n", record[count].key, record[count].value);
	}
}

int sequential_search(record record[], float search, int first, int last){
	for(int count = first; count < last; count++)
		if(search == record[count].value)
			return count;
	return -1;
}

void indexed_search(record record[], INDEX index[], float search){
	int position;
	for(int count = 0; count < MAX/5; count++) {
		if(index[count].value > search){
			position = sequential_search(record, search, index[count - 1].value, index[count].value);
			break;
		}
	}

	printf("Position: %d value: %.2f\n", position, record[position].value);
}

void fill_index (record record[], INDEX index[]){
	int m = 0;

	for(int i = 0; i < MAX/5; i++) {
		index[i].kindex = m;
		index[i].value = record[m].value;
		m+=5;
	}
}

void print_index (INDEX index[]) {
	printf("Tabela de Index\n");
	for(int i = 0; i < MAX/5; i++) {
		printf("K = %d     key = %.2f\n", index[i].kindex, index[i].value);
	}
}

int main(){
	record record[MAX];
	INDEX index[MAX/5];
	float search;

	fill_record(record);
	imprime_record(record);
	fill_index(record, index);
	print_index(index);

	printf("search: ");
	scanf("%f", &search);
	indexed_search(record, index, search);

	return 0;
}