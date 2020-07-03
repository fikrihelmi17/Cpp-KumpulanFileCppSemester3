#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define max 100

// ------ Graph dengan List Adjency ------ //
struct AdjList{
	int Destination;
	AdjList *Next;
};

//inisialisasi dfs bfs
int q[20],top=-1,front=-1,rear=-1,a[20][20],vis[20],stack[20]; 
int hapus(); //ini fungsi untuk delete
void add(int item);  //ini fungsi untuk penambahan node
void bfs(int s,int n);  //disini fungsi bfs
void dfs(int s,int n);  //ini fungsi dfs
void push(int item);  
int pop();

//graf
AdjList *Graph[max];
AdjList *newAdjList(int dest);
void addEdge(int node, int dest, int maxNode);
void createEdge(int node, int dest);
void printGraph(int maxNode);
int convertToNumber(char letter);
int convertToASCII(int number);
int vertex;


int main(){
	int prg, pilih1;
	int jumlah, berat;
	char kode[5];
	char nama[35];
	char jenis[25];
	char dataTree[3];
	char konfirTree[5], konfirGraph[5];
	char dataGraph, destGraph;
	
	int i,s,ch,j; 
	char c,dummy; 
	 
	
	do{
	
	system("cls");
	printf("================================\n");
	printf("|        PROGRAM GRAF          |\n");
	printf("================================\n");
	printf("| 1. Graph                     |\n");
	printf("| 2. Keluar program            |\n\n");
	printf("================================\n");
	printf(" Pilih menu [1,2]: "); scanf("%d", &prg);
	
	switch(prg){	
		case 1:
		do{
			system("cls");
			printf("================================\n");
			printf("|        MENU  GRAF            |\n");
			printf("================================\n");
			printf("| 1. Input graf                |\n");
			printf("| 2. Print graf                |\n");
			printf("| 3. Traversal BFS             |\n");
			printf("| 4. Traversal DFS             |\n");
			printf("| 5. Clear                     |\n");
			printf("| 6. Keluar                    |\n");
			printf("================================\n");
			printf(" Pilih menu [1/2/3/4/5] : "); scanf("%d",&pilih1);
			
			switch(pilih1){
				case 1:
					do{
						system("cls");
						printf("====================================\n");
						printf("|           INPUT GRAF             |\n");
						printf("====================================\n");
						
						printf("Masukkan jumlah vertices = "); scanf("%d", &vertex);
						
						for(i=1;i<=vertex;i++) 
						{ 
							for(j=1;j<=vertex;j++) 
								{ 
									printf("Masukkan simpul dari %d ke %d dengan bobot = ",i,j); 
									scanf("%d",&a[i][j]); 
									addEdge(convertToNumber(i), convertToNumber(j),8);
								} 
						}	 
						printf("THE ADJACENCY MATRIX IS\n");  //matrix adjacency
						for(i=1;i<=vertex;i++) 
						{ 
							for(j=1;j<=vertex;j++) 
								{ 
									printf(" %d",a[i][j]); 
								} 
							printf("\n"); 
						}		 
					
						for(i=1;i<=vertex;i++) 
						vis[i]=0; 
						getch();
						
						
						printf("====================================\n");
					} while(strcmp(konfirGraph,"Y")==0 || strcmp(konfirGraph,"y")==0);
					break;
				
				case 2:
					printGraph(8);
					getch();
				break;
				case 3:
					for(i=1;i<=vertex;i++) 
					{ 
						for(j=1;j<=vertex;j++) 
							{ 
								printf("ENTER 1 IF %d HAS A NODE WITH %d ELSE 0 ",i,j); 
								scanf("%d",&a[i][j]); 
							} 
					}	 
					printf("THE ADJACENCY MATRIX IS\n");  //matrix adjacency
					for(i=1;i<=vertex;i++) 
					{ 
						for(j=1;j<=vertex;j++) 
							{ 
								printf(" %d",a[i][j]); 
							} 
						printf("\n"); 
					}		 
				
					for(i=1;i<=vertex;i++) 
					vis[i]=0; 
					
					printf("ENTER THE SOURCE VERTEX :"); 
					scanf("%d",&s); 
					
					bfs(s,vertex);
					getch();
				break;
				case 4 :
					for(i=1;i<=vertex;i++) 
					{ 
						for(j=1;j<=vertex;j++) 
							{ 
								printf("ENTER 1 IF %d HAS A NODE WITH %d ELSE 0 ",i,j); 
								scanf("%d",&a[i][j]); 
							} 
					}	 
					printf("THE ADJACENCY MATRIX IS\n");  //matrix adjacency
					for(i=1;i<=vertex;i++) 
					{ 
						for(j=1;j<=vertex;j++) 
							{ 
								printf(" %d",a[i][j]); 
							} 
						printf("\n"); 
					}		 
				
					for(i=1;i<=vertex;i++) 
					vis[i]=0; 
					
					printf("ENTER THE SOURCE VERTEX :"); 
					scanf("%d",&s); 
					
					dfs(s,vertex); break; //diarahkan ke fungsi bfs
				case 5 :
					pop();
					printf("Data terhapus");
					getch();
				break;
			}
				
			
		} while(pilih1 >= 1 && pilih1 <= 5);
		break;
		}
	
	} while(prg ==1);
	
	return 0;	
}

// ------- Graph dengan List Adjency -------- //
AdjList *newAdjList(int dest) {
    AdjList *baru;
	baru = new AdjList;
    baru->Destination = dest;
    baru->Next = NULL;
    return baru;
}

void addEdge(int node, int dest, int maxNode){
	if(node >= maxNode || dest >= maxNode ){
		printf("Node tidak ada");
	} else {
		createEdge(node, dest);
		createEdge(dest, node);
	}
}

void createEdge(int node, int dest){
	AdjList *posNode, *b;
	
	b = newAdjList(dest);
	posNode = Graph[node];
	
	if(posNode == NULL){
		Graph[node] = b;
	} else {
		while(posNode->Next != NULL && posNode->Destination != dest){
			posNode = posNode->Next;
		}
		if(posNode->Destination != dest){
			posNode->Next = b;
		}
	}
}

void printGraph(int maxNode){
	AdjList *posNode;
	for(int i = 0; i < maxNode; i++){
		posNode = Graph[i];
		if(posNode == NULL){
			printf("\n\nDestinasi Node ke %d Tidak Ada\n", i);
		} else {
			printf("\n\nDestinasi Node ke %d", i);
			while(posNode != NULL){
				printf("-> %c",convertToASCII(posNode->Destination));
				posNode = posNode->Next;
			}
		}
	}
}

// Fungsi untuk mengkonversi dari alfabet ke angka
int convertToNumber(char letter){
	int num, asciinumber;
	
	if (letter >= 'A' && letter <= 'Z')
	  num = letter - 'A';
	else if (letter >= 'a' && letter <= 'z')
	  num = letter - 'a';
	  
	asciinumber = num + '0';
	asciinumber = asciinumber - 47;
	
	return asciinumber;
}

// Fungsi untuk mengkonversi dari angka ke alfabet
int convertToASCII(int number){
	number = number + 64;
	
	return number;
}

//------------------- BFS dan DFS ---------------------------//
//**************BFS(breadth-first search) code**************// 
void bfs(int s,int n) 
{ 
	int p,i; 
	add(s); 
	vis[s]=1; 
	p=hapus(); 
	
	if(p!=0) 
		printf(" %d",p); 
	
	while(p!=0) 
	{ 
		for(i=1;i<=n;i++) 
			if((a[p][i]!=0)&&(vis[i]==0)) 
				{ 
					add(i); 
					vis[i]=1; 
				}
							 
		p=hapus(); 
		if(p!=0) 
		printf(" %d ",p); 
	} 
	
	for(i=1;i<=n;i++) 
		if(vis[i]==0) 
	bfs(i,n); 
}


void add(int item) 
{ 
	if(rear==19) 
		printf("QUEUE FULL"); 
	else 
	{ 
		if(rear==-1) 
			{ 
				q[++rear]=item; 
				front++; 
			} 
		else 
			q[++rear]=item; 
	} 
} 

int hapus() 
{ 
	int k; 
	if((front>rear)||(front==-1)) 
		return(0); 
	else 
	{ 
		k=q[front++]; 
		return(k); 
	} 
} 

//***************DFS(depth-first search) code******************// 
void dfs(int s,int n) 
{ 
	int i,k; 
	push(s); 
	vis[s]=1; 
	k=pop(); 
	
	if(k!=0) 
		printf(" %d ",k); 
		while(k!=0) 
		{ 
		for(i=1;i<=n;i++) 
			if((a[k][i]!=0)&&(vis[i]==0)) 
		{ 
			push(i); 
			vis[i]=1; 
		} 
		k=pop(); 
			if(k!=0) 
				printf(" %d ",k); 
		} 
		for(i=1;i<=n;i++) 
			if(vis[i]==0) 
		dfs(i,n); 
} 

void push(int item) 
{ 
	if(top==19) 
		printf("Stack overflow "); 
	else 
		stack[++top]=item; 
}
 
int pop() 
{ 
	int k; 
		if(top==-1) 
			return(0); 
		else 
		{ 
			k=stack[top--]; 
			return(k); 
		} 
}
