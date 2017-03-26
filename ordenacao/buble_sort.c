#include <stdio.h>
#define SIZE 5

// Synthesis:
// Objective: Sort a vector using the Buble Sort algorithm.
// Input: Integer vector.
// Output: Vector ordered.

void read_vector(int vector[]){
// preenche o vector com entrada do usuário
	for(int counter = 0; counter < SIZE; counter++){
		scanf("%d", &vector[counter]);
	}
}

void print_vector(int vector[]){
//make the vector print
	for(int counter = 0; counter < SIZE; counter++){
		printf("%d ", vector[counter]);
	}
	printf("\n");
}

void buble(int vector[]){
//applies the buble sort algorithm to the vector
	int dimension = SIZE;

	do{
		int exchange = 0;
		for(int counter = 0; counter < dimension - 1; counter++){
			if(vector[counter + 1] < vector[counter]){
				int auxiliary = vector[counter];
				vector[counter] = vector[counter + 1];
				vector[counter + 1] = auxiliary;
				exchange++;
			}else{
				//nothing to do
			}
		}
		dimension--;
	}while(exchange);
}

int main(){
	int vector[SIZE];
	read_vector(vector);
	buble(vector);
	print_vector(vector);
	
	return 0;
}