/**
  *
  * Autor: Jock
  * Data: 12/12/2017 1:00h
  * Aplicaçoa: Arvore AVL
  *
  */

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int value, heightL, heightR;
	struct node *left, *right;
}Node;

typedef Node *Tree;

void newTree(Tree *root) {
	*root = NULL;
}

int height(Tree *root) {
	return (!(*root) ? 0 : (*root)->heightL > (*root)->heightR ? (*root)->heightL + 1 : (*root)->heightR + 1);
}

void recalculateHeight(Tree *root) {
	//recalcula a altura do no da esquerda
	(*root)->left->heightL = height(&(*root)->left->left);
	(*root)->left->heightR = height(&(*root)->left->right);

	//recalcula a altura do no da direita
	(*root)->right->heightL = height(&(*root)->right->left);
	(*root)->right->heightR = height(&(*root)->right->right);
	
	//recalcula a altura do no Raiz
	(*root)->heightL = height(&(*root)->left);
	(*root)->heightR = height(&(*root)->right);
}

void singleRotationLeft(Tree *root) {
	Node *oldRoot = *root;
	
	*root = oldRoot->right;
	oldRoot->right = (*root)->left;
	(*root)->left = oldRoot;
}

void singleRotationRight(Tree *root) {
	Node *oldRoot = *root;
	*root = (*root)->left;
	oldRoot->left = (*root)->right;
	(*root)->right = oldRoot;
}

int balancingFactor(Tree *root) {
	return ((*root)->heightR - (*root)->heightL);
}

void rebalancingTree(Tree *root) {
	char fbFather, fbChild;
	
	fbFather = balancingFactor(root);
	
	if (fbFather == 2) {
		
		fbChild = balancingFactor(&(*root)->right);
		
		if (fbChild >= 0) { 		//Rotação Simples a Esquerda
			singleRotationLeft(root);
			recalculateHeight(root); 
		} else {					//Rotaçao Dupla DireitaEsquerda
			singleRotationRight(&(*root)->right);
			singleRotationLeft(root);
			recalculateHeight(root);
		}	
	} 
	
	if (fbFather == -2) {
		
		fbChild = balancingFactor(&(*root)->left);
		
		if (fbChild <= 0) {  //Rotaçao simples a Direita
			singleRotationRight(root);
			recalculateHeight(root);
		} else {			 //Rotação Dupla EsquerdaDireita
			singleRotationLeft(&(*root)->left);
			singleRotationRight(root);
			recalculateHeight(root);
		}
	}
}

void addInTree(Tree *root, int value) {
	if ( !(*root) ) {
		(*root) = malloc(sizeof(Node));
		(*root)->value = value;
		(*root)->left = (*root)->right = NULL;
		(*root)->heightL = (*root)->heightR = 0;
	} else if (value < (*root)->value) {
		addInTree(&(*root)->left, value);
		(*root)->heightL = height(&(*root)->left);
		rebalancingTree(root);
	} else if (value > (*root)->value) {
		addInTree(&(*root)->right, value);
		(*root)->heightR = height(&(*root)->right);
		rebalancingTree(root);
	}
}

void viewTreeInOrder(Tree *root) {
	if ((*root)) {
		viewTreeInOrder(&(*root)->left);
		printf("|%2d%2d%2d| ", (*root)->value, (*root)->heightL, (*root)->heightR);
		viewTreeInOrder(&(*root)->right);
	}
}

int main() {
	Tree root;
	newTree(&root);
	addInTree(&root, 70);
	addInTree(&root, 80);
	addInTree(&root, 78);
	addInTree(&root, 90);
	viewTreeInOrder(&root);
	
	return 0;
}
