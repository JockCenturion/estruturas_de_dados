/**
  * Algoritmo: Grafos
  * Data: 14/2/2018
  * Autor: Jocknaylson
  *
  */
  

#include <stdio.h>
#include <stdlib.h>
#include "grafo.c"
#define INF 10000

typedef struct info {
	short distance, previous;
	char  status;
}Info;


void viewDistances(Info *info, int size) {
	printf("\n\n\t\t______________ DISTANCIAS__________________ \n\n");
	printf("\t\tLegenda: [vertex] = [previous, distance, status]\n\n");
	for (int count = 0; count < size; count++) {
		printf("[%d] = [%2d, %2d, %2d]  ", count, info[count].previous, info[count].distance, info[count].status);
	}
	printf("\n\t\t____________________________________________ \n");
}

void viewMimimumRoad(Fork *fork, Info *info, short previous) {
	if (previous != -1) {
		viewMimimumRoad(fork, info, info[previous].previous);
		printf("%d -> ", previous);
	}
}

void mimimunRoad(Fork *fork, Info *info) {
	printf("\n\n\t\t______________ MENOR ROTA __________________ \n\n");
	viewMimimumRoad(fork, info, (*fork)->size - 1);
	printf("fim");
	printf("\n\t\t____________________________________________ \n");	
}

char vertexIsOpen(Fork *fork, Info *info) {
	short count = 0;
	while (!info[count++].status);
	return !(count > (*fork)->size);
}

short mimimunOpenDistance(Fork *fork, Info *info) { // Escolha o com menor distancia entre os abertos
	
	short mimimunDistance = INF;
	short vertex;
	
	for (short count = 0; count < (*fork)->size; count++) {
		if (mimimunDistance > info[count].distance && info[count].status == 1) {
			mimimunDistance = info[count].distance;
			vertex 			= count;
		}
	}
	
	return vertex;
}

void relaxation(Fork *fork, Info *info, short vertex) { // colocar o predecessor
	
	for (List list = (*fork)->array[vertex]; list != NULL; list = list->prox) {
		
		short adjacent = getData(&list)->value;
		short newPeso  = getData(&list)->peso + info[vertex].distance;
		
		if (newPeso < info[adjacent].distance) {
			info[adjacent].distance = newPeso;
			info[adjacent].previous = vertex;
		}	
	}
}


void dijkstra(Fork *fork) {
	Info vertex[(*fork)->size];
	
	for (short count = 1; count < (*fork)->size; count++) {
		vertex[count].distance = INF;
		vertex[count].previous =  -1;
		vertex[count].status   =   1;
	}
	
	vertex[0].distance =  0;
	vertex[0].previous = -1;
	vertex[0].status   =  1;  
	
	while (vertexIsOpen(fork, vertex)) {
		short mimVertex = mimimunOpenDistance(fork, vertex);	//Menor Distancia dentre os vertices abertos
		relaxation(fork, vertex, mimVertex);					//Pego o menor vertice e calculo a distancia dele para seus adjacentes
		vertex[mimVertex].status = 0;							//Marco como visitado este vertice
	}
	
	viewDistances(vertex, (*fork)->size);
	mimimunRoad(fork, vertex);	
}


