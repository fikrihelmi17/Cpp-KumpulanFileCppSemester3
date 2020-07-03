#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct tree{ //inisialisasi struct
	char data[50];
	tree *kiri;
	tree *kanan;
};

struct stack{
	tree *isi;
	stack *next;
};

tree *pohon; //membuat objek


//fungsi push (tambah pada stack)
void PUSH (stack **Stack,tree *Tree){
	stack *baru;
	baru = new stack;
	baru->isi = Tree;
	baru->next = *Stack;
	*Stack = baru;
}

//fungsi pop (hapus pada stack)
void POP(stack **Stack, tree **Tree){
	if (*Stack !=NULL){
		*Tree = (*Stack)->isi;
		*Stack = (*Stack)->next;
	}
}

void BACA_STACK (stack *STACK){
	printf("\nIsi stack : ");
	while (STACK !=NULL){
		printf("%s ",STACK->isi->data);
		STACK = STACK->next;
	}
	printf("\n");
}

tree *BARU (char DATA[]){ //tambah data baru
	tree *B;
	B = new tree;
	strcpy(B->data, DATA);
	B->kanan = NULL;
	B->kiri = NULL;
	return B;
}

void makeTree(tree **akar, char data[]){
 tree *baru, *pNow, *temp;
 baru = BARU(data);
 if(*akar == NULL){
  *akar = baru;
 }else{
  pNow = *akar;
  temp = *akar;
  while (strcmp(pNow->data,data)!=0 && temp != NULL){
   pNow = temp;
   if (strcmp(pNow->data,data)<0)
   {
    temp = pNow->kanan;
   }
   else{
    temp = pNow->kiri;
   }
  }
  if (strcmp(pNow->data,data)!=0){
   if (strcmp(pNow->data,data)<0){
    pNow->kanan = baru;
   }
   else{
    pNow->kiri = baru;
   }
  }else{
   printf("Data sudah ada\n");
  }
 }
}

//fungsi preorder
void PREORDER(tree*Akar){
	stack *Stack;
	tree *Pos;
	Stack = NULL;
	PUSH(&Stack,Akar);
	while(Stack !=NULL){
		POP(&Stack,&Pos);
		while(Pos!=NULL){
			printf("---- %s ----",Pos->data);
			if (Pos->kanan != NULL){
				PUSH(&Stack,Pos->kanan);
			}
			Pos = Pos->kiri;
		}
	}
}

//fungsi inorder
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
				printf("%s ",Pos->data);
				Pos = Pos->kanan;
			} else {
				done = 1;
			}
		}
	}
}

//fungsi postorder
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
	
	BACA_STACK(Out);
}

//fungsi utama
int main(){
	int pilih;
	char angka[50];
	char pilih2[5];
	pohon = NULL;
	
	do{
		system("cls");
		printf(" Binary Tree (Stack)\n");
		printf("\n");
		printf(" 1. Tambah simpul\n");
		printf(" 2. Cetak dengan Preorder\n");
		printf(" 3. Cetak dengan Inorder\n");
		printf(" 4. Cetak dengan Postorder\n");
		printf(" 5. Exit\n");
		printf(" Pilih : "); scanf("%d",&pilih);
		
		switch(pilih){
			case 1:
				do{
					system("cls");
					printf(" Tambah Simpul \n");
					printf("\n");
					printf(" Masukkan angka : "); scanf("%s",&angka);
					makeTree(&pohon,angka);
					printf("====================================\n");
					printf(" Tambah? [y/t] : "); scanf("%s",pilih2);
				} while(strcmp(pilih2,"y")==0); //mengcompare apakah pilih2 itu sama dengan y
				break;
			case 2:
				system("cls");
				printf(" Cetak dengan Preorder \n");
				printf("====================================\n");
				printf(" Isi pada simpul : ");
				PREORDER(pohon);
				getch();
				break;
			case 3:
				system("cls");
				printf(" Cetak dengan Inorder \n");
				printf("====================================\n");
				printf(" Isi pada simpul : ");
				InOrder(pohon);
				getch();
				break;
			case 4:
				system("cls");
				printf(" Cetak dengan Postorder \n");
				printf("====================================\n");
				printf(" Isi pada simpul : ");
				PostOrder(pohon);
				getch();
				break;
		}
	} while(pilih >= 1 && pilih <= 4);
	
}
