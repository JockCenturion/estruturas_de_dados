/**
  *
  * Autor: Jock
  * Data: 12/10/2017 10:00h 
  * Aplicaçoa: Busca Binária
  *
  */


#include <stdio.h>
#include <stdlib.h>

/* Recursivo
int bb(int *array, int search, int start, int end) {
	int middle = (start + end) / 2;
	
	if (array[middle] == search) {
		return middle;
	} else if (start >= end) {
		return -1;
	} else if (search > array[middle]) {
		return bb(array, search, middle + 1, end);
	} else {
		return bb(array, search, start, middle - 1);
	}
}*/

//Interativo
int bb(int *array, int search, int start, int end) {
	while (start <= end) {
		int middle = (start + end) / 2;
		
		if (array[middle] == search) {
			return middle;
		} else if (search > array[middle]) {
			start = ++middle;
		} else {
			end = --middle;
		}
	}
	
	return -1;
}


int binarySearch(int *array, int search, int size) {
	return bb(array, search, 0, size);
}


int main() {
	
	int vet[7] = {1, 2, 3, 5, 5, 5, 5};
	printf("vet[%d]\n", binarySearch(vet, 5, 7));
	
	
	
	
	return 0;
}
