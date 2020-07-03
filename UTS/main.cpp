#include <iostream>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>

struct penjualan{       
	char kode[4];
	char nama[20];
	int jumlah;
	double diskon;
	double harga;
};

struct elemen{             
	penjualan barang;
	struct elemen *next;
	struct elemen *before;
};

struct list{                    // ngasih alamat ke si satpam
	struct elemen *first;
	struct elemen *last;
};

void printAllElemen(list L);
void printTotal(list L);
void addFirst(list *L);
void deleteFirst(list *L);
int isEmpty(list *L);

int main() {
	list L;
	L.first = NULL;
	L.last = NULL;
	int pilih;
	
	menu :
	system("cls");
	printf("-------------------------- UTS ALPRO PRAKTEK --------------------------\n");
	printf("1. Tambah Data\n");
	printf("2. Hapus Data\n");
	printf("3. Print Data Terurut Menurut Nama Barang\n");
	printf("4. Print Data Harga Diatas Rata Rata\n");
	printf("5. Print Total Harga\n");
	printf("6. Keluar\n");
	printf("Pilih : "); scanf("%d",&pilih);
	
	if(pilih==1){
		system("cls");
		addFirst(&L);
		getch();
		goto menu;
	} else if (pilih==2){
		system("cls");
		deleteFirst(&L);
		getch();
		goto menu;
	} else if (pilih==3){
		system("cls");
		printAllElemen(L);
		getch();
		goto menu;
	} else if (pilih==4){
		system("cls");
		printRata(L);
		getch();
		goto menu;
	} else if (pilih==5){
		system("cls");
		printTotal(L);
		getch();
		goto menu;
	} else if (pilih==6){
		return 0;
	}
}

void addFirst(list *L)
{
	elemen *newEl=(elemen*)malloc(sizeof(elemen)); 
	float diskon;
	int jml;
	float harga;
	printf("Masukkan Kode : "); scanf("%s",newEl->barang.kode);
	printf("Masukkan Nama Barang : "); scanf("%s",newEl->barang.nama);
	printf("Masukkan Jumlah : "); scanf("%d",&jml);
	newEl->barang.jumlah=jml;
	printf("Masukkan Diskon : "); scanf("%f",&diskon);
	newEl->barang.diskon=diskon;  
	printf("Masukkan Harga : "); scanf("%f",&harga);
	newEl->barang.harga=harga;
		
    if(isEmpty(L)==1) {
    	L->first=newEl;
    	L->last=newEl;
		newEl->next=NULL;
		newEl->before=NULL;	
		//L->last->next=L->first;
	} else {
		L->first->before=newEl;
		newEl->next=L->first;
		L->first=newEl;
    	newEl->before=NULL;
    	//L->last->next=L->first;
	}
}

void deleteFirst(list *L){
	if(isEmpty(L)==1) {
		printf("Perintah tidak bisa dilaksanakan. Karna tidak ada data\n\n");		
	} else{
		elemen *p = L->first;
		
		while(p!=NULL){
			if(p->barang.diskon == 0) {
				free(p);
			}
			p = p->next;
		}
	
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

void printTotal(list L){
	
			elemen *p = L.first;
			float jumlah, diskon;
			
			jumlah = 0;
			int count = 0;
			
			while(p!=NULL){ 
				diskon = ((p->barang.harga * p->barang.jumlah) * p->barang.diskon) / 100;
				jumlah = jumlah+p->barang.harga - diskon;
				count = count + 1;
				p = p->next;
	}	
	float rata = jumlah;
	printf("Harga : %f\n\n",rata);
}

void printAllElemen(list L){
	
			elemen *p = L.first;
			while(p!=NULL){ 
				printf("Data Penjualan Barang\n");
				printf("Kode 	: %s\n",p->barang.kode);
				printf("Nama 	: %s\n",p->barang.nama);
				printf("Jumlah 	: %d\n",p->barang.jumlah);
				printf("Diskon 	: %2.2f\n",p->barang.diskon);
				printf("Harga 	: %2.2f\n",p->barang.harga);
				p=p->next;
		
	}	
}

void printRata (list L){
	
			elemen *p = L.first;
			elemen *pRata = L.first;
			
			float jumlah = 0;
			int count = 0;
			
			while(p!=NULL){
				jumlah = jumlah + p->barang.harga;
				count = count + 1;
				p = p->next;
			}
			
			float rata = jumlah/count;
			printf("\nHarga : %f\n\n", rata);
			
			while(pRata!=NULL){
			if(pRata!=NULL) {
					printf("Data Penjualan Barang\n");
				printf("Kode 	: %s\n",p->barang.kode);
				printf("Nama 	: %s\n",p->barang.nama);
				printf("Jumlah 	: %d\n",p->barang.jumlah);
				printf("Diskon 	: %2.2f\n",p->barang.diskon);
				printf("Harga 	: %2.2f\n",p->barang.harga);
			} 
			pRata=pRata->next;	
		}	
}
