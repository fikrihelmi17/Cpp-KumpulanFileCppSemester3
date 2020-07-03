#include <iostream>
#include <string.h>

struct mahasiswa {
	int nim;
	char nama[100];
	float ipk;
	mahasiswa *next;
	mahasiswa *back;
};
mahasiswa *head,*baru;

void inisialisasi() {
	head=new mahasiswa;
	head->next = NULL;
	head->back = NULL;
}

void inputData(int NIM, char NAMA[100], float IPK) {
	mahasiswa *pNow;
	
	baru = new mahasiswa;
	baru->nim = NIM;
	strcpy(baru->nama,NAMA);
	baru->ipk = IPK;
	
	if (head->next == NULL){
		head->next = baru;
		baru->next = head;
		head->back = baru;
		baru->back = head;
	} else {
		if(NIM > head->back->nim) {
			head->back->next = baru;
			baru->next = head;
			baru->back = head->back;
			head->back = baru;
		} else {
			pNow = head->next;
			while(NIM > pNow->nim) {
				pNow = pNow->next;
			}
			
			if(pNow == head->next) {
				baru->next = pNow;
				baru->back = head;
				head->next = baru;
				pNow->back = baru;
			} else {
				baru->next = pNow;
				baru->back = pNow->back;
				baru->next->back = baru;
				baru->back->next = baru;
			}
		}
	}
}

void hapusData(int NIM){
	mahasiswa *pNow, *hapus;
	
	if(head->next->nim == NIM){
		if(head->back->nim != NIM) {
			hapus = head->next;
			head->next = hapus->next;
			hapus->next->back = head;
			hapus = NULL;
		} else {
			head->next = NULL;
			head->back=NULL;
		}
	} else {
		hapus = head->next;
		while(hapus->next != head->next && hapus->nim != NIM) {
			pNow = hapus;
			hapus = hapus->next;
		}
		
		if(hapus->nim != NIM) {
			printf("NIM tidak ada");
		} else {
			if (head->back == hapus) {
				hapus = head->back;
				head->back = hapus->back;
				hapus->back->next = head;
				hapus = NULL;
			} else {
				pNow->next = hapus->next;
				hapus->next->back = pNow;
				hapus = NULL;
			}
		}
	}
	
}

void tampil(){
	mahasiswa *pNow;
	
	if(head->next == NULL){
		printf("NIM tidak ada");
	} else {
		pNow = head->next;
		printf("\nNIM\tNama\tIPK\n");
		while(pNow->next != head->next) {
			printf("%d\t%s\t%0.2f\n",pNow->nim,pNow->nama,pNow->ipk);
			pNow=pNow->next;
		}
	}
}

void pencarian(float IPK) {
	mahasiswa *pNow;
	bool found = false;
	
	if(head->next==NULL){
		printf("Tidak ada data");
	} else {
		pNow = head->next;
		printf("\nHASIL PENCARIAN\n");
		while(pNow->next != head->next) {
			if(pNow->ipk == IPK) {
				printf("NIM\t: %d ",pNow->nim);
				printf("NAMA\t: %s ",pNow->nama);
				printf("IPK\t: %0.2f ",pNow->ipk);
				found=true;
			}
			pNow=pNow->next;
		}
		
		if(!found) {
			printf("Tidak ditemukan");
		}
	}
}

float rata(){
	mahasiswa *pNow;
	float sum = 0;
	int i = 0;
	
	if(head->next == NULL) {
		printf("Tidak ada data");
	} else {
		pNow = head->next;
		while(pNow->next != head->next){
			sum = sum+pNow->ipk;
			i++;
			pNow = pNow->next;
		}
	}
	return sum/i;
}

float min(){
	mahasiswa *pNow;
	float min = 9999;
	
	if(head->next == NULL){
		printf("Tidak ada data");
	} else {
		pNow = head->next;
		while(pNow->next != head->next){
			if(min > pNow->ipk){
				min = pNow->ipk;
			}
			pNow = pNow->next;
		}
	}
	return min;
}

float max(){
	mahasiswa *pNow;
	float max = -9999;
	
	if(head->next == NULL) {
		printf("Tidak ada data");
	} else {
		pNow = head->next;
		while(pNow->next != head->next){
			if(max < pNow->ipk){
				max = pNow->ipk;
			}
			pNow=pNow->next;
		}
	}
	return max;
}

int main(int argc, char** argv) {
	int nim, pilih;
	char nama[100]; 
	float ipk;
	
	inisialisasi();
	
	do{
		printf("\n\n1. Add Data Terurut\n");
		printf("2. View Data\n");
		printf("3. Search Data\n");
		printf("4. Delete Data\n");
		printf("5. Rata rata IPK\n");
		printf("6. Min & Max Value\n");
		printf("0. Exit\n");
				
		printf("pilih : "); scanf("%d",&pilih);
		
		switch(pilih){
			case 1 : printf("Masukkan NIM\t: "); scanf("%d",&nim);
					printf("Masukkan Nama\t: "); scanf("%S",nama);
					printf("Masukkan ipk\t: "); scanf("%F",&ipk);
					inputData(nim,nama,ipk);
					break;
			case 2 : tampil(); break;
			case 3 : printf("Masukkan IPK yang dicari : "); scanf("%f",&ipk);
					pencarian(ipk); break;
			case 4 : printf("Masukkan NIM yang akan dihapus\t: "); scanf("%d",&nim);
					hapusData(nim); break;
			case 5 : printf("Rata - rata ipk : %0.2f\n",rata()); break;
			case 6 : printf("Min : %0.2f || Max : %0.2f\n",min(),max()); break;
			case 0 : printf("keluar"); break;
			default : printf("salah");  
		}
		
	}while(pilih!=0);
	
	return 0;
}

