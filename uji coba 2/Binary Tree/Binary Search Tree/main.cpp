//Binary Search Tree

#include <iostream>
#include <malloc.h>

typedef struct Node {
	int value;
	struct Node *left;
	struct Node *right;
};

typedef struct {
	Node *root;
}BinarySearchTree;

void insertNode(int value, BinarySearchTree *T);
int searchNode(int value, BinarySearchTree *root); //return 1 katemu, 0 tidak ketemu
void printTreePreOrder(BinarySearchTree *root);
void printTreePostOrder(Node *root);
void printTreeInOrder(Node *root);
void printTreeLevelOrder(Node *root);
void removeNode(int value, BinarySearchTree *root);

int main() {
	BinarySearchTree T;
	BinarySearchTree *root;
	root = &T;
	
	insertNode(10,&T);
	insertNode(1,&T);
	insertNode(12,&T);
	insertNode(30,&T);
	insertNode(4,&T);
	printTreeInOrder(T.root);
}

void insertNode(int value, BinarySearchTree *T) {
	Node *newNode; //pointer baru
	Node *p; //pointer penunjuk
	
	//buat node
	newNode = new Node;
	newNode->value=value;
	newNode->left = newNode->right = NULL;
	
	if(T->root==NULL)
		T->root = newNode;
	else {
		p = T->root;
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

int searchNode(int value, BinarySearchTree *root) {
	if(root == NULL || root->root->value == value)
		return root->root;
		
	if(root->root->value < value)
		return searchNode(value, root->root->right);
	
	return searchNode(value, root->root->left);
}

void printTreeInOrder(Node *root) {
	if(root!=NULL) {
		printTreeInOrder(root->left);
		printf("%d\n", root->value);
		printTreeInOrder(root->right);	
	}
}

void printTreePreOrder(Node *root){
	if(root!=NULL) {
		printf(" %d \n", root->value);
		printTreeInOrder(root->left);
		printTreeInOrder(root->right);
	}
}

void printTreePostOrder(Node *root){
	if(root!=NULL) {
		printTreeInOrder(root->left);
		printTreeInOrder(root->right);
		printf(" %d \n", root->value);
	}
}
