//------------------------------
// Nama : Mohammad Iqbal
// NPM  : 0617104013
// 
// Binary Search Tree
//------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Node {
	int value;
	Node *left;
	Node *right;
};

struct BinarySearchTree {
	Node *root;
};

Node* makeTree(int value);
void insertNode(int value, BinarySearchTree *T);
void searchNode(int value, BinarySearchTree *T);
void printTreePreOrder(Node *root);
void printTreePostOrder(Node *root);
void printTreeInOrder(Node *root);
void destroySubTree(Node *subtree);

int main(){
	BinarySearchTree T;
	T.root = NULL;
	
	insertNode(4, &T);
	insertNode(2, &T);
	insertNode(5, &T);
	insertNode(3, &T);
	insertNode(1, &T);
	
	printf("=========================");
	printf("\n Binary Search Tree");
	printf("\n=========================");
	printf("\n\n Cetak");
	printf("\n-------------------------");
	printf("\n Print PreOrder  : ");
	printTreePreOrder(T.root);
	printf("\n Print InOrder   : ");
	printTreeInOrder(T.root);
	printf("\n Print PostOrder : ");
	printTreePostOrder(T.root);
	
	printf("\n\n Pencarian");
	printf("\n-------------------------");
	searchNode(10, &T);
	
	printf("\n\n Hapus Tree");
	printf("\n-------------------------");
	destroySubTree(T.root);
	
	return 0;
}

Node* makeTree(int value){
	Node *p = (Node*)malloc(sizeof(Node));
	p->value = value;
	p->left = NULL;
	p->right = NULL;
	
	return p;
}

void insertNode(int value, BinarySearchTree *T)
{
	Node *baru, *pNow, *temp;
	baru = makeTree(value);
	if(T->root == NULL){
		T->root = baru;
	}else{
		pNow = T->root;
		temp = T->root;
		while (pNow->value != value && temp != NULL){
			pNow = temp;
			if (pNow->value < value)
			{
				temp = pNow->right;
			}
			else{
				temp = pNow->left;
			}
		}
		if (pNow->value != value){
			if (pNow->value < value){
				pNow->right = baru;
			}
			else{
				pNow->left = baru;
			}
		}else{
			printf("Nilai sudah ada\n");
		}
	}
}
   
void printTreePreOrder(Node *root){
	if(root != NULL){
		printf("%d", root->value);
		printTreePreOrder(root->left);
		printTreePreOrder(root->right);
	}
}

void printTreePostOrder(Node *root){
	if(root != NULL){
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);
		printf("%d", root->value);
	}
}

void printTreeInOrder(Node *root){
	if(root != NULL){
		printTreeInOrder(root->left);
		printf("%d", root->value);
		printTreeInOrder(root->right);
	}
}

void searchNode(int value, BinarySearchTree *T){
	if(T->root != NULL){
		Node *pNow, *temp;
		pNow = T->root;
		temp = T->root;
		while(pNow->value != value && temp != NULL){
			pNow = temp;
			if(pNow->value == value){
				printf("\n Nilai ditemukan!");
				printf("\n Nilai yang dicari : %d",pNow->value);
				return;	
			}
			
			if(pNow->value < value)
			{
				temp = pNow->right;
			}else{
				temp = pNow->left;
			}
			
			if(temp == NULL){
				printf("\n Nilai tidak ditemukan!");
			}
		}
	}
}

void destroySubTree(Node *subtree) {
	if (subtree == NULL) return; 
  
    destroySubTree(subtree->left); 
    destroySubTree(subtree->right); 
    
    printf("\n Hapus node: %d", subtree->value); 
    free(subtree); 
}
