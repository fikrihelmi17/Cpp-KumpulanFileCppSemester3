/*
Fikri Helmi      			0617104005               
Deni Hadiya AKmala             0617103009
Rudy Krisandi
*/

#include <iostream>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct mahasiswa{       //rumah nya beserta isi
	char npm[20];
	char nama[20];
	char nilai[20];
};

struct elemen{             //alamat si rumah
	mahasiswa elmt;
	struct elemen *next;
} *akhir=NULL,*bantu;

struct list{                    // ngasih alamat ke si satpam
	struct elemen *first;
};

void printAllElemen(list L);
void addLast(char nim[],char nama[],float ipk, list *L);
void addFirst(list *L);
void addAfter(elemen *prev,char nim[], char nama[], float ipk, list *L);
void deleteFirst(list *L);
void deleteAfter(elemen *prev, list *L);
void deleteLast(list *L);
elemen searchData(char cari[],list L);


int main()
{
	list L; //ini dia satpamnya	
	elemen *newEl, *newEl2, *newEl3; //membuat mandor
	newEl = (elemen *) malloc (sizeof(elemen)); //mandor buatin rumah
	strcpy(newEl->elmt.npm,"0617104010"); //masukin elemen ke rumah
	strcpy(newEl->elmt.nama,"Udin"); //masukin elemen ke rumah
	//newEl->elmt.nilai=90;
	L.first=newEl;
	
	newEl2 = (elemen *) malloc (sizeof(elemen)); //bikin rumah kedua
	strcpy(newEl2->elmt.npm,"0617104011");
	strcpy(newEl2->elmt.nama,"Fikri");
	//newEl2->elmt.nilai=100;
	newEl->next=newEl2; //rumah 1 ngasih tau rumah kedua
	
	
	newEl3 = (elemen *) malloc (sizeof(elemen)); //bikin rumah ketiga
	strcpy(newEl3->elmt.npm,"0617104012");
	strcpy(newEl3->elmt.nama,"Helmi");
	//newEl3->elmt.nilai=85;
	newEl2->next=newEl3; //rumah kedua ngasih tau rumah ketiga

	newEl3->next=NULL; //rumah ketiga nunjukin kosong
	
	
   int choice;
   do{  
   		super_menu: 
		   system("cls"); 	
    	printf("||===============================================||\n");
    	printf("||         Aplikasi Entry Data Mahasiswa         ||\n");
    	printf("||-----------------------------------------------||\n");
    	printf("|| (1). Create Data Mahasiswa                    ||\n");
    	printf("|| (2). Hapus  Data Mahasiswa                    ||\n");
    	printf("|| (3). Cetak  Data Mahasiswa                    ||\n");
    	printf("|| (4). Cari   Data Mahasiswa                    ||\n");
    	printf("|| (5). To exit                                  ||\n");
    	printf("||===============================================||\n");
    	printf("\n\nPilih : "); scanf("%d",&choice);
    
		switch (choice){
    	case 1:
        	 system("cls");
        	 int pilih;
        	 do{			 
       			printf("||===============================================||\n");
    			printf("||         Aplikasi Entry Data Mahasiswa         ||\n");
    			printf("||-----------------------------------------------||\n");
    			printf("|| (1). Tambah Diawal                            ||\n");
    			printf("|| (2). Tambah Setelah                           ||\n");
    			printf("|| (3). Tambah Diakhir                           ||\n");
    			printf("|| (4). Kembali                                  ||\n");
    			printf("||===============================================||\n");
    			printf("\n\nPilih : "); scanf("%d",&pilih);
    		
				switch (pilih){
    			case 1:
      				system("cls");
         			addFirst(&L);                   
       				getch();
       				goto super_menu;
      				break;
     			case 2:
        			system("cls");
         			addAfter(newEl2,"0617104040", "Fitri", 73, &L);                    
        			getch();
        			goto super_menu;
       				break;
      			case 3:
					system("cls");
        			addLast("0617102018","Dinda",50,&L);                    
      				getch();
      				goto super_menu;
       				break;
      			case 4:        
         			system("cls");
        			//printf("Exit Program");
        			goto super_menu;
         			break;
      			default: printf("salah input");
      			}
				}while(choice != 4);
   				
				printf(" Terimakasih");
   				getch();	
      case 2:
        system("cls");	
        	 int pilih2;
        	 do{
			 		 
       			printf("||===============================================||\n");
    			printf("||         Aplikasi Entry Data Mahasiswa         ||\n");
    			printf("||-----------------------------------------------||\n");
    			printf("|| (1). Hapus Diawal                            ||\n");
    			printf("|| (2). Hapus Setelah                           ||\n");
    			printf("|| (3). Hapus Diakhir                           ||\n");
    			printf("|| (4). Kembali                                  ||\n");
    			printf("||===============================================||\n");
    			printf("\n\nPilih : "); scanf("%d",&pilih2);
    			switch (pilih2){
    			case 1:
      				system("cls");
         			deleteFirst(&L);                    
       				getch();
       				goto super_menu;
      				break;
     			 case 2:
        			system("cls");
         			deleteAfter(newEl, &L);                   
        			getch();
        			goto super_menu;
       				break;
      			case 3:
					system("cls");
        			deleteLast(&L);                    
      				getch();
      				goto super_menu;
       				break;
      			case 4:        
         			system("cls");
        			//printf("Exit Program");
        			goto super_menu;
         			break;
      			default: printf("salah input");
      			}
				}while(choice != 4);
   				
				printf("\nTerimakasih");
   				getch();	
         	
      case 3:
         system("cls");
         printf("(3). Cetak  Data Mahasiswa                    \n");
         printAllElemen(L);
         getch();
         goto super_menu;
         break;
      case 4:
	   	system("cls");
        printf("(4). Cari   Data Mahasiswa                   \n");
        searchData("0617104012",L);
        break;
      case 5:        
         system("cls");
         printf("Exit Program");
         break;
      default: printf("salah input");
      }
	}while(choice != 5);
   
   printf("\nTerimakasih");
   getch();
   
   return 0;
}

void deleteAfter(elemen *prev, list *L){
	elemen *p; 
	elemen *bantu;
	
	p=prev->next;
	bantu=p->next;
	
	free(p);
	
	prev->next=bantu;
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
void deleteFirst(list *L){
	elemen *p = L->first;
	L->first=(L->first)->next;
	free(p);
}

void addAfter(elemen *prev,char nim[], char nama[], float ipk, list *L){
	elemen *newEl6 = (elemen *)malloc(sizeof(elemen));
	
	system("cls");
	printf("\nTambah Data\n");
    printf("===========\n\n");
    strcpy(newEl6->elmt.npm,nim);
	strcpy(newEl6->elmt.nama,nama);
	//newEl6->elmt.nilai=ipk;
	
	newEl6->next=prev->next;
	prev->next=newEl6;
}

void addLast(char nim[],char nama[],float ipk, list *L)
{
	elemen *penunjuk = L->first;
	elemen *newEl4 =(elemen*)malloc(sizeof(elemen));
    system("cls");
    printf("\nTambah Data\n");
    printf("===========\n\n");
    strcpy(newEl4->elmt.npm,nim);
	strcpy(newEl4->elmt.nama,nama);
	//newEl4->elmt.nilai=97;
	printf("===== periksa =====\n");
	do {
		if(penunjuk->next==NULL) {
			penunjuk->next=newEl4;
			newEl4->next=NULL;		
		}
		penunjuk = penunjuk->next;
	} while(penunjuk!=NULL);
}

void addFirst(list *L)
{
	elemen *newEl5=(elemen*)malloc(sizeof(elemen));
    system("cls");
    printf("\nTambah Data\n");
    printf("===========\n\n"); 
    printf("\nNIM		: "); scanf("%s",newEl5->elmt.npm);
    printf("\nNama		: "); scanf("%s",newEl5->elmt.nama);
	printf("\nIPK		: "); scanf("%s",newEl5->elmt.nilai); //ku abdi di ubah ka string heula, lamun deni bisa ubah ka floatnya
	
    
	newEl5->next=L->first;
    L->first=newEl5;
    
    printf("\n\nData berhasil dimasukkan...");
    printf("\n>> Kembali ke menu awal");
}

void printAllElemen(list L){
	system("cls");
		elemen *p = L.first;
		while(p!=NULL){ //selagi p nya nggak menunjukkan kosong, print terus yang dibawah
	
		printf("Data Mahasiswa\n");
		printf("Nama 	: %s\n",p->elmt.nama);
		printf("NPM 	: %s\n",p->elmt.npm);
		printf("Nilai 	: %2.2f\n\n",p->elmt.nilai);
		p=p->next;
		
	}	
}

elemen searchData(char cari[],list L){
	elemen *p = L.first;
	
	while(p!=NULL){
		if(strcmp(p->elmt.npm,cari)==0){
			printf("Data Mahasiswa\n");
			printf("Nama 	: %s\n",p->elmt.nama);
			printf("NPM 	: %s\n",p->elmt.npm);
			printf("Nilai 	: %2.2f\n\n",p->elmt.nilai);
			p=p->next;
			getch();
		}
		else {
			p=p->next;
		}
	}
}
