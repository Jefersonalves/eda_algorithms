#include <stdio.h>
#define SIZE 4

int circular_binary_search(int *value, int search, int start, int end){
	int middle = 0;
	int right = end + SIZE;
	int left = start;
	
	while(right >= left){
		middle = (right + left)/2;
		if(middle >= SIZE) middle = middle - SIZE;

		printf("middle: %d, left value: %d, right value: %d\n", middle, value[left], value[right - SIZE]);

		if(value[middle] == search){
			return middle;
		}else{
			if(value[middle] > search){
				if(middle - 1 >= SIZE) right = middle - 1 - SIZE;
				else right = middle - 1;
			}else{
				if(middle + 1 >= SIZE) left = middle + 1 - SIZE;
				else left = middle + 1;
			}
		}
	}

	return -1;
}

int main(){

	int value[SIZE] = {300, 400, 150, 205};
	int start = 2;
	int end = 1;

	int search = 0;
	puts("Digite o que procura:");
	scanf("%d", &search);

	int result = circular_binary_search(value, search, start, end);
	printf("result: %d\n", result);
}