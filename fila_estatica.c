#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/* 
 * Autor:  Jock
 * Data:   18/08/2017 
 * Titulo: Fila Estatica
 *
 */
 
struct queue {
	short *array, length, head, tail, size;
};
  
void newQueue(Queue *q, short length) {
	if ( !(q->array = malloc(length * sizeof(short))) ) {
 		printf("[Error::insufficient memory] function newQueue.");
 		exit(1);
 	}
	q->length = length;
	q->head = q->tail = q->size = 0;
}

short size(Queue *q) {
	return q->size;
}

short isFull(Queue *q) {
	return (q->size == q->length);
} 

short isEmpty(Queue *q) {
	return (!q->size);
} 

void addInQueue(Queue *q, short value) {
	if ( isFull(q) ) {
		printf("[Error queue isFull] function addInQueue.");
		exit(1);
	} 
	q->size++;													
	q->array[q->tail++ % q->length] = value;
}

short removeInQueue(Queue *q) {
	if ( isEmpty(q) ) {
		printf("[Error queue isEmpty] function removeInQueue.");
		exit(1);
	} 
	q->size--;
	return q->array[q->head++ % q->length];
}

void viewQueue(Queue *q) {
	for (int i = q->head; i < q->tail; i++)
		printf("%3d -> ", q->array[i % q->length]);
	printf("NULL\n");
}


