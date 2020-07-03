//------------------------------
// Nama : Mohammad Iqbal
// NPM  : 0617104013
// 
// Binary Tree dengan Stack
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

struct stack{
	tree *isi;
	stack *next;
};

tree *pohon;
tree *SimpulBaru(int data);
void PUSH(stack **Stack,tree *Tree);
void POP(stack **Stack, tree **Tree);
void BacaStack(stack *STACK);
void SisipSimpul(tree **akar, int data);
void PreOrder(tree *akar);
void InOrder(tree *akar);
void PostOrder(tree *akar);

int main(){
	int pilih, angka;
	char pilih2[5];
	pohon = NULL;
	
	do{
		system("cls");
		printf("===========================\n");
		printf(" Binary Tree (Stack)\n");
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
				printf("====================================\n");
				printf(" Cetak dengan Preorder \n");
				printf("====================================\n");
				printf(" Isi pada simpul : ");
				PreOrder(pohon);
				getch();
				break;
			case 3:
				system("cls");
				printf("====================================\n");
				printf(" Cetak dengan Inorder \n");
				printf("====================================\n");
				printf(" Isi pada simpul : ");
				InOrder(pohon);
				getch();
				break;
			case 4:
				system("cls");
				printf("====================================\n");
				printf(" Cetak dengan Postorder \n");
				printf("====================================\n");
				printf(" Isi pada simpul : ");
				PostOrder(pohon);
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

void PUSH(stack **Stack,tree *Tree){
	stack *baru;
	baru = new stack;
	baru->isi = Tree;
	baru->next = *Stack;
	*Stack = baru;
}

void POP(stack **Stack, tree **Tree){
	if (*Stack !=NULL){
		*Tree = (*Stack)->isi;
		*Stack = (*Stack)->next;
	}
}

void BacaStack(stack *STACK){
	while (STACK != NULL){
		printf("%d ",STACK->isi->data);
		STACK = STACK->next;
	}
}

void SisipSimpul(tree **akar, int data){
	tree *baru, *pNow, *temp;
	baru = SimpulBaru(data);
	if(*akar == NULL){
		*akar = baru;
	}else{
		pNow = *akar;
		temp = *akar;
		while (pNow->data != data && temp != NULL){
			pNow = temp;
			if (pNow->data < data)
			{
				temp = pNow->kanan;
			}
			else{
				temp = pNow->kiri;
			}
		}
		if (pNow->data != data){
			if (pNow->data < data){
				pNow->kanan = baru;
			}
			else{
				pNow->kiri = baru;
			}
		}else{
			printf("Nilai sudah ada\n");
		}
	}
}

void PreOrder(tree *akar){
	stack *Stack;
	tree *Pos;
	Stack = NULL;
	PUSH(&Stack,akar);
	while(Stack !=NULL){
		POP(&Stack,&Pos);
		while(Pos!=NULL){
			printf("%d ",Pos->data);
			if (Pos->kanan != NULL){
				PUSH(&Stack,Pos->kanan);
			}
			Pos = Pos->kiri;
		}
	}
}

void InOrder(tree *akar){
	stack *Stack = NULL;
	tree *Pos = akar;
	bool done = 0;
	
	while(!done){
		if(Pos != NULL){
			PUSH(&Stack,Pos);
			Pos = Pos->kiri;	
		} else {
			if(Stack != NULL){
				POP(&Stack,&Pos);
				printf("%d ",Pos->data);
				Pos = Pos->kanan;
			} else {
				done = 1;
			}
		}
	}
}

void PostOrder(tree *akar){
	stack *Stack, *Out;
	tree *Pos;
	Stack = NULL;
	Out = NULL;
	PUSH(&Stack,akar);
	
	while(Stack != NULL){
		POP(&Stack,&Pos);
		PUSH(&Out,Pos);
		
		if(Pos->kiri != NULL){
			PUSH(&Stack,Pos->kiri);
		}
		if (Pos->kanan != NULL){
			PUSH(&Stack,Pos->kanan);
		}
	}
	
	BacaStack(Out);
}
