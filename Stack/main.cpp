#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 5

struct data{
	int nim;
	char nama[100];
	float ipk;
};

struct tumpukan{
	data isi[MAX];
	int top;
};

tumpukan stack;

void inisialisasi() {
	stack.top=0;
}

void PUSH(int NIM, char NAMA[100], float IPK){
	if(stack.top != MAX) {
		stack.isi[stack.top].nim = NIM;
		strcpy(stack.isi[stack.top].nama, NAMA);
		stack.isi[stack.top].ipk = IPK;
		stack.top++;
	} else {
		printf("Tumpukan Penuh\n");
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
	printf("\nNIM\tNAMA\tIPK\n");
	for(int i=0; i < stack.top; i++){
		printf("%d\t%d\t%0.2f\n", stack.isi[i].nim, stack.isi[i].nama, stack.isi[i].ipk);
	}
}

int main(int argc, char** argv) {
	int pilih;
	int nim;
	char nama[100];
	float ipk;
	
	inisialisasi();
	
	printf("Masukan data\n");
	do {
		printf("Masukkan NIM	: "); scanf("%d",&nim);
		printf("Masukkan NAMA	: "); scanf("%s", &nama);
		printf("Masukkan IPK	: "); scanf("%f",&ipk);
		PUSH(nim, nama, ipk);
		printf("Tekan 1 untuk melanjutkan, tekan 0 untuk keluar : ");
		scanf("%d",&pilih);
	} while (pilih!=0);
	
	Tampil();
	POP();
	Tampil();
	
	
	return 0;
}
