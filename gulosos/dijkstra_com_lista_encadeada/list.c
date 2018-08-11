/**
  * Algoritmo: Lista
  * Data: 14/2/2018
  * Autor: Jocknaylson
  *
  */
  

#include <stdio.h>
#include <stdlib.h>

/* Esta estrutura deverá ser definida fora*/
struct data {
	int value;
	int peso;
};

typedef struct node {					
	struct node *prox;
	struct data *data;
}Node;


typedef struct node* List;
typedef struct data* Data;

void createList(List *list) {
	*list = NULL;
}

void addInList(List *list, Data data) {
	if ((*list) != NULL && data->value > (*list)->data->value) {
		addInList(&(*list)->prox, data);
	} else {
		Node *newNode = malloc(sizeof(Node)); 
		newNode->data = data;
		newNode->prox = *list;
		*list 		  = newNode;
	}
}

Data getData(List *list) {
	return (*list)->data;
}

void viewList(List *list) {
	if ((*list) != NULL) {
		printf("%3d", (*list)->data->value);
		viewList(&(*list)->prox);
	} else {
		printf("  NULL");
	}
}






	/**
 	  *  DICAS
 	  *
 	  * 1) Na hora de alocar a ESTRUTA node, renomei como typedef struct node
 	  *    pois sizeof(List) gera conflito.
 	  */
