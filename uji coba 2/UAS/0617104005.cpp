//Nama : Fikri Helmi Setiawan
//NPM : 0617104005

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <cstdlib>

struct Node {
	int harga;
	char barang[20];
	Node *left;
	Node *right;
};

struct BinarySearchTree {
	Node *root;
};

Node* makeTree(int harga);
void insertNode(char barang[20], int harga, BinarySearchTree *T);
void searchNode(char keyword[20], BinarySearchTree *T);
void printTreePreOrder(Node *root);
void printTreePostOrder(Node *root);
void printTreeInOrder(Node *root);
void destroySubTree(Node *subtree);

int main(){
	int pilih;
	char barang[20];
	float harga;
	char cari[20];
	
	BinarySearchTree T;
	T.root = NULL;
	
	do {
		
	printf("Aplikasi CRUD Product\n");
	printf("1. Add Product\n");
	printf("2. Edit Product Price\n");
	printf("3. Delete Product\n");
	printf("4. Search Product\n");
	printf("5. Show All Product (in order)\n");
	printf("\nMenu : "); scanf("%d",&pilih);
	
	switch(pilih) {
		case 1 : 
			printf("\nAdd Product\n");
			printf("\tProduct Name : "); scanf("%s", barang);
			printf("\n\tProduct Price : "); scanf("%f", &harga);
			insertNode(barang, harga, &T);
		break;
		case 2 : 
			printf("\nEdit Product\n");
			printf("\tSearch Product : "); scanf("s", cari);
			searchNode(cari, &T);
			
		break;
		case 3 : 
			printf("\nDelete Product\n");
			printf("\tSearch Product : "); 
			destroySubTree(T.root);
			printf("\n\n>>press any key to home menu");
			getch();
		break;
		case 4 : 
		printf("Search Product : "); scanf("%s", cari);
		searchNode(cari, &T);
		break; 
		case 5 : 
			printf("\nAll Product (In Order Traversing)\n");
			printTreeInOrder(T.root);
			printf("\n\n>>press any key to home menu");
			getch();
		break;
		}
	} while (pilih >= 1 && pilih <= 5);

	return 0;
}

Node* makeTree(char barang[20], int harga){
	Node *baru = (Node*)malloc(sizeof(Node));
	strcpy(baru->barang, barang);
	baru->harga = harga;
	baru->left = NULL;
	baru->right = NULL;
	return baru;
}

void insertNode(char barang[20], int harga, BinarySearchTree *T)
{
	Node *baru, *pNow, *temp;
	baru = makeTree(barang, harga);
	if(T->root == NULL)
		T->root = baru;
	else{
		pNow = T->root;
		temp = T->root;
		while (pNow->harga != harga && temp != NULL){
			pNow = temp;
			if (pNow->harga < harga)
				temp = pNow->right;
			else
				temp = pNow->left;		
		}
		if (pNow->harga != harga){
			if (pNow->harga < harga)
				pNow->right = baru;
			else
				pNow->left = baru;
		}else
			printf("Nilai ada\n");
	}
}

void searchNode(char keyword[20], BinarySearchTree *T){
	if(T->root != NULL){
		Node *pNow, *temp;
		pNow = T->root;
		temp = T->root;
		while(pNow->barang != keyword && temp != NULL){
			pNow = temp;
			if(pNow->barang == keyword){
				printf("\nValue pencarian : %s",pNow->barang);
				printf("\n\tProduct Found ...\n");
				return;	
			}
			if(pNow->barang < keyword)
				temp = pNow->right;
				
			else
				temp = pNow->left;
			
			if(temp == NULL)
				printf("\nProduct tidak ada!\n\n");
			
		}
	}
}

void printTreeInOrder(Node *root){
	if(root != NULL){
		printTreeInOrder(root->left);
		printf("%s", root->barang);
		printf("( %d )", root->harga);
		printf(" - ");
		printTreeInOrder(root->right);
	}
}

void destroySubTree(Node *subtree) {
	if (subtree == NULL) 
		return; 
  
    destroySubTree(subtree->left); 
    destroySubTree(subtree->right); 
    
    //printf("\nHapus : %s", subtree->barang);
    printf("\nHapus : %d", subtree->harga); 
    free(subtree); 
}
