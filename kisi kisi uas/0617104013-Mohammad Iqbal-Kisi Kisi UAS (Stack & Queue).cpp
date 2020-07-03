
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct barang {
	char   ID[5];
	char   nama[30];
	char   kategori[20];
	int    jumlah;
	double harga;
};

struct stack {
	barang data;
	stack *top;
	stack *bottom;
};

struct queue {
	barang data;
	queue *next;
	queue *prev;
};

struct queueArr {
	barang data[];
	int front;
	int rear;
};

void push(char id[], char nama[], char kategori[], int jumlah, double harga);
void pop();
void printStack(char tipe[]);

void enqueue(char id[], char nama[], char kategori[], int jumlah, double harga);
void dequeue();
void printQueue(char tipe[]);

void enqueueArr(char id[], char nama[], char kategori[], int jumlah, double harga);
void dequeueArr();
void printQueueArr();

stack *sHead, *sTail;
queue *qHead, *qTail;
queueArr qData;

int main(){
	int prg, pilih, jumlah;
	double harga;
	char id[5];
	char nama[30];
	char kategori[20];
	
	sHead = NULL;
	sTail = NULL;
	qHead = NULL;
	qTail = NULL;
	qData.front = 0;
	qData.rear  = 0;
	
	do{
	
	system("cls");
	printf(" Program apa yang akan dicoba?\n");
	printf(" 1. Stack\n");
	printf(" 2. Queue dengan list\n");
	printf(" 3. Queue dengan array\n");
	printf(" 4. Keluar program\n\n");
	printf(" Program [1/2/3] : "); scanf("%d", &prg);
	
	switch(prg){
		
		case 1:
		do{
			system("cls");
			printf("==============================\n");
			printf(" Tumpukan (Stack) \n");
			printf("==============================\n");
			printf(" 1. Tambah data\n");
			printf(" 2. Hapus data\n");
			printf(" 3. Cetak data dari atas\n");
			printf(" 4. Cetak data dari bawah\n");
			printf(" 5. Keluar\n");
			printf("==============================\n");
			printf(" Pilih menu [1/2/3/4] : "); scanf("%d",&pilih);
			
			switch(pilih){
				case 1:
					system("cls");
					printf("============================\n");
					printf(" ID       : "); scanf("%s", id);
					printf(" Nama     : "); scanf("%s", nama);
					printf(" Kategori : "); scanf("%s", kategori);
					printf(" Jumlah   : "); scanf("%d", &jumlah);
					printf(" Harga    : "); scanf("%lf", &harga);
					printf("============================\n");
					push(id, nama, kategori, jumlah, harga);
					break;
				case 2:
					system("cls");
					pop();
					getch();
					break;
				case 3:
					system("cls");
					printStack("top");
					getch();
					break;
				case 4:
					system("cls");
					printStack("bottom");
					getch();
					break;
			}
			
		} while(pilih >= 1 && pilih <= 4);
		break;
	
		case 2:
		do{
			system("cls");
			printf("================================\n");
			printf(" Antrian (Queue) dengan list \n");
			printf("================================\n");
			printf(" 1. Tambah data\n");
			printf(" 2. Hapus data\n");
			printf(" 3. Cetak data dari depan\n");
			printf(" 4. Cetak data dari belakang\n");
			printf(" 5. Keluar\n");
			printf("================================\n");
			printf(" Pilih menu [1/2/3/4] : "); scanf("%d",&pilih);
			
			switch(pilih){
				case 1:
					system("cls");
					printf("============================\n");
					printf(" ID       : "); scanf("%s", id);
					printf(" Nama     : "); scanf("%s", nama);
					printf(" Kategori : "); scanf("%s", kategori);
					printf(" Jumlah   : "); scanf("%d", &jumlah);
					printf(" Harga    : "); scanf("%lf", &harga);
					printf("============================\n");
					enqueue(id, nama, kategori, jumlah, harga);
					break;
				case 2:
					system("cls");
					dequeue();
					getch();
					break;
				case 3:
					system("cls");
					printQueue("front");
					getch();
					break;
				case 4:
					system("cls");
					printQueue("rear");
					getch();
					break;
			}
			
		} while(pilih >= 1 && pilih <= 4);
		break;
		
		case 3:
		do{
			system("cls");
			printf("================================\n");
			printf(" Antrian (Queue) dengan array \n");
			printf("================================\n");
			printf(" 1. Tambah data\n");
			printf(" 2. Hapus data\n");
			printf(" 3. Cetak data\n");
			printf(" 4. Keluar\n");
			printf("================================\n");
			printf(" Pilih menu [1/2/3] : "); scanf("%d",&pilih);
			
			switch(pilih){
				case 1:
					system("cls");
					printf("============================\n");
					printf(" ID       : "); scanf("%s", id);
					printf(" Nama     : "); scanf("%s", nama);
					printf(" Kategori : "); scanf("%s", kategori);
					printf(" Jumlah   : "); scanf("%d", &jumlah);
					printf(" Harga    : "); scanf("%lf", &harga);
					printf("============================\n");
					enqueueArr(id, nama, kategori, jumlah, harga);
					break;
				case 2:
					system("cls");
					dequeueArr();
					getch();
					break;
				case 3:
					system("cls");
					printQueueArr();
					getch();
					break;
			}
			
		} while(pilih >= 1 && pilih <= 3);	
		break;
	}
	
	} while(prg >= 1 && prg <= 3);
	
	return 0;
}

void push(char id[], char nama[], char kategori[], int jumlah, double harga){
	stack *p = (stack*)malloc(sizeof(stack));
	strcpy(p->data.ID, id);
	strcpy(p->data.nama, nama);
	strcpy(p->data.kategori, kategori);
	p->data.jumlah = jumlah;
	p->data.harga  = harga;
	
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

void pop(){
	stack *p = sHead;
	if(sHead != NULL) {
		printf(" Data %s sudah dihapus...", sHead->data.nama);
		sHead = p->bottom;
		sHead->top = NULL;
		free(p);
	}
}

void printStack(char tipe[]){
	printf("===============================================\n");
	printf(" Data Barang\n");
	printf("===============================================\n");
	printf(" ID   Nama       Kategori    Jumlah    Harga\n");
	printf("-----------------------------------------------\n");
	if(strcmp(tipe,"top")==0){
		stack *p = sHead;
		while (p != NULL) {
			printf(" %s %-10s %-11s %-9d %.f \n", 
				p->data.ID, p->data.nama, p->data.kategori, p->data.jumlah, p->data.harga);
		    p = p->bottom;
		}
	} else if(strcmp(tipe,"bottom")==0) {
		stack *p = sTail;
		while (p != NULL) {
			printf(" %s %-10s %-11s %-9d %.f \n", 
				p->data.ID, p->data.nama, p->data.kategori, p->data.jumlah, p->data.harga);
		    p = p->top;
		}	
	}
	printf("===============================================\n");
}

void enqueue(char id[], char nama[], char kategori[], int jumlah, double harga){
	queue *p = (queue*)malloc(sizeof(queue));
	strcpy(p->data.ID, id);
	strcpy(p->data.nama, nama);
	strcpy(p->data.kategori, kategori);
	p->data.jumlah = jumlah;
	p->data.harga  = harga;
	
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

void dequeue(){
	queue *p = qHead;
	if(qHead != NULL) {
		printf(" Data %s sudah dihapus...", qHead->data.nama);
		qHead = p->next;
		qHead->prev = NULL;
		free(p);
	}
}

void printQueue(char tipe[]){
	printf("===============================================\n");
	printf(" Data Barang\n");
	printf("===============================================\n");
	printf(" ID   Nama       Kategori    Jumlah    Harga\n");
	printf("-----------------------------------------------\n");
	if(strcmp(tipe,"front")==0){
		queue *p = qHead;
		while (p != NULL) {
			printf(" %s %-10s %-11s %-9d %.f \n", 
				p->data.ID, p->data.nama, p->data.kategori, p->data.jumlah, p->data.harga);
		    p = p->next;
		}
	} else if(strcmp(tipe,"rear")==0) {
		queue *p = qTail;
		while (p != NULL) {
			printf(" %s %-10s %-11s %-9d %.f \n", 
				p->data.ID, p->data.nama, p->data.kategori, p->data.jumlah, p->data.harga);
		    p = p->prev;
		}	
	}
	printf("===============================================\n");
}

void enqueueArr(char id[], char nama[], char kategori[], int jumlah, double harga){
	strcpy(qData.data[qData.rear].ID, id);
	strcpy(qData.data[qData.rear].nama, nama);
	strcpy(qData.data[qData.rear].kategori, kategori);
//	qData.data[qData.rear].jumlah = jumlah;
//	qData.data[qData.rear].harga = harga;
	qData.rear++;
}

void dequeueArr(){
	if(qData.front == qData.rear){
		printf("Tidak ada data...");
	} else {
		qData.front++;
		for(int i = qData.front; i < qData.rear; i++){
			strcpy(qData.data[i-1].ID,qData.data[i].ID);
			strcpy(qData.data[i-1].nama,qData.data[i].nama);
			strcpy(qData.data[i-1].kategori,qData.data[i].kategori);
			qData.data[i-1].jumlah = qData.data[i].jumlah;
			qData.data[i-1].harga = qData.data[i].harga;
		}
		qData.front--;
		qData.rear--;
	}
}

void printQueueArr(){
	if(qData.front == qData.rear){
		printf("Tidak ada data...");
	} else {
		printf("===============================================\n");
		printf(" Data Barang\n");
		printf("===============================================\n");
		printf(" ID   Nama       Kategori    Jumlah    Harga\n");
		printf("-----------------------------------------------\n");
		for(int i = qData.rear; i < qData.rear; i++){
			printf(" %s %-10s %-11s %-9d %.f \n", 
				qData.data[i].ID , qData.data[i].nama, qData.data[i].kategori, qData.data[i].jumlah, qData.data[i].harga);
		}
		printf("===============================================\n");	
	}
}
