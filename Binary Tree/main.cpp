//Nama : Fikri Helmi Setiawan
//NPM : 0617104005

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct tree {
	int data;
	tree *kiri;
	tree *kanan;
};

tree *pohon;
tree *Baru(int data);
void Simpul(tree **pohonz, int data);
void PreOrder(tree *pohonz);
void InOrder(tree *pohonz);
void PostOrder(tree *pohonz);

tree *Baru(int data){
	tree *baru;
	baru = new tree;
	baru->data = data;
	baru->kanan = NULL;
	baru->kiri = NULL;
	return baru;
}

void Simpul(tree **pohonz, int data){
	if(*pohonz == NULL){
		*pohonz = Baru(data);
	}else{
		if((*pohonz)->data ==data){
			printf("Data Ada\n");
		}else if ((*pohonz)->data<data){
			Simpul(&(*pohonz)->kanan, data);
		}else{
			Simpul(&(*pohonz)->kiri, data);
		}
	}
}

void PreOrder(tree *pohonz){
	if(pohonz != NULL){
		printf("%d ",pohonz->data);
		PreOrder(pohonz->kiri);
		PreOrder(pohonz->kanan);
	}
}

void InOrder(tree *pohonz){
	if(pohonz!= NULL){
		InOrder(pohonz->kiri);
		printf("%d ",pohonz->data);
		InOrder(pohonz->kanan);
	}
}

void PostOrder(tree *pohonz){
	if(pohonz!= NULL){
		PostOrder(pohonz->kiri);
		PostOrder(pohonz->kanan);
		printf("%d ",pohonz->data);
	}
}

int main(){
	int menu, angka;
	char pilih2[5];
	pohon = NULL;
	
	do{
		system("cls");
		printf("1. Tambah simpul\n");
		printf("2. Print Preorder\n");
		printf("3. Print Inorder\n");
		printf("4. Print Postorder\n");
		printf("5. Keluar\n");
		printf("Pilih Menu : "); scanf("%d",&menu);
		
		switch(menu){
			case 1:
				system("cls");
				printf(" Tambah Simpul \n");
				printf(" Masukkan angka : "); scanf("%d",&angka);
				Simpul(&pohon,angka);
				getch();
				break;
			case 2:
				system("cls");
				printf("Print Preorder \n");
				printf("Isinya : ");
				PreOrder(pohon);
				getch();
				break;
			case 3:
				system("cls");
				printf("Print Inorder \n");
				printf("Isinya : ");
				InOrder(pohon);
				getch();
				break;
			case 4:
				system("cls");
				printf("Print Postorder \n");
				printf("Isinya : ");
				PostOrder(pohon);
				getch();
				break;
		}
	} while(menu >= 1 && menu <= 4);
}
