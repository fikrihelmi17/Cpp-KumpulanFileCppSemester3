//Binary Tree

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>

typedef struct Node {
	int value;
	Node *left;
	Node *right;
};

typedef struct {
	Node *root;
}BinaryTree;

void makeTree(int value, BinaryTree *T);
void addRight(int value, BinaryTree **parent);
void addLeft(int value, BinaryTree **parent);
void delLeft(int value, BinaryTree **node); //jika punya child, tidak boleh didelete
void delRight(int value, BinaryTree **node); //jika punya child, tidak boleh didelete
void printTreePreOrder(Node *root);
void printTreePostOrder(Node *root);
void printTreeInOrder(Node *root);
void printTreeLevelOrder(Node *root);
void destroySubTree(BinaryTree **subtree);

int main() {
	BinaryTree T;
	BinaryTree *parent;
	parent = &T;
	
	makeTree(10, &T);
	printf("\n");
	addRight(11, &parent);
	printf("\n");
	addLeft(12, &parent);
	printf("\n");
	printTreePreOrder(T.root);
	return 0;
}

void printTreePreOrder(Node *root){
	if(root!=NULL) {
		printf("%d\n", root->value);
		printTreePreOrder(root->left);
		printTreePreOrder(root->right);
	}
}

void printTreeInOrder(Node *root){
	if(root!=NULL) {
		printTreeInOrder(root->left);
		printf("%d\n", root->value);
		printTreeInOrder(root->right);
	}
}

void printTreePostOrder(Node *root){
	if(root!=NULL) {
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);
		printf("%d\n", root->value);
	}
}

void makeTree(int value, BinaryTree *T) {
	Node *p=(Node *)malloc(sizeof(Node)); //alokasi memori untuk node baru
	
	//inisialisasi anak kiri dan anak kanan sebagai NULL
	T->root = p;
	p->value = value; //memasukkan data ke node tersebut
	p->left = NULL;
	p->right = NULL;
}

void addRight(int value, BinaryTree **parent) {
	Node *newNode; //pointer baru
	Node *p; //pointer penunjuk
	
	//buat node
	newNode = new Node;
	newNode->value=value;
	newNode->left = newNode->right = NULL;
	
	if((*parent)->root==NULL)
		(*parent)->root = newNode;
	else {
		p = (*parent)->root;
		while (p != NULL){
			if(value < p->value) {
				if(p->left)
					p = p->left;
				else {
					p->left = newNode;
					break;
				}
			}
			else if (value > p->value){
				if(p->right)
					p = p->right;
				else {
					p->right = newNode;
					break;
				}
			}
			else {
				printf("Duplikat nilai terdeteksi");
				break;
			}
		}
	}
}

void addLeft(int value, BinaryTree **parent) {
	Node *newNode; //pointer baru
	Node *p; //pointer penunjuk
	
	//buat node
	newNode = new Node;
	newNode->value=value;
	newNode->left = newNode->right = NULL;
	
	if(!(*parent)->root)
		(*parent)->root = newNode;
	else {
		p = (*parent)->root;
		while (p != NULL){
			if(value < p->value) {
				if(p->left)
					p = p->left;
				else {
					p->left = newNode;
					break;
				}
			}
			else if (value > p->value){
				if(p->right)
					p = p->right;
				else {
					p->right = newNode;
					break;
				}
			}
			else {
				printf("Duplikat nilai terdeteksi");
				break;
			}
		}
	}
}

void delLeft(int value, BinaryTree **node) {
	if(value < (*node)->root->value)
		delLeft(value,(*node)->root->left);
	else
		delLeft(value,(*node)->root->right);
}
void delRight(int value, BinaryTree **node) {
	if(value < (*node)->root->value)
		delLeft(value,(*node)->root->left);
	else
		delLeft(value,(*node)->root->right);
}
