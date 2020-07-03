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
};

struct queue{                    // ngasih alamat ke si satpam
	struct elemen *top;
};

void printAllElemen(queue Q);
int isEmpty(queue *Q);
void enqueue(char nim[],char nama[],float ipk, queue *Q);
void dequeue(queue *Q);


int main() {
	queue Q;  
	//Q.top = NULL;
	
	enqueue("1","Dinda",50,&Q);
	enqueue("2","Mayang",50,&Q);
	enqueue("3","Fitri",50,&Q);
	printAllElemen(Q);
	getch();
	
	dequeue(&Q);
	printAllElemen(Q);
	
	return 0;
}


void dequeue(queue *Q){
	elemen *p = Q->top;
	Q->top=(Q->top)->next;
	free(p);
}



void enqueue(char nim[],char nama[],float ipk, queue *Q)
{
	elemen *penunjuk = Q->top;
	elemen *newEl4 =(elemen*)malloc(sizeof(elemen));
	
    strcpy(newEl4->elmt.npm,nim);
	strcpy(newEl4->elmt.nama,nama);
	newEl4->elmt.nilai=97;
	
	
	if(isEmpty(Q)==1) {
		Q->top=newEl4;
		newEl4->next=NULL;
	} else {
		do {
			if(penunjuk->next==NULL) {
				penunjuk->next=newEl4;
				newEl4->next=NULL;		
			}
				penunjuk = penunjuk->next;
		} while(penunjuk!=NULL);
	}
	
}

int isEmpty(queue *Q) {
	if(Q->top == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void printAllElemen(queue Q){
	system("cls");
			elemen *p = Q.top;
			while(p!=NULL){ //selagi p nya nggak menunjukkan kosong, print terus yang dibawah
	
		printf("Data Mahasiswa\n");
		printf("Nama 	: %s\n",p->elmt.nama);
		printf("NPM 	: %s\n",p->elmt.npm);
		printf("Nilai 	: %2.2f\n\n",p->elmt.nilai);
		p=p->next;
		
	}	
}

