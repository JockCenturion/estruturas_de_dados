/**
  * Algoritmo: Grafos
  * Data: 14/2/2018
  * Autor: Jocknaylson
  *
  */
  

#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.c"



int main() {
	
	
	/* Grafo 1 */
	Fork fork = newFork(5);
	//Adicionando o 0º Vertice
	addInFork(&fork, 0, 1, 2);
	addInFork(&fork, 0, 2, 4);
	addInFork(&fork, 0, 3, 6);
	
	//Adicionando o 1º Vertice
	addInFork(&fork, 1, 0, 2);
	addInFork(&fork, 1, 3, 3);
	addInFork(&fork, 1, 4, 7);

	//Adicionando o 2º Vertice
	addInFork(&fork, 2, 0, 4);
	addInFork(&fork, 2, 4, 9);
	
	//Adicionando o 3º Vertice
	addInFork(&fork, 3, 0, 6);
	addInFork(&fork, 3, 1, 3);
	addInFork(&fork, 3, 4, 1);
	
	//Adicionando o 4º Vertice
	addInFork(&fork, 4, 1, 7);
	addInFork(&fork, 4, 3, 1);
	addInFork(&fork, 4, 2, 9);
	
	viewFork(&fork);
	dijkstra(&fork);
	
	
	
	
   /* Grafo Orientado - 2	
	Fork fork = newFork(4);
	
	//Adicionando o 1º Vertice
	addInFork(&fork, 0, 1, 3);
	addInFork(&fork, 0, 2, 1);
	addInFork(&fork, 0, 3, 2);
	
	//Adicionando o 2º Vertice
	addInFork(&fork, 1, 3, 2);

	//Adicionando o 3º Vertice
	addInFork(&fork, 2, 3, 0);


	//viewFork(&fork);
	dijkstra(&fork);
	
	*/
	


	/* Grafo Orientado - 3
	Fork fork = newFork(6);
	//Adicionando o 1º Vertice
	addInFork(&fork, 0, 2, 1);

	
	//Adicionando o 2º Vertice
	addInFork(&fork, 1, 4, 4);
	
	//Adicionando o 3º Vertice
	addInFork(&fork, 2, 1, 2);
	addInFork(&fork, 2, 4, 2);
	addInFork(&fork, 2, 3, 1);
	
	//Adicionando o 3º Vertice
	addInFork(&fork, 3, 5, 1);
	
	//Adicionando o 3º Vertice
	addInFork(&fork, 4, 5, 3);
	viewFork(&fork);

	dijkstra(&fork);
*/

	
/*	Grafo - 4

	Fork fork = newFork(4);
	
	//Adicionando o 0º Vertice
	addInFork(&fork, 0, 1, 5);
	addInFork(&fork, 0, 3, 2);
	
	addInFork(&fork, 1, 0, 5);
	addInFork(&fork, 1, 2, 4);
	
	addInFork(&fork, 2, 1, 4);
	addInFork(&fork, 2, 3, 3);
	
	addInFork(&fork, 3, 2, 3);
	addInFork(&fork, 3, 0, 2);
	
	viewFork(&fork);
	dijkstra(&fork);
	
	*/
	
	

	


	
	return 0;
}
