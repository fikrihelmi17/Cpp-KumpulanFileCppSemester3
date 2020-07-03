//Nama : Fikri Helmi Setiawan
//NPM : 0617104005

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
	
	insertNode(5, &T);
	insertNode(3, &T);
	insertNode(4, &T);
	
	printf("---------- Print ----------\n");
	printf("\nPrint Pre Order  : ");
	printTreePreOrder(T.root);
	printf("\nPrint In Order   : ");
	printTreeInOrder(T.root);
	printf("\nPrint Post Order : ");
	printTreePostOrder(T.root);
	
	printf("\n\n\n---------- Pencarian ----------");
	searchNode(3, &T);
	
	printf("\n\n\n---------- Hapus ----------");
	destroySubTree(T.root);
	
	return 0;
}

Node* makeTree(int value){
	Node *baru = (Node*)malloc(sizeof(Node));
	baru->value = value;
	baru->left = NULL;
	baru->right = NULL;
	return baru;
}

void insertNode(int value, BinarySearchTree *T)
{
	Node *baru, *pNow, *temp;
	baru = makeTree(value);
	if(T->root == NULL)
		T->root = baru;
	else{
		pNow = T->root;
		temp = T->root;
		while (pNow->value != value && temp != NULL){
			pNow = temp;
			if (pNow->value < value)
				temp = pNow->right;
			else
				temp = pNow->left;		
		}
		if (pNow->value != value){
			if (pNow->value < value)
				pNow->right = baru;
			else
				pNow->left = baru;
		}else
			printf("Nilai ada\n");
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
				printf("\nValue pencarian : %d",pNow->value);
				printf("\tValue ditemukan!");
				return;	
			}
			if(pNow->value < value)
				temp = pNow->right;
			else
				temp = pNow->left;
			
			if(temp == NULL)
				printf("\nValue tidak ada!");
			
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

void printTreeInOrder(Node *root){
	if(root != NULL){
		printTreeInOrder(root->left);
		printf("%d", root->value);
		printTreeInOrder(root->right);
	}
}

void printTreePostOrder(Node *root){
	if(root != NULL){
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);
		printf("%d", root->value);
	}
}


void destroySubTree(Node *subtree) {
	if (subtree == NULL) 
		return; 
  
    destroySubTree(subtree->left); 
    destroySubTree(subtree->right); 
    
    printf("\nHapus : %d", subtree->value); 
    free(subtree); 
}
