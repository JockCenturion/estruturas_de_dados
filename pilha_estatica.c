/* 
 * Autor:  Jock
 * Data:   09/07/2017 
 * Titulo: FilaDuplamenteEncadeada
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha{
	int *vet, topo, TAM;
};

void criar(Pilha *p, int TAM) {
	if ( !( p->vet = malloc(TAM * sizeof(int))) ) {
		printf("Error!\n");
		exit(1);
	} else {
		p->topo = -1;
		p->TAM  = TAM;
	}		
}

void inserir(Pilha *p, int valor) {
	if (p->topo == p->TAM - 1) 
		printf("Pilha Cheia");
	else 
		p->vet[++(p->topo)] = valor;
}

void imprimir(Pilha *p) {
	for (int i = p->topo; i >= 0; i--) 
		printf("%5d", p->vet[i]);
}

char vazia(Pilha *p) {
	return (p->topo == -1);
}

int remover(Pilha *p) {
	if (vazia(p)) {
		printf("Pilha Vazia!\n");
		exit(1);
	} else {
		return (p->vet[(p->topo)--]);
	}		
}

int qtdNo(Pilha *p) {
	return (p->topo + 1);
}

int topoEh(Pilha *p) {
	return (p->vet[p->topo]);
}

int buscar(Pilha *p, int valor) {
	for (int i = p->topo; i >= 0; i--) 
		if (p->vet[i] == valor)
			return i;
	return -1;
}

void liberar(Pilha *p) {
	free(p->vet);
	p->topo = -1;
	p->TAM  = -1;
}

void inverter(Pilha *p) {
	int *newVet = NULL;
	
	if ( !(newVet = malloc((p->topo + 1) * sizeof(int))) ) {
		printf("Error!\n");
		exit(1);
	} else {
		for (int i = p->topo; i >= 0; i--)
			newVet[p->topo - i] = p->vet[i];
		
		free(p->vet);	
		p->vet = newVet;
		
	}
}


int main() {
	//Criar uma biblioteca ou chamar as funçoes aqui
	
	return 0;
}


