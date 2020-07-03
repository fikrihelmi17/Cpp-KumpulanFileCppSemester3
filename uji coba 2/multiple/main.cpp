#include <iostream>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>

struct mahasiswa{       //rumah nya beserta isi
	char npm[20];
	char nama[20];
	float nilai;
};

struct elemen{             //alamat si rumah
	mahasiswa elmt;
	struct elemen *next;
	struct elemen *subnext;
};

struct list{                    // ngasih alamat ke si satpam
	struct elemen *first;
};


