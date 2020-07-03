#include <iostream>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>

struct mahasiswa{       //rumah nya beserta isi
	char npm[20];
	char nama[20];
	float nilai;
};

struct elemen{             //alamat si rumah
	mahasiswa elmt;
	struct elemen *next;
	//struct elemen *prev;
};

struct stack{                    // ngasih alamat ke si satpam
	struct elemen *top;
};

void printAllElemen(stack S);

void push(char nim[],char nama[],float ipk, stack *S);
void pop(stack *S);
int isEmpty(stack *S);


int main() {
	stack S;  
	S.top = NULL;
	
	
	
	push("1", "Setiawan", 30, &S);	
	push("2", "Fikri", 30, &S);
	push("3", "Helmi", 30, &S);

	printAllElemen(S);
	getch();
	
	pop(&S);
	printAllElemen(S);
	getch();
	
	return 0;
}


void pop(stack *S){
	elemen *p = S->top;
	if(isEmpty(S)==0){
		S->top=(S->top)->next;
		free(p);
		p=NULL;	
	}
}


void push(char nim[], char nama[],float ipk, stack *S)
{
	elemen *newEl5=(elemen*)malloc(sizeof(elemen));
  
    strcpy(newEl5->elmt.npm,nim);
	strcpy(newEl5->elmt.nama,nama);
	newEl5->elmt.nilai=ipk;
    
    if(isEmpty(S)==1) {
    	S->top=newEl5;
		newEl5->next=NULL;	
	} else {
		newEl5->next = S->top;
    	S->top= newEl5;
	}
    
}

int isEmpty(stack *S) {
	if(S->top == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void printAllElemen(stack S){
	system("cls");
			elemen *p = S.top;
			while(p!=NULL){ //selagi p nya nggak menunjukkan kosong, print terus yang dibawah
	
		printf("Data Mahasiswa\n");
		printf("Nama 	: %s\n",p->elmt.nama);
		printf("NPM 	: %s\n",p->elmt.npm);
		printf("Nilai 	: %2.2f\n\n",p->elmt.nilai);
		p=p->next;
		
	}	
}


