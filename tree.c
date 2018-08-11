/**
  *
  * Autor: Jock
  * Data: 12/09/2017 10:00h v1.1
  * Data: 28/12/2017 12:45h v1.2
  * Aplicaçoa: Arvore de Busca Binária
  *
  */

/**
  * Funçoes: criar, inserir, remover, liberar, qtdDeNos,  qtdDeFolhas, qtdDeNosPares, Altura e visualizar
  *
  * Arvore de Busca Binária
  *    
  *      6									     15
  *   4      8				     		10 			 	   20
  * 1   5  7   10		  			8		12		   18   	24
  *								 0	  0	 0    0		16    0    0     0
  *								 		          0   17
  *
 */


#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int value;
	struct node *left, *right;	
}Node; 

typedef Node* Tree;

void newTree(Tree *root) {
	*root = NULL;
}

void addInTree(Tree *root, int value) {
	if ( (*root) == NULL ) {
		*root = malloc(sizeof(Node));
		(*root)->value = value;
		(*root)->left = (*root)->right = NULL;
	} else if ( value < (*root)->value ) {
		addInTree(&(*root)->left, value);
	} else if ( value > (*root)->value ) {
		addInTree(&(*root)->right, value);
	} 
}

short searchInTree(Tree *root, int value) {
	if ( (*root) == NULL ) {
		return 0;
	} else if ( (*root)->value == value) {
		return 1;
	} else if ( (*root)->value > value ) {
		searchInTree(&(*root)->left, value);
	} else if ( (*root)->value < value ) {
		searchInTree(&(*root)->right, value);
	}
}

void viewTreeInOrder(Tree *root) {
	if ( (*root) != NULL ) {
		viewTreeInOrder(&(*root)->left);
		printf("%6d", (*root)->value);
		viewTreeInOrder(&(*root)->right);
	}
}

void viewTreePreOrder(Tree *root) {
	if ( (*root) != NULL ) {
		printf("%6d", (*root)->value);
		viewTreePreOrder(&(*root)->left);
		viewTreePreOrder(&(*root)->right);
	}
}

void viewTreePosOrder(Tree *root) {
	if ( (*root) != NULL ) {
		viewTreePosOrder(&(*root)->left);
		viewTreePosOrder(&(*root)->right);
		printf("%6d", (*root)->value);
	}
}

void freeTree(Tree *root) {
	if ( (*root) != NULL ) {
		freeTree(&(*root)->left);
		freeTree(&(*root)->right);
		free(*root);
		*root = NULL;
	}
}

short nodeCount(Tree *root) {
	return (!(*root)) ? 0 : 1 + nodeCount(&(*root)->left) + nodeCount(&(*root)->right);
}

short leafNodeCount(Tree *root) {
	if ((*root) == NULL) {
		return 0;
	} else {
		return (!(*root)->left && !(*root)->right) +
				 leafNodeCount(&((*root)->left))   +
				 leafNodeCount(&((*root)->right));
	}
}

int pairNodeCount(Tree *root) {
	if ( !(*root) ) {
		return 0;
	} else {
		return !((*root)->value % 2) + pairNodeCount(&(*root)->left) + 
				pairNodeCount(&(*root)->right);
	}
}

short height(Tree *root) {
	if ((*root) == NULL) {
		return -1;
	} if (!(*root)->left && !(*root)->right) {
		return 0;
	} else {
		char leftCount = height(&(*root)->left);
		char rightCount = height(&(*root)->right);
		return (leftCount > rightCount) ? leftCount + 1 : rightCount + 1;
	}
}

Node* lowLeftNode(Tree *root) {						  //auxiliary function (removeInTree)
	if (!(*root)->left) {
		Node *found = *root;
		*root = found->right;
		return found;
	} else {
		return lowLeftNode(&(*root)->left);
	}
}

void removeInTree(Tree *root, int value) {
	if ( (*root) == NULL ) {
		return;
	} else if ((*root)->value == value) {
		Node *exclusion =  *root;
		
		if (!(*root)->left && !(*root)->right) {		//zero son (leaf node)
			*root = NULL;
		} else if ((*root)->left && (*root)->right) {	//two son
			exclusion = lowLeftNode(&(*root)->right);
			(*root)->value = exclusion->value;
		} else {										// one son
			*root = ((*root)->left) ? (*root)->left : (*root)->right;
		}
		free(exclusion);
	} else if ((*root)->value > value) {
		removeInTree(&(*root)->left, value);
	} else if ((*root)->value < value) {
		removeInTree(&(*root)->right, value);
	}
}



int main() {
	
	Tree root;
	newTree(&root);
	addInTree(&root, 15);
	addInTree(&root, 10);
	addInTree(&root, 20);
	addInTree(&root, 8);
	addInTree(&root, 12);
	addInTree(&root, 18);
	addInTree(&root, 24);
	addInTree(&root, 16);
	addInTree(&root, 17);
	//freeTree(&root);
	removeInTree(&root, 15);
	printf("Nos folha: %d\n\n", leafNodeCount(&root));
	printf("Altura: %d\n\n", height(&root));
	printf("Quantidade de Nos: %d\n\n", nodeCount(&root));
	printf("Busca: %d\n\n", searchInTree(&root, 18));
	printf("Em Ordem:");
	viewTreeInOrder(&root);
	

	
	return 0;
}
