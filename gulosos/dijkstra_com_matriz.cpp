/*
 * Author: Jock
 * Date: 23/11/2017
 * Algorithm: Dijsktra 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#define INF 100000
#define MAX 6

typedef struct {
	short aberto;
	int ant;
	int dist;	
}No;

/*________________Auxiliares_____________________*/
void viewArray(int mat[][MAX]) { //Motra a Matriz de Adjacencia
	for (int count = 0; count < MAX; count++) {
		for (int count1 = 0; count1 < MAX; count1++){
			printf("%2d", mat[count][count1]);
		}
		printf("\n");
	}
}

void visualizaDistancia(No *arr) {		//Mostra as distancias de cada Vertice
	for (int count = 0; count < MAX; count++) {
		printf("No %d -> [Visitado: %2d | NoAnterior: %2d | MenorDistancia: %6d]\n", count, arr[count].aberto, arr[count].ant, arr[count].dist);
	}			
}


/*____________________Dijsktra____________________________*/
void inicializaDistancias(No *arr, int size) {					// O(n)
	for (int count = 0; count < MAX; count++) {
		arr[count].aberto =  1;
		arr[count].ant    = -1;
		arr[count].dist   = INF;
	}
	
	arr[0].dist = 0;	//vertice 0 é diferenciado
}

short menorDistancia(No *arr, int size) {					 // O(n)
	int dist  = INF;
	int menor = -1;
	
	for (int count = 0; count < size; count++) {
		if ( (dist > arr[count].dist) && (arr[count].aberto) ) {  
			dist  = arr[count].dist;
			menor = count;
		}
	}
	
	return menor;
}

void relaxamento(int mat[][MAX], No *arr, int u, int d) {	//O(1)
	int peso = arr[u].dist + mat[u][d];
	
	if (peso < arr[d].dist) {
		arr[d].dist = peso;
		arr[d].ant  = u;
	}
}


No* dijkstra(int mat[][MAX], int verticeIncial) {		// O(n^2) + O(n) ==> O(n^2)
	//Variaveis Locais
	No *nos = malloc(sizeof(No) * MAX);
	int u, d;
	
	//Inicializa todos os Nos
	inicializaDistancias(nos, MAX);						// O(n)
	
	//Executa o dijkstra
	do {												//O(n) * O(n) = O(N^2)
		u = menorDistancia(nos, MAX);
		if (u != -1) {
			nos[u].aberto = 0;
			
			for (int d = u; d < MAX; d++) {				//O(n)
				if ( (u != d) && (mat[u][d] > 0) ) {
					relaxamento(mat, nos, u, d);		// O(1)
				}
			}	
		}

	} while (u != -1);
	
	return nos;


}

int main() {
	/*int mat[MAX][MAX] = {0, 2, 1, 0, 0,
						 0, 0, 0, 1, 0,
						 0, 0, 0, 3, 0,
						 0, 0, 0, 0, 2,
						 0, 0, 0, 0, 0};*/
						 
	int mat[MAX][MAX] =   {0, 2, 1, 0, 0, 0,
						   0, 0, 0, 1, 0, 0,
						   0, 0, 0, 3, 4, 0,
						   0, 0, 0, 0, 0, 2,
						   0, 0, 0, 0, 0, 2,
						   0, 0, 0, 0, 0, 0,};
	
	
	
	No *dist = dijkstra(mat, 0);
	visualizaDistancia(dist);
	

	return 0;
}









