// Nama   : Mohammad Iqbal
// NPM	  : 0617104013
// Matkul : Struktur Data dan Algoritma Lanjutan
// Tugas  : Tugas Doubly Circular Linked List

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct Mahasiswa{
	char npm[9];
	char nama[50];
	float ipk;      
};

struct Elemen{
	Mahasiswa mhs;
	Elemen *before;
	Elemen *next;    
};

struct List{
	Elemen *first;    
	Elemen *last;  
};

void addFirst(char npm[], char nama[], float ipk, List *L);
void addLast(char npm[], char nama[], float ipk, List *L);
void addAfter(Elemen *prev, char npm[], char nama[], float ipk, List *L);
void addBefore(Elemen *after, char npm[], char nama[], float ipk, List *L);
void delFirst(List *L);
void delLast(List *L);
void delAfter(Elemen *prev, List *L);
void delBefore(Elemen *after, List *L);
void printAllFromFirst(List L);
void printAllFromLast(List L);
Elemen *searchElemen(char npm[], List L);
int countElemen(List L);
// isEmpty berada dibawah main()

int main() {
	List L;
	Elemen *cari;
	char npm[9];
	
	L.first = NULL;
	L.last = NULL;
	
	// Tambah data
	addFirst("17104013", "Iqbal", 3.8, &L);
	addFirst("17104001", "Rizki", 3.8, &L);
	addFirst("17104012", "Ari", 3.5, &L);
	addLast("17104008", "Syahrul", 3.4, &L);
	addLast("17104007", "Ryan", 3.4, &L);
	
	printf("\n=================================");
	printf("\n Print dari awal");
	printf("\n=================================");
	printAllFromFirst(L);
	printf("\n=================================");
	printf("\n Jumlah elemen: %d", countElemen(L));
	printf("\n");
	
	printf("\n=================================");
	printf("\n Tambah data sebelum dan sesudah");
	printf("\n=================================");
	printf("\n Masukkan NPM: "); scanf("%s", npm);
	cari = searchElemen(npm, L);
	if(cari != NULL){ 
		addAfter(cari,"17104015", "Raissa", 3.65, &L);
		addBefore(cari,"17104011", "Reggy", 3.7, &L);
	} else {
		printf("\n NPM yang dicari tidak ditemukan!\n");
	}
	printf("\n=================================");
	printf("\n Print dari akhir");
	printf("\n=================================");
	printAllFromLast(L);
	printf("\n=================================");
	printf("\n Jumlah elemen: %d", countElemen(L));
	printf("\n");
	
	printf("\n=================================");
	printf("\n Hapus data sebelum dan sesudah");
	printf("\n=================================");
	printf("\n Masukkan NPM: "); scanf("%s", npm);
	cari = searchElemen(npm, L);
	if(cari != NULL){ 
		delAfter(cari, &L);
		delBefore(cari, &L);
		printf("\n=================================");
		printf("\n Data setelah dihapus");
	} else {
		printf("\n NPM yang dicari tidak ditemukan!");
	}
	printf("\n=================================");
	printAllFromFirst(L);
	printf("\n=================================");
	printf("\n Jumlah elemen: %d", countElemen(L));
	
	printf("\n\n=================================");
	printf("\n Hapus data diawal dan diakhir");
	printf("\n=================================");
	delFirst(&L);
	delLast(&L);
	printAllFromLast(L);
	printf("\n=================================");
	printf("\n Jumlah elemen: %d", countElemen(L));
	
	return 0;
}

// Fungsi untuk memeriksa list apakah NULL atau tidak
int isEmpty(List *L) {
	if(L->first == NULL) return 1;
	else return 0;
}

// Fungsi untuk menghitung jumlah list
int countElemen(List L){
	int hasil = 0;
	if(L.first != NULL){
		Elemen *p;
		p = L.first;
		
		while(p != NULL){
			hasil = hasil + 1;
			p = p->next	;
		}
	}
	return hasil;
}

// Cetak list dari awal
void printAllFromFirst(List L) {
	if(isEmpty(&L) == 0) {
		Elemen *p = L.first;
		while (p != NULL) {
			printf("\n Data Mahasiswa");
			printf("\n   NPM  : %s\n", p->mhs.npm);
			printf("   Nama : %s\n", p->mhs.nama);
			printf("   IPK  : %.2f\n", p->mhs.ipk);
		    p = p->next;
		}
	} else {
		printf("\n Tidak ada data");	
	}
}

// Cetak list dari akhir
void printAllFromLast(List L) {
	if(isEmpty(&L) == 0) {
		Elemen *p = L.last;
		while (p != NULL) {
			printf("\n Data Mahasiswa");
			printf("\n   NPM  : %s\n", p->mhs.npm);
			printf("   Nama : %s\n", p->mhs.nama);
			printf("   IPK  : %.2f\n", p->mhs.ipk);
		    p = p->before;
		}
	} else {
		printf("\n Tidak ada data");	
	}
}

// Fungsi untuk mencari data pada list berdasarkan npm
Elemen *searchElemen(char npm[], List L){
	Elemen *p;
	p = L.first;
	
	int i = 1;
	while(p != NULL){
		if(strcmp(npm, p->mhs.npm) == 0){
			return p;
		}
		p = p->next;
	}
}

// Untuk menambah list baru di awal
void addFirst(char npm[], char nama[], float ipk, List *L) {
	// Buat elemen p untuk menampung data	
	Elemen *p = (Elemen*)malloc(sizeof(Elemen));
	strcpy(p->mhs.npm, npm);
	strcpy(p->mhs.nama, nama);
	p->mhs.ipk = ipk;
	
	if(isEmpty(L) == 1) {
		// Dalam kondisi kosong, L first dan last menunjuk ke NULL
		// L first ditunjukkan ke p  ||L->first|| 
		//                                |--------> || p ||
		L->first = p; 
		// L last ditunjukkan ke p
		// ||L->first||               ||L->last||
		//      |--------> || p || <-------|
		L->last = p; 
		// p next dan before ditunjukkan ke NULL
		// ||L->first||               ||L->last||
		//       |-------> || p || <-------|
		//                 |     |
		//      NULL  <----|     |---->  NULL
		p->next = NULL;
		p->before = NULL;
	} else {
		// Kondisi dimana L first dan last menunjuk ke elemen
		// Disini L last tidak digunakan
		// || p ||
		//    ^
		//    |-----|| Elemen existing ||
		// Karna kita tidak tahu elemen nya apa maka dapat diwakilkan dengan L first
		// L first before ditunjukkan ke p
		L->first->before = p;
		// p next ditunjukkan ke elemen yang sudah ada / L first
		// || p || ----------|
		//    ^             \/
		//    |-----|| Elemen existing ||
		p->next = L->first;
		// Karena p sudah menunjuk ke/ terhubung dengan elemen yang sudah ada yang diwakilkan oleh L first
		// Maka sekarang pindahkan L first ke p, karena p yang menjadi elemen awal
		// ||L->first||
		//       |
		//       |--> || p || ----------|
		//               ^             \/
		//               |-----|| Elemen existing ||
		L->first = p;
		// Lalu p before ditunjukkan ke NULL
		// ||L->first||
		//       |
		//       |--> || p || ----------|
		//            |  ^             \/
		//   NULL <---|  |-----|| Elemen existing ||
		p->before = NULL;
	}
}

// Untuk menambahkan list baru di akhir
void addLast(char npm[], char nama[], float ipk, List *L) {
	Elemen *p = (Elemen*)malloc(sizeof(Elemen));
	strcpy(p->mhs.npm, npm);
	strcpy(p->mhs.nama, nama);
	p->mhs.ipk = ipk;
	
	if(isEmpty(L) == 1) {
		L->last = p;
		L->first = p;
		p->next = NULL;
		p->before = NULL;
	} else {
		L->last->next = p;
		p->before = L->last;
		L->last = p;
		p->next = NULL;
	}
}

// Untuk menambahkan list baru setelah list/elemen yang ditentukan
void addAfter(Elemen *prev, char npm[], char nama[], float ipk, List *L) {
	// Buat elemen p untuk menampung data	
	Elemen *p = (Elemen*)malloc(sizeof(Elemen));
	strcpy(p->mhs.npm, npm);
	strcpy(p->mhs.nama, nama);
	p->mhs.ipk = ipk;
	
	if(prev->next == NULL){ // Jika elemen prev berada di paling akhir
		// Maka panggil prosedur addLast untuk melakukan penambahan diakhir
		addLast(npm, nama, ipk, L);
	} else {
		p->next = prev->next;
		prev->next->before = p;
		prev->next = p;
		p->before = prev;
	}
}

// Untuk menambahkan list baru sebelum list/elemen yang ditentukan
void addBefore(Elemen *after, char npm[], char nama[], float ipk, List *L) {
	// Buat elemen p untuk menampung data	
	Elemen *p = (Elemen*)malloc(sizeof(Elemen));
	strcpy(p->mhs.npm, npm);
	strcpy(p->mhs.nama, nama);
	p->mhs.ipk = ipk;
	
	if(after->before == NULL){ // Jika elemen after berada di paling awal
		// Maka panggil prosedur addFirst untuk melakukan penambahan diawal
		addFirst(npm, nama, ipk, L); 
	} else {
		p->before = after->before;
		after->before->next = p;
		after->before = p;
		p->next = after;
	}
}

// Hapus list yang posisinya di awal
void delFirst(List *L) {
	if(isEmpty(L) == 0) {
		Elemen *p = L->first;
		L->first = p->next;
		p->next->before = NULL;
		p->next = NULL;
		free(p);
		p = NULL;
	} else {
		printf("\n Tidak ada data");	
	}
}

// Hapus list yang posisinya di akhir
void delLast(List *L) {
	if(isEmpty(L) == 0) {
		Elemen *p = L->last;
		L->last = p->before;
		p->before->next = NULL;
		p->before = NULL;
		free(p);
		p = NULL;
	} else {
		printf("\n Tidak ada data");	
	}
}

// Hapus list yang posisinya setelah list/elemen yang ditentukan
void delAfter(Elemen *prev, List *L){
	// Penghapusan akan dilakukan jika elemen setelahnya tidak NULL
	if(prev->next != NULL) {
		Elemen *p = prev->next;
		prev->next = p->next;
		// Jika elemen setelahnya NULL yang artinya elemen p berada di paling akhir
		if(p->next == NULL){
			// L->last pindah ke elemen prev
			L->last = prev; 
		} else { // Jika tidak NULL
			// elemen setelah p diarahkan ke elemen prev
			// sehingga tidak ada elemen yang menunjuk ke elemen p
			p->next->before = prev;
			p->next = NULL;
		}
		p->before = NULL;
		free(p);
		p = NULL;
	}
}

// Hapus list yang posisinya setelah list/elemen yang ditentukan
void delBefore(Elemen *after, List *L){
	// Penghapusan akan dilakukan jika elemen sebelumnya tidak NULL
	if(after->before != NULL) {
		Elemen *p = after->before;
		after->before = p->before;
		// Jika elemen sebelumnya NULL yang artinya elemen p berada di paling awal
		if(p->before == NULL){ 
			// L->first pindah ke elemen after
			L->first = after; 
		} else { // Jika tidak 
			// elemen sebelum p diarahkan ke elemen after
			// sehingga tidak ada elemen yang menunjuk ke elemen p
			p->before->next = after; 
			p->before = NULL;
		}
		p->next = NULL;
		free(p);
		p = NULL;
	}
}
