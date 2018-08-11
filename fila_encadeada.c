/* 
 * Autor:  Jock
 * Data:   1/08/2017 
 * Titulo: FilaEncadeada
 *
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int value;
	struct nodo *prox;
} Nodo;

typedef struct queue {
	Nodo *head, *tail;
	int size;
} Queue;

void newQueue(Queue **q) {
	if ( !(*q = malloc(sizeof(Queue))) ) {
		printf("[Error Insufficient Memory] function newQueue.");
		exit(1);
	} else {
		(*q)->head = (*q)->tail = NULL;
		(*q)->size = 0;
	}
}

void addInQueue(Queue **q, int value) {
	Nodo *no;
	
	/*Cria o novo No*/
	if ( !(no = malloc(sizeof(Nodo))) ) {
		printf("[Error isFull Queue] fuction addInQueue.");
		exit(1);
	} else {
		no->value = value;
		no->prox  = NULL;
		(*q)->size++;
	}
	
	/*Adiciona o no a Fila*/
	if ( !(*q)->head ) 
		(*q)->head = (*q)->tail = no;
	else 
		(*q)->tail = (*q)->tail->prox = no;
} 

int deleteInQueue(Queue **q) {
	if ( !(*q)->head ) {
		printf("[Error isEmpty Queue] function deleteInQueue.");
		exit(1);
	} else {
		/*Pegando os campos do head atual*/
		int value 	   = (*q)->head->value;
		Nodo *oldHead  = (*q)->head;
		
		/*Atualiza a cabela para o proximo no && size*/
		(*q)->head 	   = oldHead->prox;
		(*q)->size--;
		
		free(oldHead);
		return value;
	}
}

short isEmpty(Queue **q) {
	return ( !(*q)->head );
}

int getSize(Queue **q) {
	return (*q)->size;
}

void viewQueue(Queue **q) {
	for (Nodo *i = (*q)->head; i != NULL; i = i->prox) 
		printf("%3d -> ", i->value);
	printf("NULL\n");
}




int main() {
	Queue *q;
	newQueue(&q);
	
	for (int i = 0; i < 6; i++)
		addInQueue(&q, i);
	
	viewQueue(&q);
	
	for (int i = 0; i < 2; i++)
		deleteInQueue(&q);
	
	printf("\nSize: %d\n", getSize(&q));
	
	viewQueue(&q);
	
	
	
	return 0;
}
