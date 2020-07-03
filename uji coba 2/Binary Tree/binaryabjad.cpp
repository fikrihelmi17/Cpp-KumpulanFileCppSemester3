/*
    Saungkode - saungkode.wordpress.com
*/
 
/*Library*/
 
#include <stdio.h>
#include <string.h>
#include <malloc.h>
 
#define LEFT "left"
#define RIGHT "right"
 
/*-------Pohon Biner*/
 
typedef struct smp *alamatsimpul;
typedef struct smp{
    char huruf;         //Elemen pohon
    alamatsimpul right;//Ranting kanan
    alamatsimpul left;//Ranting kiri
}simpul;
 
typedef struct{
    simpul* root;//Root = Akar pohon paling atas
}tree;
 
/*-------Stack*/
 
typedef struct elmStack *alamatelmtStack;
typedef struct elmStack{
    simpul* elemen;//alamat simpul pohon
    alamatelmtStack next;
}containerStack;
 
typedef struct {
  containerStack *top;//Paling atas
}stack;
 
/*-------Queue*/
 
typedef struct elmQueue *alamatelmtQueue;
typedef struct elmQueue{
    simpul* elemen;//alamat simpul pohon
    alamatelmtQueue next;
}containerQueue;
 
typedef struct{
    containerQueue *first;//Pointer depan
    containerQueue *last;//Pointer belakang
}queue;
 
/*
    Saungkode - saungkode.wordpress.com
*/
 
/*Mesin*/
 
/*-------Pohon Biner*/
 
//Buat pohon baru
void makeTree(char huruf, tree *T){
    simpul *node;//Pointer baru
    node = (simpul *) malloc (sizeof (simpul));
    node->huruf = huruf;
    node->right = NULL;
    node->left = NULL;
    (*T).root = node;//Pindah akar
}
 
//Tambah elemen di ranting kanan
void addTree(char tempat[], char huruf, simpul **root){
    /*Jika ranting kanan masih kosong*/
    if((*root)->right == NULL){
        simpul *node;//Pointer baru
        node = (simpul *) malloc (sizeof (simpul));
        node->huruf = huruf;
        node->right = NULL;
        node->left = NULL;
        if(strcmp(tempat, RIGHT) == 0) (*root)->right = node;//Pindah ranting kanan
        else if(strcmp(tempat, LEFT) == 0) (*root)->left = node;//Pindah ranting kiri
    }
}
 
/*
    Saungkode - saungkode.wordpress.com
*/
 
/*-------Stack*/
 
//buat stack kosong
void createEmptyStack(stack *S){
  (*S).top = NULL;
}
 
//fungsi memeriksa stack kosong atau tidak
int isStackEmpty(stack S){
    int hasil = 0;
    if(S.top == NULL){ //jika kosong
        hasil = 1;
    }
    return hasil;
}
 
//operator peek
simpul* peek(stack S){
    if(S.top != NULL){ //jika tidak kosong
        return S.top->elemen;
    }
}
 
//operator push
void push(simpul *node, stack *S ){
    containerStack *tunjuk;
    tunjuk = (containerStack *) malloc (sizeof (containerStack));
    tunjuk->elemen = node;
    tunjuk->next = (*S).top;
    (*S).top = tunjuk;
    tunjuk = NULL;
}
 
//operator pop
void pop(stack *S){
    if((*S).top != NULL){ //jika tidak kosong
        containerStack *tunjuk = (*S).top;
        (*S).top = (*S).top->next;
        tunjuk->next = NULL;
        free(tunjuk);
    }
}
 
/*
    Saungkode - saungkode.wordpress.com
*/
 
/*-------Queue*/
 
//prosedur membuat queue kosong
void createEmptyQueue(queue *Q){
    (*Q).first = NULL;
    (*Q).last = NULL;
}
 
//prosedur memeriksa apakah queue kosong
int isQueueEmpty(queue Q){
    int hasil = 0;
    if(Q.first == NULL){
        hasil = 1;
    }
    return hasil;
}
 
//prosedur menambah elemen pada queue(addLast)
void addQueue(simpul *node, queue *Q ){
    containerQueue *tunjuk;
    tunjuk = (containerQueue *) malloc (sizeof (containerQueue));
    tunjuk->elemen = node;
    tunjuk->next = NULL;
 
    //jika queue masih kosong (addFirst)
    if((*Q).first == NULL) (*Q).first = tunjuk;
    else (*Q).last->next = tunjuk;
 
    (*Q).last = tunjuk;
    tunjuk = NULL;
}
 
//prosedur delete queue (delFirst);
void delQueue(queue *Q){
 
    //jika queue tidak kosong
    if((*Q).first != NULL){
        containerQueue *tunjuk = (*Q).first;
        (*Q).first = (*Q).first->next;
        tunjuk->next = NULL;
        free(tunjuk);
    }
}
 
/*
    Saungkode - saungkode.wordpress.com
*/
 
/*-------Prosedur Cetak Pohon Biner*/
 
// print pohon menurut keadalaman dengan algoritma DFS
void DFS_printPreOrder(simpul *root){
    if(root!=NULL){
        stack S;
        createEmptyStack(&S);
        push(root, &S);
 
        while(isStackEmpty(S) != 1){
            printf("%c ", S.top->elemen->huruf);
            simpul *node = peek(S);
            pop(&S);
 
            if(node->right != NULL){
                push(node->right, &S);
            }
            if(node->left != NULL){
                push(node->left, &S);
            }
        }
        printf("\n");
    }
}
 
//print pohon per level dengan algoritma BFS
void BFS_printLevelOrder(simpul *root){
    if(root!=NULL){
        queue Q;
        createEmptyQueue(&Q);
        addQueue(root, &Q);
 
        while(isQueueEmpty(Q) != 1){
            printf("%c ", Q.first->elemen->huruf);
 
            if(Q.first->elemen->left != NULL){
                addQueue(Q.first->elemen->left, &Q);
            }
            if(Q.first->elemen->right != NULL){
                addQueue(Q.first->elemen->right, &Q);
            }
            delQueue(&Q);
        }
        printf("\n");
    }
}
 
/*
    Saungkode - saungkode.wordpress.com
*/
 
int main(){
 
    tree T;
 
    makeTree('A', &T);
    addTree(LEFT , 'B', &T.root);
    addTree(RIGHT, 'C', &T.root);
    addTree(LEFT , 'D', &T.root->left);
    addTree(RIGHT, 'E', &T.root->left);
    addTree(LEFT , 'F', &T.root->right);
    addTree(RIGHT, 'G', &T.root->right);
    addTree(LEFT , 'H', &T.root->left->left);
    addTree(RIGHT, 'I', &T.root->left->right);
    addTree(LEFT , 'J', &T.root->right->right);
    addTree(RIGHT, 'K', &T.root->right->right);
    addTree(RIGHT, 'L', &T.root->right->right->right);
 
    DFS_printPreOrder(T.root);
    BFS_printLevelOrder(T.root);
 
    return 0;
}
