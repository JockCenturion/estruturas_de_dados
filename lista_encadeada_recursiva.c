/* 
 * Autor:  Jock
 * Data:   2/08/2017 
 * Titulo: ListaEncadeadaRecursiva
 *
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int value;
	struct no *prox;
}No;

typedef No List;


void newList(List **l) {
	*l = NULL;
}

char isEmptyList(List **l) {
	return (*l == NULL);
}

void clearList(List **l) {
	if(*l) clearList(&(*l)->prox);
	free(*l);
	*l = NULL;
}

void addInList(List **l, int value) {
	if (*l && value > (*l)->value ) {
		addInList(&(*l)->prox, value);
	} else {
		No *no 		= malloc(sizeof(No)); 
		no->value 	= value;
		no->prox  	= *l;
		*l          = no;
	}
}

void deleteInList(List **l, int value) {
	if (*l && value != (*l)->value)
		deleteInList(&(*l)->prox, value);
	else if (*l) {
		No *aux = *l;
		*l = (*l)->prox;
		free(aux);
	}
}

char searchInList(List **l, int value) {
	if (!*l) 						return 0;
	else if ((*l)->value == value)  return 1;
	else 							return searchInList(&(*l)->prox, value);
}

void viewList(List **l) {
	if (*l != NULL) {
		printf("%2d -> ", (*l)->value);
		viewList(&(*l)->prox);
	} else {
		printf("NULL\n");
	}
}


int main() {
	
	return 0;
}



