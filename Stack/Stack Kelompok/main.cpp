#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 50

struct data{
	int noTiket;
	char nama[100];
	float harga;
};

struct tumpukan{
	data isi[MAX];
	int top;
};

tumpukan stack;

void inisialisasi() {
	stack.top=0;
}

void PUSH(int NOTIKET, char NAMA[100], float HARGA){
	
	if(stack.top != MAX) {
		/*Yang pertama masuk, terakhir keluar
		penonton masuk mengisi dahulu kursi yang paling belakang*/
		stack.isi[stack.top].noTiket = NOTIKET;
		strcpy(stack.isi[stack.top].nama, NAMA);
		stack.isi[stack.top].harga = HARGA;
		stack.top++;
	} else {
		printf("Penonton Penuh\n");
	}
}

void POP() {
	if(stack.top != 0) {
		stack.top--;
	} else {
		printf("Data Kosong\n");
	}
}

void Tampil() {
	printf("\nNO TIKET\tNAMA\t\tHARGA\n");
	for(int i=0; i < stack.top; i++){
		printf("%d\t\t%s\t\t%0.2f\n", stack.isi[i].noTiket, stack.isi[i].nama, stack.isi[i].harga);
	}
}

int main(int argc, char** argv) {
	int pilih;
	int notiket;
	char nama[100];
	float harga;
	
	inisialisasi();
	
	printf("Masukan data\n");
	do {
		printf("Masukkan No Tiket	: "); scanf("%d",&notiket);
		printf("Masukkan Nama		: "); scanf("%s", nama);
		printf("Masukkan Harga		: "); scanf("%f",&harga);
		PUSH(notiket, nama, harga);
		printf("Tekan 1 untuk melanjutkan, tekan 0 untuk keluar : ");
		scanf("%d",&pilih);
	} while (pilih!=0);
	
	Tampil();
	POP();
	Tampil();
	
	
	return 0;
}
