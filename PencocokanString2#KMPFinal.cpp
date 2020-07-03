/*
Fikri Helmi							0617104005
Deni Hadiya Akmala 					0617103009
Rudy Krisandi						0617104006
*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<conio.h>

using namespace std;

char txt[100],pat[100];
int M ,N ,lps[100],j=0,i=0;

 // Isi lps [] untuk pat patttern tertentu [0.M-1]
 
void computeLPSArray(){
		// panjang akhiran awalan terpanjang sebelumnya
  		int len = 0, i;
  		lps[0] = 0;// lps [0] selalu 0
  	
  		i = 1;
 		while(i < M){	// loop menghitung lps [i] untuk i = 1 hingga M-1
  			 	if(pat[i] == pat[len]){
  			 	len++;
  			 	lps[i] = len;
  			 	i++;
   			}else{
   		      	/*Ini sulit. Perhatikan contohnya.
	            AAACAAAA dan i = 7. Idenya mirip
    	        untuk mencari langkah. */
   				if( len != 0 ){len = lps[len-1];   
				   }
   				else{
     				lps[i] = 0;
     				i++;
   				}
   			}
  		}
}
void KMPSearch(){
  int j=0,i=0;
  M = strlen(pat);
  N = strlen(txt);
  computeLPSArray();
  	while(i < N){
		if(pat[j] == txt[i]){
		/* buat pat [] dan txt [] yang akan memegang akhiran awalan terpanjang
    						 nilai untuk pola*/
    	j++;
    	i++;
  		}
		if (j == M){
    		printf("Found pattern at index %d \n", i-j);
    		j = lps[j-1];
  		}// tidak cocok setelah perbandingan j
		  
		else if(pat[j] != txt[i]){
				/*Jangan cocok dengan karakter lps [0..lps [j-1]],
            	 mereka akan tetap cocok*/
    			if(j != 0){j = lps[j-1];}
    			else {i = i+1;}
  		}
  	}
}

int main(){
 printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
 printf("\n Masukkan sebuah TEKS                   : ");
 gets(txt);
 printf("\n Masukkan  PATTERN yang akan dicocokan  : ");
 gets(pat);
 printf("\n-------------------------------------------------------------------------------\n");
 KMPSearch();
 printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n"); 
 return 0;
}

//1. Sebuah teks (text), yaitu sebuah (long) string yang panjangnya n karakter.
//2. Pattern, yaitu sebuah string dengan panjang m karakter (m < n) yang akan dicari dalam teks. 

//output:-
//Masukkan sebuah TEKS : CampusWidyatamaCoke
//ENTER THE PATTERN    : C
//Found pattern at index 1
//Found pattern at index 16
