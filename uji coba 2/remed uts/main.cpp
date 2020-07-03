#include <iostream>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>

struct barang{      
	int id_produk;
	char nama_produk[20];
	double harga;
};

struct elemen{          
	barang brg;
	struct elemen *next;
};

struct list{                  
	struct elemen *first;
};

void printAllElemen(list L);
void deleteLast(list *L);
elemen *searchData(int cari,list L);
int isEmpty(list *L);


int main() {
	list L;  

	printAllElemen(L);
	searchData(001,L);
	deleteLast(&L);
	
	return 0;
}

void deleteLast(list *L){

	elemen *p = L->first;
	elemen *prev = NULL;
	
		while(p->next!=NULL) {
		prev=p;
		p=p->next;
	}	
	free(p);
	prev->next=NULL;
	
}

void printAllElemen(list L){
	system("cls");
			elemen *p = L.first;
			while(p!=NULL){ 
	
		printf("Data Barang\n");
		printf("Nama Barang	: %s\n",p->brg.nama_produk);
		printf("ID Produk 	: %d\n",p->brg.id_produk);
		printf("Harga 		: %2.2f\n\n",p->brg.harga);
		p=p->next;
		
	}	
}
elemen *searchData(int cari,list L){
	elemen *p = L.first;
	
	while(p!=NULL){
		if(p->brg.id_produk == cari){
			printf("Data Mahasiswa\n");
			printf("Nama Barang 	: %s\n",p->brg.nama_produk);
			printf("ID Produk 	: %d\n",p->brg.id_produk);
			printf("Harga 	: %2.2f\n\n",p->brg.harga);
			p=p->next;
			getch();
		}
		else {
			p=p->next;
		}
	}
}
