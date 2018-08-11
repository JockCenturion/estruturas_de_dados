
/**
  * Algoritmo: Grafos
  * Data: 14/2/2018
  * Autor: Jocknaylson
  *
  */
  
#include <stdio.h>
#include <stdlib.h>
#include "list.c"

struct fork {
	List *array;
	short *visited, size;
};

typedef struct fork *Fork;

Fork newFork(short size) {
	
	//Allocation
	Fork fork 		= malloc(sizeof(Fork));
	fork->array 	= malloc(size * sizeof(List));
	fork->visited 	= malloc(size * sizeof(short));
	
	//Inicialization
	fork->size = size;

	for (int count = 0; count < size; count++) {
		createList(&fork->array[count]);		//Para cada position do array cria-se uma fila de prioridade (menor no começo)	
		fork->visited[count] = 0;				//Marcando Vertices não visitdos
	}

	return fork;
}

void addInFork(Fork *fork, int vertex, int adjacent, int peso) {
	if ((vertex >= 0 && vertex < (*fork)->size) && (adjacent >= 0 && adjacent < (*fork)->size)) {
		Data data = malloc(sizeof(Data));
		data->value 	= adjacent;
		data->peso 		= peso;
		addInList(&(*fork)->array[vertex], data);
	} else {
		printf("vertex inexist\n");
	}
}

void viewFork(Fork *fork) {
	for (int count = 0; count < (*fork)->size; count++) {
		printf("%d ", count);
		viewList(&(*fork)->array[count]);
		printf("\n");
	}
}



