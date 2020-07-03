#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 3

struct data{
	int id;
	char nama[100];
	float ipk;
};

struct queue{
	data isi[MAX];
	int depan;
	int belakang;
};

queue antrian;

void inisialisasi() {
	antrian.depan =  0;
	antrian.belakang = 0;
}

void ADD(int ID, char NAMA[100], float IPK){
	if(antrian.belakang != MAX) {
		antrian.isi[antrian.belakang].id = ID;
		strcpy(antrian.isi[antrian.belakang].nama, NAMA);
		antrian.isi[antrian.belakang].ipk = IPK;
		antrian.belakang++;
	} else {
		printf("Tumpukan Penuh\n");
	}
}

void GESER() {
	for(int i = antrian.depan; i < antrian.belakang; i++){
		antrian.isi[i-1].id = antrian.isi[i].id;
		strcpy(antrian.isi[i-1].nama, antrian.isi[i].nama);
		antrian.isi[i-1].ipk = antrian.isi[i].ipk;
	}
	antrian.depan--;
	antrian.belakang--;
}

void DELETE() {
	if(antrian.depan == antrian.belakang){
		printf("antrian kosong");
	} else {
		antrian.depan++;
		GESER();
	}
}

void Tampil() {
	printf("\nNIM\tNAMA\tIPK\n");
	for(int i=antrian.depan; i < antrian.belakang; i++){
		printf("%d\t%d\t%0.2f\n", 
		antrian.isi[i].id, 
		antrian.isi[i].nama, 
		antrian.isi[i].ipk);
	}
}

int main(int argc, char** argv) {
	int pilih;
	int id;
	char nama[100];
	float ipk;
	
	do {
		printf("\n-------------------------------------------\n");
		printf("1. Add Queue\n");
		printf("2. Delete Queue\n");
		printf("3. Tampil Queue\n");
		printf("0. Keluar\n");
		printf("\n-------------------------------------------\n");
		printf("Pilih : "); scanf("%d", &pilih);
		switch(pilih) {
			case 1 :
				printf("Masukkan NIM	: "); scanf("%d",&id);
				printf("Masukkan NAMA	: "); scanf("%s", &nama);
				printf("Masukkan IPK	: "); scanf("%f",&ipk);
				ADD(id, nama, ipk);
			break;
			case 2 : DELETE(); break;
			case 3 : Tampil(); break;
			case 0 : printf("Keluar dari aplikasi\n"); break;
			default : printf("Pilihan salah"); break;
		}
	} while (pilih!=0);
		
	return 0;
}
