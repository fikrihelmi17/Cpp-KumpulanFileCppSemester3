#include<stdio.h>
#define max 100

struct AdjList{
	int Destination;
	AdjList *Next;
};

AdjList *Graph[max];
AdjList *newAdjList(int dest);
void addEdge(int node, int dest, int maxNode);
void createEdge(int node, int dest);
void printGraph(int maxNode);

int main() {
	int vertex = 5;
	
	addEdge(0, 1, vertex);
    addEdge(0, 4, vertex);
    addEdge(1, 2, vertex);
    addEdge(1, 3, vertex);
    addEdge(1, 4, vertex);
    addEdge(2, 3, vertex);
    addEdge(3, 4, vertex);
	printGraph(vertex);
	
	return 0;
}

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
				printf("-> %d",posNode->Destination);
				posNode = posNode->Next;
			}
		}
	}
}
