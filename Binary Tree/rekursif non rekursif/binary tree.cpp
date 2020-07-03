#include <stdio.h>

struct tree{
	int data;
	tree *kiri;
	tree *kanan;
};

struct stack{
	tree *isi;
	stack *next;
};
tree *pohon;

void PUSH (stack **Stack,tree *Tree){
	stack *baru;
	baru = new stack;
	baru->isi = Tree;
	baru->next = *Stack;
	*Stack = baru;
}

void POP(stack **Stack, tree **Tree){
	if (*Stack !=NULL){
		*Tree = (*Stack)->isi;
		*Stack = (*Stack)->next;
	}
}

void BACA_STACK (stack *STACK){
	printf("Isi stack : ");
	while (STACK !=NULL){
		printf("%d",STACK->isi->data);
		STACK = STACK->next;
	}
	printf("\n");
}

tree *BARU (int DATA){
	tree *B;
	B = new tree;
	B->data = DATA;
	B->kanan = NULL;
	B->kiri = NULL;
	return B;
}

void SISIP_SIMPUL(tree **akar, int DATA){
	tree *baru, *pNow, *temp;
	baru = BARU(DATA);
	if(*akar == NULL){
		*akar = baru;
	}else{
		pNow = *akar;
		temp = *akar;
		while (pNow->data != DATA && temp != NULL){
			pNow = temp;
			if (pNow->data < DATA)
			{
				temp = pNow->kanan;
				printf("R");
			}
			else{
				temp = pNow->kiri;
				printf("L");
			}
		}
		if (pNow->data != DATA){
			if (pNow->data < DATA){
				pNow->kanan = baru;
				//printf("R");
			}
			else{
				pNow->kiri = baru;
				//printf("L");
			}
		}else{
			printf("Nilai sudah ada\n");
		}
	}
}

void SISIP_SIMPUL_R(tree **pohonz, int DATA){
	if(*pohonz== NULL){
		*pohonz= BARU(DATA);
	}else{
		if((*pohonz)->data ==DATA){
			printf("Data sama\n");
		}else if ((*pohonz)->data<DATA){
			SISIP_SIMPUL_R(&(*pohonz)->kanan, DATA);
			printf("R");
		}else{
			SISIP_SIMPUL_R(&(*pohonz)->kiri, DATA);
			printf("L");
		}
	}
}

void PREORDER(tree*Akar){
	stack *Stack;
	tree *Pos;
	Stack = NULL;
	PUSH(&Stack,Akar);
	while(Stack !=NULL){
		POP(&Stack,&Pos);
		while(Pos!=NULL){
			printf("%d",Pos->data);
			if (Pos->kanan != NULL){
				PUSH(&Stack,Pos->kanan);
			}
			Pos = Pos->kiri;
		}
	}
}

void PREORDER_R(tree *pohonz){
	if(pohonz!= NULL){
		printf("%d\n",pohonz->data);
		PREORDER_R(pohonz->kiri);
		PREORDER_R(pohonz->kanan);
	}
}

int main(){
	pohon = NULL;
	
	SISIP_SIMPUL_R(&pohon,8);
	printf("\n==\n");
	SISIP_SIMPUL(&pohon,5);
	printf("\n==\n");
	SISIP_SIMPUL_R(&pohon,2);
	printf("\n==\n");
	SISIP_SIMPUL(&pohon,4);
	printf("\n==\n");
	SISIP_SIMPUL_R(&pohon,3);
	printf("\n==\n");
	SISIP_SIMPUL(&pohon,10);
	printf("\n==\n");
	SISIP_SIMPUL_R(&pohon,12);
	printf("\n==\n");
	SISIP_SIMPUL(&pohon,9);
	printf("\n==\n");
	SISIP_SIMPUL_R(&pohon,1);
	printf("\n==\n");
	
	PREORDER_R(pohon);
	
}
