/* 
 * Autor:  Jock
 * Data:   8/08/2017 
 * Titulo: FilaDuplamenteEncadeada
 *
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int value;
	struct nodo *prox, *ant;
}Nodo;

typedef struct queue {
	Nodo *head, *tail;
	int size;
}Queue;

void newQueue(Queue **queue) {
	if ( !( (*queue = malloc(sizeof(Queue))) ) ) {
		printf("Error.");
		exit(1);
	} else {
		(*queue)->head = (*queue)->tail = NULL;
		(*queue)->size = 0;
	}
}

void addInQueue(Queue **queue, int value) {
	Nodo *no;
	
	if ( !(no = malloc(sizeof(Nodo))) ) {
		printf("Error.");
		exit(1);
	} else {
		no->value = value;
		no->ant   = (*queue)->tail;	
		no->prox  = NULL;	
	}
	
	if ( !(*queue)->head )
		(*queue)->head = (*queue)->tail = no;
	else 
		(*queue)->tail = (*queue)->tail->prox = no;
}

int removeInQueue(Queue **queue) {
	if ( !(*queue)->head ) {
		printf("Error.");
		exit(1);
	} else {
		Nodo *oldHead = (*queue)->head;
		int  value    = oldHead->value;
		
		(*queue)->head       = oldHead->prox;
		if ( (*queue)->head )  (*queue)->head->ant  = NULL;
	
		free(oldHead);
		return value;		
	}
}

void viewQueue(Queue **queue) {
	for (Nodo *count = (*queue)->head; count && (*queue)->head; count = count->prox) {
		printf("|%3d| ->", count->value);
	}
	printf("NULL");
} 


int main() {
	Queue *q;
	newQueue(&q);
	addInQueue(&q, 225);
	addInQueue(&q, 226);
	addInQueue(&q, 227);
	viewQueue(&q);
	return 0;
}
