// ________________________ ________________
//                         |                |
// ----------------------- | ---------------
// Nama : Mohammad Iqbal   | Entry          |
// NPM  : 0617104013       | Mahasiswa      |
// ----------------------- | ---------------
// ________________________|________________|
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <malloc.h>

struct Mahasiswa{
	char npm[12];
	char nama[30];
	int ipk;      
};

struct Elemen{
	Mahasiswa mhs;
	Elemen *next;      
};

struct List{
	Elemen *first;      
};

void printAllElemen(List L);
Elemen *searchElemen(char npm[], List L);
void addFirst(char nim[], char nama[], float ipk, List *L);
void addAfter (Elemen *prev, char nim[], char nama[], float ipk);
void addLast(char nim[], char nama[], float ipk, List *L);
void deleteFirst(List *L);
void deleteAfter(Elemen *prev);
void deleteLast(List *L);
void sorting(List *L);

int main() {
	int input, inputTb;
	
	do {
		system("cls");
		printf("Aplikasi Entry Data Mahasiswa\n");
		printf("\n1. Create Data Mahasiswa");
		printf("\n2. Hapus Data Mahasiswa");
		printf("\n3. Cetak Data Mahasiswa");
		printf("\n4. Cari Mahasiswa");
		printf("\n5. Exit");
		printf("\n\nInput: "); scanf("%d",&input);
		
		switch(input) {
			case 1:
				do {
					system("cls");
					printf("Create Data Mahasiswa\n");
					printf("\n1. Tambah Diawal");
					printf("\n2. Tambah Setelah");
					printf("\n3. Tambah Diakhir");
					printf("\n4. Kembali");
					printf("\n\nInput: "); scanf("%d",&inputTb);
					
					if(inputTb>=1 && inputTb<=3){
						
					}
				} while(inputTb>=1 && inputTb<=3);
				
				break;
			case 2:
				do {
					system("cls");
					printf("Hapus Data Mahasiswa\n");
					printf("\n1. Hapus Diawal");
					printf("\n2. Hapus Setelah");
					printf("\n3. Hapus Diakhir");
					printf("\n4. Kembali");
					printf("\n\nInput: "); scanf("%d",&inputTb);
				} while(inputTb>=1 && inputTb<=3);
				break;
			case 3:
			case 4:
				break;
		}
	} while(input>=1 && input<=4);
	
	return 0;
}

void printAllElemen(List L) {
	Elemen *p = L.first;
	while (p != NULL) {
		printf("\nData Mahasiswa");
		printf("\n   NPM  : %s\n", p->mhs.npm);
		printf("   Nama : %s\n", p->mhs.nama);
		printf("   IPK  : %d\n", p->mhs.ipk);
	    p = p->next;
	}
}

Elemen *searchElemen(char npm[], List L){
	Elemen *p = L.first;
	while (p != NULL) {
		if(strcmp(p->mhs.npm,npm)==0){
			printf("\n   NPM  : %s\n", p->mhs.npm);
			printf("   Nama : %s\n", p->mhs.nama);
			printf("   IPK  : %d\n", p->mhs.ipk);
		}
		p = p->next;
	}	
}

// Prosedur untuk menambahkan data di awal
void addFirst(char nim[], char nama[], float ipk, List *L) {
	// Buat elemen p untuk menampung data	
	Elemen *p = (Elemen*)malloc(sizeof(Elemen));
	strcpy(p->mhs.npm, nim);
	strcpy(p->mhs.nama, nama);
	p->mhs.ipk = ipk;
	
	// tambah data di awal
	p->next = L->first;
	L->first = p;
}

// Prosedur untuk menambahkan data setelah elemen yang diinputkan
void addAfter (Elemen *prev, char nim[], char nama[], float ipk) {
	// Buat elemen p untuk menampung data	
	Elemen *p = (Elemen*)malloc(sizeof(Elemen));
	strcpy(p->mhs.npm, nim);
	strcpy(p->mhs.nama, nama);
	p->mhs.ipk = ipk;
	
	p->next = prev->next;
	prev->next = p;
}

// Prosedur untuk menambahkan data di akhir
void addLast(char nim[], char nama[], float ipk, List *L) {
	// Buat elemen baru c yang mempunyai tugas untuk cek setiap list
	Elemen *c = L->first;
	
	// Buat elemen p untuk menampung data
	Elemen *p = (Elemen*)malloc(sizeof(Elemen));
	strcpy(p->mhs.npm, nim);
	strcpy(p->mhs.nama, nama);
	p->mhs.ipk = ipk;
	
	// Cek setiap list dengan looping
	do {
		// Cek list yang NULL
		if(c->next==NULL){
			c->next = p;    // list terakhir diarahkan ke list baru
			p->next = NULL; // next list baru di set NULL
		}
		c = c->next;
	} while(c!=NULL);
}

void deleteFirst(List *L) {
	Elemen *p = L->first;
	L->first = p->next;
	free(p);
	p = NULL;
}

void deleteAfter(Elemen *prev) {
	Elemen *p = prev->next;
	prev->next = p->next;
	free(p);
	p = NULL;
}

void deleteLast(List *L) {
	Elemen *q = L->first;
	Elemen *p = q->next;
	
	while(p->next!=NULL) {
		p = p->next;
		q = q->next;
	}
	
	q->next = p->next;
	free(p);
	p = NULL;
	q = NULL;
}

void sorting(List *L){
	
	int counter = 0;
	char tempNIM[12];
	char tempNama[30];
	int ipk;
	
	temp = L->first;
	
	while(temp!=NULL){
	   temp = temp->next;
	   counter++;
	}
	
	temp = L->first;
	
	for(int j=0; j < counter; j++){
	   while(temp->next!=NULL) {
		if(temp->ipk > temp->ipk->next) {
			strcpy(tempNIM, temp->nim);
			strcpy(temp->nim, temp->next->nim);
			strcpy(temp->next->nim, tempNIM);
	
			strcpy(tempNama, temp->nama);
			strcpy(temp->nama, temp->next->nama);
			strcpy(temp->next->nama, tempNama);
		
			tempIPK = temp->ipk;
			temp->ipk = temp->next->ipk;
			temp->next->ipk = tempIPK;	
		}
		else {
			temp = temp->next;
		}
	   }
	   temp = L->first;
	}
}
