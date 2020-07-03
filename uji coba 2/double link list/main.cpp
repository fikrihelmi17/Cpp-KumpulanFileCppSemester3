/*Fikri Helmi Setiawan
0617104005*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>

struct mahasiswa{       //rumah nya beserta isi
	char npm[9];
	char nama[50];
	float ipk;
};

struct elemen{             //alamat si rumah
	mahasiswa mhs;
	struct elemen *next;
	struct elemen *before;
}*bantu;

struct list{                    // ngasih alamat ke si satpam
	struct elemen *first;
	struct elemen *last;
};

void printAllFromFirst(list L);
void printAllFromLast(list L);
void addLast(char nim[],char nama[],float ipk, list *L);
void addFirst(char nim[],char nama[],float ipk, list *L);
void addAfter(char cari[],char nim[], char nama[], float ipk, list *L);
void addBefore(char cari[],char nim[], char nama[], float ipk, list *L);
void deleteFirst(list *L);
void deleteAfter(char cari[],list *L);
void deleteBefore(list *L);
void deleteLast(list *L);
elemen *searchData(char cari[],list L);
int countElemen(list L);
int isEmpty(list *L);

int main() {
	list L;
	L.first = NULL;
	L.last = NULL;
	
	
	//addFirst("0617","Fikri",3.7,&L);
	//addFirst("0618","Helmi",3.7,&L);
	//getch();
	//addAfter("0617","0620","Fitri",3.7,&L);
	//getch();
	//addAfter(newEl,"0618","Helmi",3.8,&L);
	//addBefore("0617","0621","Dinda",3.7,&L);
	addLast("0619","Set",3.7,&L);
	addLast("0618","Helmi",3.7,&L);
	//getch();
	
	//countElemen(L);
	//printf("\n\n\n");
	
	printf("Print dari Awal\n");
	printAllFromFirst(L);
	printf("\n\nPrint dari Akhir\n");
	printAllFromLast(L);
	
	getch();
	system("cls");
	
	//searchData("0617",L);
	//deleteFirst(&L);
	//deleteAfter("0619",&L);
	deleteBefore(&L);
	//deleteLast(&L);
	
	
	printf("Print dari Awal\n");
	printAllFromFirst(L);
	printf("\n\nPrint dari Akhir\n");
	printAllFromLast(L);
	
	return 0;
}

void addFirst(char nim[], char nama[],float ipk, list *L)
{
	elemen *newEl=(elemen*)malloc(sizeof(elemen)); 
    strcpy(newEl->mhs.npm,nim);
	strcpy(newEl->mhs.nama,nama);
	newEl->mhs.ipk=ipk;  
    
    if(isEmpty(L)==1) {
    	L->first=newEl;
    	L->last=newEl;
		newEl->next=NULL;
		newEl->before=NULL;	
	} else {
		L->first->before=newEl;
		newEl->next=L->first;
		L->first=newEl;
    	newEl->before=NULL;
	}
}

void addAfter(char cari[], char npm[], char nama[], float ipk, list *L) {
	elemen *newEl = (elemen*)malloc(sizeof(elemen)); 

	strcpy(newEl->mhs.npm, npm); 
	strcpy(newEl->mhs.nama, nama); 
	newEl->mhs.ipk = ipk;
	
	if(isEmpty(L) == 1) {
		L->first = newEl;
		newEl->before = NULL;
		newEl->next = L->last;
		L->last = newEl;
	} else {
		elemen *p = L->first;
		while(p != NULL) {
			if(strcmp(p->mhs.npm, cari) == 0) {
			printf("Data Mahasiswa\n");
			printf("Nama 	: %s\n", nama);
			printf("NPM 	: %s\n", npm);
			printf("IPK 	: %2.2f\n\n", ipk);
			if(p->next == NULL) {
					addLast(npm, nama, ipk, L);
				} else {
					newEl->next = p->next;
					p->next->before = newEl;
					p->next = newEl;
					newEl->before = p;	
			}
		}
		p=p->next;
		}
	}
}

void addBefore(char cari[], char npm[], char nama[], float ipk, list *L) {
	elemen *newEl = (elemen*)malloc(sizeof(elemen)); 

	strcpy(newEl->mhs.npm, npm); 
	strcpy(newEl->mhs.nama, nama); 
	newEl->mhs.ipk = ipk;
	

		elemen *p = L->first;
			if(p->next == NULL) {
					addLast(npm, nama, ipk, L);
				} else {
					newEl->next = p->next;
					p->next->before = newEl;
					p->next = newEl;
					newEl->before = p;	
			}
		
		p=p->before;
		
}


void addLast(char nim[],char nama[],float ipk, list *L){
	
	elemen *newEl =(elemen*)malloc(sizeof(elemen));
	elemen *penunjuk = L->first;
    strcpy(newEl->mhs.npm,nim);
	strcpy(newEl->mhs.nama,nama);
	newEl->mhs.ipk=97;
	
	newEl->next = NULL;
	
	if(isEmpty(L)==1) {
		L->first=newEl;
    	L->last=newEl;
		newEl->next=NULL;
		newEl->before=NULL;	
	} else {
		while (penunjuk->next!=NULL) {
		penunjuk=penunjuk->next;
		}
		penunjuk->next=newEl;
		newEl->before=penunjuk;
		L->last=newEl;
		newEl->next=NULL;
	}
	
	return;
}

void deleteFirst(list *L){
	elemen *p;
	
	if(isEmpty(L)==1) {
		printf("Perintah tidak bisa dilaksanakan. Karna tidak ada data\n\n");		
	} else{
		p = L->first;
		L->first=L->first->next;
		free(p);
		L->first->before=NULL;	
	} 
}

void deleteAfter(char cari[], list *L){
	elemen *bantu;
	elemen *p = L->first;
	while(p!=NULL) {
		if(strcmp(p->mhs.npm,cari) == 0) {
			bantu = p->next;
			p->next = bantu->next;
			bantu->next->before=p;
			free(bantu);
		}
		p = p->next;
	}
}

void deleteBefore(list *L){
	char cari[10];
	strcpy(cari,"0618");
	
	elemen *p = L->first;
	while(p!=NULL) {
		if(strcmp(cari,p->mhs.npm) == 0) {
			elemen *bantu = p->before;
			p->before = bantu->before;	
			bantu->before->next=p;
			free(bantu);	
		}
		p = p->next;
	}
}

void deleteLast(list *L) {
	elemen *p;
	
	if(isEmpty(L)==1) {
		printf("error");
	} else {
		p = L->last;
		L->last = L->last->before;
		free(p);
		L->last->next=NULL;
	}
}


elemen *searchData(char cari[],list L){
	elemen *p = L.first;
	
	if(isEmpty(&L) == 1) {
		printf("error");
	} else {
		while(p!=NULL){
		if(strcmp(p->mhs.npm,cari)==0){
			printf("Data Mahasiswa\n");
			printf("Nama 	: %s\n",p->mhs.nama);
			printf("NPM 	: %s\n",p->mhs.npm);
			printf("IPK 	: %2.2f\n\n",p->mhs.ipk);
			p=p->next;
			getch();
		}
		else {
			p=p->next;
		}
	}
		
  }	
}

int countElemen(list L){
	int hasil = 0;
	if(L.first != NULL){
		elemen *p;
		p = L.first;
		
		while(p != NULL){
			hasil = hasil + 1;
			p = p->next	;
		}
		printf("%d",hasil);
	}
}

int isEmpty(list *L) {
	if(L->first == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void printAllFromFirst(list L){
	
			elemen *p = L.first;
			while(p!=NULL){ 
				printf("Data Mahasiswa\n");
				printf("Nama 	: %s\n",p->mhs.nama);
				printf("NPM 	: %s\n",p->mhs.npm);
				printf("Nilai 	: %2.2f\n\n",p->mhs.ipk);
				p=p->next;
		
	}	
}

void printAllFromLast(list L){
	
			elemen *p = L.last;
			while(p!=NULL){ 
				printf("Data Mahasiswa\n");
				printf("Nama 	: %s\n",p->mhs.nama);
				printf("NPM 	: %s\n",p->mhs.npm);
				printf("Nilai 	: %2.2f\n\n",p->mhs.ipk);
				p=p->before;
		
	}	
}

