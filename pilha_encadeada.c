/* 
 * Autor:  Jock
 * Data:   10/07/2017 
 * Titulo: PilhaEncadeada
 *
 */


#include <stdio.h>
#include <stdlib.h>


struct no {
	int valor;
	struct no *prox;
};

struct pilha {
	No *topo;
	int indice;
};

void criar(Pilha **p) {
	if (!(*p = malloc(sizeof(Pilha)))) {
		printf("Error in fuction criar\n");
		exit(1);
	} else {
		(*p)->topo 		= NULL;
		(*p)->indice 	= -1;
	}
}

char inserir(Pilha **p, int valor) {
	No *nodo;
	
	if ( !(nodo = malloc(sizeof(No))) ) {
		printf("Error in fuction inserir\n");
		return 0;
	} else {
		nodo->prox  	= (*p)->topo;
		nodo->valor 	= valor;
		(*p)->topo  	= nodo;
		(*p)->indice++;
		return 1; 
	}
}

char vazia(Pilha **p) {
	return ( (*p)->topo == NULL );
}

int remover(Pilha **p) {
	if (vazia(p)) {
		printf("Error in function remover\n");
		exit(1);
	} else {
		No *exc 		= (*p)->topo;
		int inf 		= (*p)->topo->valor;
		(*p)->topo		= (*p)->topo->prox;
		(*p)->indice--;
		
		free(exc);
		return inf;
		
	}
}

void imprimir(Pilha **p) {
	No *count;
	
	if (vazia(p))
		printf("Pilha Vazia!\n");
	else {
		for (count = (*p)->topo; count != NULL; count = count->prox)
			printf("%4d  ==>  ", count->valor);
		printf("NULL");
	}			
}

void liberar(Pilha **p) {
	No *aux = (*p)->topo;
	
	while (aux != NULL) {
		No *temp = aux->prox;
		free(aux);
		aux = temp;
	}
	
	free(*p);
}

int qtdElementos(Pilha **p) {
	return ((*p)->indice + 1);
}

int topoEh(Pilha **p) {
	return ((*p)->topo->valor);
}

char buscar(Pilha **p, int valor) {
	No *count;
	
	for (count = (*p)->topo; count != NULL; count = count->prox)
		if (count->valor == valor)
			return 1;
	return 0;
}

char inverter(Pilha **p) {
	Pilha *aux;
	criar(&aux);
	
	while (!vazia(p)) 
		inserir(&aux, remover(p));
	
	if (vazia(p)) {
		liberar(p);  //liberando a pilha p
		*p = aux;
		return 1;
	} else 
		return 0;
} 


char comparar(Pilha **p1, Pilha **p2) {
	
	if ((*p1)->indice != (*p2)->indice)
		return 0;
	else {
		No *endTop1 = (*p1)->topo;
		No *endTop2 = (*p2)->topo;
		
		while (endTop1 != NULL && endTop2 != NULL) {
			if (endTop1->valor != endTop2->valor)
				return 0;
			
			endTop1 = endTop1->prox;
			endTop2 = endTop2->prox;
		}
	}
	
	return 1;
}


Pilha* mesclar(Pilha **p1, Pilha **p2) {
	No *aux1;
	No *aux2;
	Pilha *p3;
	
	criar(&p3);
	

	if ( (*p1)->indice >= (*p2)->indice ) {
		aux1 = (*p1)->topo;
		aux2 = (*p2)->topo;
	} else {
		aux1 = (*p2)->topo;
		aux2 = (*p1)->topo;
	}

	while (1) {
		
		if (aux1 != NULL) {
			inserir(&p3, aux1->valor);
			aux1 = aux1->prox;
		}
		
		if (aux2 != NULL) {
			inserir(&p3, aux2->valor);
			aux2 = aux2->prox;
		}
			
		if(aux1 == NULL && aux2 == NULL)
			break;
		
	}
	
	inverter(&p3);
	return p3;
}


Pilha* clonar(Pilha **p) {
	Pilha *clone;
	No    *aux;
	
	criar(&clone);
	
	for (aux = (*p)->topo; aux != NULL; aux = aux->prox) 
		inserir(&clone, aux->valor);
	
	inverter(&clone);
	return clone;
	
}


