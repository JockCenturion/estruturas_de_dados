/*
 *
 * Author: Jock
 * Date: 11/24/2017
 * Algorithm: Ordinations
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

/* functions auxiliaries */
void swap(int *var1, int *var2) {
	int aux = *var1;
	*var1   = *var2;
	*var2   = aux;
}

void viewArray(int *array, int size) {
	for (int count = 0; count < size; count++) {
		printf("%4d", array[count]);
	}
	
	printf("\n");
}

/* Simple Algorithm */

/* bubbleSort */
void bubbleSort(int *array, int size) {		//O(n^2)
	int flag = 1;
	
	while (flag == 1) {
		
		flag = 0; 
		
		for (int count = 0; count < size - 1; count++) {	
			if (array[count] > array[count + 1]) {
				swap(&array[count], &array[count + 1]);
				flag = 1;
			}	
		}
		
		size -= 1;
	} 
}

/* SelectionSort */
void selectionSort(int *array, int size) {  //O(n^2)
	
	for (int count = 0; count < size - 1; count++) {
		
		int smaller = count;
		
		for (int count1 = count + 1; count1 < size; count1++) {
			if (array[smaller] > array[count1]) {		//ordem decrescente, muda > -> < 
				smaller = count1;
			}
		}
		
		if (count != smaller) {
			swap(&array[smaller], &array[count]);
		}
	}
}

/* InsertionSort */
void insertionSort(int *array, int size) {	//O(n^2)
	for (int count = 0; count < size; count++) {
		int elected = array[count];
		int next    = count - 1;
		
		while ( (next >= 0) && (array[next] > elected) ) {
			array[next + 1] = array[next--];
		}
		
		array[next + 1] = elected;
	}
}

/* Complex Algorithm */

/* ShellSort */
void shellSort(int *array, int size) {
	int jump = (size - 1) / 2;
	
	while (jump > 0) {
		for (int count = jump; count < size; count++) {
			int temp = array[count];
			int next = count - jump;
			
			while ( (next >= 0) && (array[next] > temp) ) {
				array[next + jump] = array[next];
				next -= jump;
			}
			
			array[next + jump] = temp;
		}
		
		jump = jump / 2;
	}
}

/* HeapSort */
void heapMax(int *array, int position, int size) {
	int maxSon = 2 * position + 1;   //first son
	int son    = 2 * position + 2;   //second son
	
	if (son < size) {
		maxSon = (array[son] > array[maxSon]) ? son : maxSon; 
	}
	
	if ( (maxSon < size) && (array[maxSon] > array[position]) ) {
		swap(&array[maxSon], &array[position]);
		heapMax(array, maxSon, size);
	}
}

void heapSort(int *array, int size) {
	for (int count = (size - 1) / 2; count >= 0; count--) {
		heapMax(array, count, size);
	}

	for (int count = size; count > 1; count--) {
		swap(&array[0], &array[count-1]);  // (0, count-1)
		heapMax(array, 0, count-1);		   // (0, count-2) -> heapMax < size 
	}
}

/* MargeSort */
void merge(int *array, int start, int middle, int end) {
	//declaration
	int *temp, start1, start2, count, count2, size;

	//Initialization
	size   = end - start + 1;
	start1 = start;
	start2 = middle + 1;
	temp   = malloc(sizeof(int) * size);
	
	//coding
	for (int count = 0; count < size; count++) {
		if (start1 <= middle && start2 <= end) {
			temp[count] = (array[start1] < array[start2]) ? array[start1++] : array[start2++];
		} else {	
			temp[count] = (start1 > middle) ? array[start2++] : array[start1++];
		}
	}
	
	for (count = 0; count < size; count++) {
		array[start++] = temp[count];
	}
	
	free(temp);
}

void mergeSort(int *array, int start, int end) {
	if (start < end) {
		int middle = (start + end) / 2;
		mergeSort(array, start, middle);
		mergeSort(array, middle + 1, end);
		merge(array, start, middle, end);
	}
}

/* QuickSort */
void quickSort(int *array, int start, int end) {
	int left  = start;
	int right = end;
	int pivot = array[(left + right) / 2];
	
	
	while (left <= right) {
		while (array[left]  <  pivot) left++;
		while (array[right] >  pivot) right--;
		
		if (left <= right) {
			swap(&array[left++], &array[right--]);	
		}
	}
	
	if (left < end) {
		quickSort(array, left, end);
	}
	
	if (right > start) {
		quickSort(array, start, right);
	} 
}


int main() {
	
	int vet[MAX] = {3, 2, 6, 1, 4, 5, 7, 9, 9, 10, 11, 20, 18, 1, 0, 19, 20, 5, 15, 14};
	//int vet[MAX] = {3, 2, 4, 6, 1, 5};
	//int vet[MAX] = {5, 2, 3};
	
	viewArray(vet, MAX);
	
	
	//bubbleSort(vet, MAX);
	//selectionSort(vet, MAX);
	//insertionSort(vet, MAX);
	//shellSort(vet, MAX);
	//heapSort(vet, MAX);
	//mergeSort(vet, 0, MAX - 1);
	//quickSort(vet, 0, MAX - 1);
	viewArray(vet, MAX);
	
	
	return 0;
}
