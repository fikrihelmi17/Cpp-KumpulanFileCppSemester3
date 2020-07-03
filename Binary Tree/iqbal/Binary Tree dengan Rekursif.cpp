//------------------------------
// Nama : Mohammad Iqbal
// NPM  : 0617104013
// 
// Binary Tree dengan Rekursif
//------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct tree{
	int data;
	tree *kiri;
	tree *kanan;
};

tree *pohon;
tree *SimpulBaru(int data);
void SisipSimpul(tree **pohonz, int data);
void PreOrder(tree *pohonz);
void InOrder(tree *pohonz);
void PostOrder(tree *pohonz);

int main(){
	int pilih, angka;
	char pilih2[5];
	pohon = NULL;
	
	do{
		system("cls");
		printf("===========================\n");
		printf(" Binary Tree \n");
		printf("===========================\n");
		printf(" 1. Tambah simpul\n");
		printf(" 2. Cetak dengan Preorder\n");
		printf(" 3. Cetak dengan Inorder\n");
		printf(" 4. Cetak dengan Postorder\n");
		printf(" 5. Exit\n");
		printf("===========================\n");
		printf(" Pilih menu [1/2/3/4] : "); scanf("%d",&pilih);
		
		switch(pilih){
			case 1:
				do{
					system("cls");
					printf("====================================\n");
					printf(" Tambah Simpul \n");
					printf("====================================\n");
					printf(" Masukkan angka : "); scanf("%d",&angka);
					SisipSimpul(&pohon,angka);
					printf("====================================\n");
					printf(" Tambah lagi? [iya/tidak] : "); scanf("%s",pilih2);
				} while(strcmp(pilih2,"iya")==0);
				break;
			case 2:
				system("cls");
				printf("======================================\n");
				printf(" Cetak dengan Preorder \n");
				printf("======================================\n");
				printf(" Isi pada simpul : ");
				PreOrder(pohon);
				printf("\n======================================\n");
				getch();
				break;
			case 3:
				system("cls");
				printf("====================================\n");
				printf(" Cetak dengan Inorder \n");
				printf("====================================\n");
				printf(" Isi pada simpul : ");
				InOrder(pohon);
				printf("\n======================================\n");
				getch();
				break;
			case 4:
				system("cls");
				printf("====================================\n");
				printf(" Cetak dengan Postorder \n");
				printf("====================================\n");
				printf(" Isi pada simpul : ");
				PostOrder(pohon);
				printf("\n======================================\n");
				getch();
				break;
		}
	} while(pilih >= 1 && pilih <= 4);
}

tree *SimpulBaru(int data){
	tree *B;
	B = new tree;
	B->data = data;
	B->kanan = NULL;
	B->kiri = NULL;
	return B;
}

void SisipSimpul(tree **pohonz, int data){
	if(*pohonz== NULL){
		*pohonz= SimpulBaru(data);
	}else{
		if((*pohonz)->data ==data){
			printf("Data sudah ada\n");
		}else if ((*pohonz)->data<data){
			SisipSimpul(&(*pohonz)->kanan, data);
		}else{
			SisipSimpul(&(*pohonz)->kiri, data);
		}
	}
}

void PreOrder(tree *pohonz){
	if(pohonz!= NULL){
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
