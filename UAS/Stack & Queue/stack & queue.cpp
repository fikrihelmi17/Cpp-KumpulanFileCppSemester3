#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct mahasiswa { //inisialisasi stuct mahasiswa
	char   kode[5]; //disini di deklarasikan variabel yang dibutuhkan
	char   nama[30];
	char   angkatan[20];
	char   jurusan[20];
	char   email[20];
};

struct stack { //karna dua pointer maka inisialisasikan dua pointer
	mahasiswa mhs;
	stack *top;
	stack *bottom;
};

struct queue { //inisialisasi struct queue
	mahasiswa mhs;
	queue *next;
	queue *prev;
};

//dibawah ini adalah inisialisasi fungsi fungsi
void push(char kode[], char nama[], char angkatan[], char jurusan[], char email[]);
void pop();
void printStack(char tipe[]);

void add(char kode[], char nama[], char angkatan[], char jurusan[], char email[]);
void hapus();
void printQueue(char tipe[]);

stack *sHead, *sTail;
queue *qHead, *qTail;


int main(){
	int prg, pilih;
	char   kode[5];
	char   nama[30];
	char   angkatan[20];
	char   jurusan[20];
	char   email[20];
	
	sHead = NULL;
	sTail = NULL;
	qHead = NULL;
	qTail = NULL;
	
	do{
	//menu 
	system("cls");
	printf(" 1. Stack\n");
	printf(" 2. Queue\n");
	printf(" 3. Keluar program\n\n");
	printf(" Pilih : "); scanf("%d", &prg);
	
	switch(prg){
		
		case 1: //ketika case 1 maka keluar menu stack
		do{
			system("cls");
			printf(" Tumpukan (Stack) \n");
			printf(" 1. Tambah mhs\n");
			printf(" 2. Hapus mhs\n");
			printf(" 3. Cetak mhs dari atas\n");
			printf(" 4. Keluar\n");
			printf("==============================\n");
			printf(" Pilih : "); scanf("%d",&pilih);
			
			switch(pilih){
				case 1:
					system("cls");
					printf(" Kode		: "); scanf("%s", kode);
					printf(" Nama     	: "); scanf("%s", nama);
					printf(" Angkatan 	: "); scanf("%s", angkatan);
					printf(" Jurusan   	: "); scanf("%s", jurusan);
					printf(" Email    	: "); scanf("%s", email);
					printf("\n\n");
					push(kode, nama, angkatan, jurusan, email); //diarahkan ke fungsi push
					break;
				case 2:
					system("cls");
					pop();
					getch(); //menunggu enter dari user
					break;
				case 3:
					system("cls");
					printStack("top");
					getch();
					break;
			}
			
		} while(pilih >= 1 && pilih <= 3); //jika diluar jangkauan ini maka program akan berhenti
		break;
	
		case 2:
		do{
			system("cls");
			printf(" Antrian (Queue) \n");
			printf(" 1. Tambah mhs\n");
			printf(" 2. Hapus mhs\n");
			printf(" 3. Cetak mhs dari depan\n");
			printf(" 4. Keluar\n");
			printf("\n\n");
			printf(" Pilih : "); scanf("%d",&pilih);
			
			switch(pilih){
				case 1:
					system("cls");
					printf(" Kode       : "); scanf("%s", kode);
					printf(" Nama     	: "); scanf("%s", nama);
					printf(" Angkatan 	: "); scanf("%s", angkatan);
					printf(" Jurusan   	: "); scanf("%s", jurusan);
					printf(" Email    	: "); scanf("%s", email);
					printf("\n\n");
					add(kode, nama, angkatan, jurusan, email); //diarahkan ke fungsi add
					break;
				case 2:
					system("cls");
					hapus();
					getch();
					break;
				case 3:
					system("cls");
					printQueue("front");
					getch();
					break;
			}
			
		} while(pilih >= 1 && pilih <= 3);
		break;
	  }
	} while(prg >= 1 && prg <= 2);
	
	
	return 0;
}

void push(char kode[], char nama[], char angkatan[], char jurusan[], char email[]){
	stack *p = (stack*)malloc(sizeof(stack));
	
	//memasukkan data ke struct
	strcpy(p->mhs.kode, kode);
	strcpy(p->mhs.nama, nama);
	strcpy(p->mhs.angkatan, angkatan);
	strcpy(p->mhs.jurusan, jurusan);
	strcpy(p->mhs.email, email);
	
	//disini lah bagian push
	if(sHead == NULL) {
		sHead = p;
		p->top = NULL;
		p->bottom = NULL;
		sTail = p;
	} else {
		p->bottom = sHead;
		sHead = p;
		p->bottom->top = p;
		p->top = NULL;
	}
}

//fungsi pop atau menghapus
void pop(){
	stack *p = sHead;
	if(sHead != NULL) {
		printf(" Mahasiswa %s sudah dihapus...", sHead->mhs.nama);
		sHead = p->bottom;
		sHead->top = NULL;
		free(p); //hapus
	}
}

//fungsi print stack
void printStack(char tipe[]){
	printf(" Data Mahasiswa\n");
	printf("===============================================\n");
	printf(" Kode   Nama       Angkatan    Jurusan    Email\n");
	printf("-----------------------------------------------\n");
	if(strcmp(tipe,"top")==0){
		stack *p = sHead;
		while (p != NULL) {
			printf(" %s %-10s %-11s %-9s %s \n", 
				p->mhs.kode, p->mhs.nama, p->mhs.angkatan, p->mhs.jurusan, p->mhs.email); //mengambil data dari struct dan printkan
		    p = p->bottom; //berjalan ke sebelahnya
		}
	}
	printf("===============================================\n");
}

//fungsi add
void add(char kode[], char nama[], char angkatan[], char jurusan[], char email[]){
	queue *p = (queue*)malloc(sizeof(queue));
	
	//memasukkan data ke struct
	strcpy(p->mhs.kode, kode);
	strcpy(p->mhs.nama, nama);
	strcpy(p->mhs.angkatan, angkatan);
	strcpy(p->mhs.jurusan, jurusan);
	strcpy(p->mhs.email, email);
	
	//bagian queue
	if(qHead == NULL) {
		qHead = p;
		p->next = NULL;
		p->prev = NULL;
		qTail = p;
	} else {
		p->prev = qTail;
		qTail = p;
		p->prev->next = p;
		p->next = NULL;
	}
}

void hapus(){
	queue *p = qHead;
	if(qHead != NULL) {
		printf(" Mahasiswa %s sudah dihapus...", qHead->mhs.nama);
		qHead = p->next;
		qHead->prev = NULL;
		free(p);
	}
}

void printQueue(char tipe[]){
	printf(" Data Mahasiswa\n");
	printf("===============================================\n");
	printf(" Kode   Nama       Angkatan    Jurusan    Email\n");
	printf("-----------------------------------------------\n");
	if(strcmp(tipe,"front")==0){
		queue *p = qHead;
		while (p != NULL) {
			printf(" %s %-10s %-11s %-9s %s \n", 
				p->mhs.kode, p->mhs.nama, p->mhs.angkatan, p->mhs.jurusan, p->mhs.email);
		    p = p->next;
		}
	}
	printf("===============================================\n");
}
