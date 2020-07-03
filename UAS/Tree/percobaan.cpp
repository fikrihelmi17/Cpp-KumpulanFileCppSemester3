#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#define MAX 30


typedef struct node
{
  int vertex;
  struct node *next;
}node;

typedef struct q
{
  int r,f;
  int data[MAX];
}q;


node *g[20];                                     //heads of linked list
int n;                                           //no. of nodes
int visited[MAX];

void readgraph();                //create adjacency list
void insert(int vi,int vj);                    //insert edge(vi,vj) in graph
void bfs(int i);
void dfs(int i);
void enquee(q *,int);
int dequee(q *);
int empty(q *);
int full(q *);

int main()
{
  int i,k;
  
  do
  {
    printf("\n\n1.CREATE A GRAPH\n2.DFS\n3.BFS\n4.QUIT.");
    printf("\nEnter your choice::");
    scanf("%d",&k);
    switch(k)
    {
      case 1:
            readgraph();
            break;
      case 2:
            for(i=0;i<n;i++)
                visited[i]=0;
            printf("\nEnter the start node::");
            scanf("%d",&i);
            dfs(i);
            break;
      case 3:
            printf("\nEnter the start node::");
            scanf("%d",&i);
            bfs(i);
            break;

    }
   }while(k!=4);
}

void readgraph()
{
  int i,j,vi,vj,no;


  printf("\nEnter the no. of vertices::");
  scanf("%d",&n);
  for(i=0;i<n;i++)                //initialise g to NULL
    g[i]=NULL;

  printf("\nEnter the no. of edges::");         //insert edges to graph g
  scanf("%d",&no);
  for(i=0;i<no;i++)
  {
    printf("\nEnter the edge(u,v)::");
    scanf("%d%d",&vi,&vj);
    insert(vi,vj);
    insert(vj,vi);

  }
  printf("THE ADJACENCY MATRIX IS\n");  //matrix adjacency
					for(i=0;i<no;i++) 
					{ 
						for(j=1;j<=n;j++) 
							{ 
								printf(" %d",vi,vj); 
							} 
						printf("\n"); 
					}	

}

void insert(int vi,int vj)
{
  node *p,*q;
  q=(node*)malloc(sizeof(node));         //acquire memory for new node
  q->vertex=vj;
  q->next=NULL;


  if(g[vi]==NULL)
    g[vi]=q;                               //insert node in linked list
  else
  {
    p=g[vi];
    while(p->next!=NULL)                       //go to end of linked list
    p=p->next;
    p->next=q;
  }
}

void dfs(int i)
{
 node *p;
 p=g[i];
 visited[i]=1;
 printf("\nVisit->%d",i);
 while(p!=NULL)
 {
   i=p->vertex;
   if(!visited[i])
    dfs(i);
   p=p->next;
  }
}

void bfs(int v)
{
  int i,w;
  q x;
  node *p;
  x.r=x.f=-1;                        //initialise quee
  for(i=0;i<n;i++)
    visited[i]=0;

  enquee(&x,v);
  printf("\nVisit->%d",v);
  visited[v]=1;
  while(!empty(&x))
  {
    v=dequee(&x);
    //insert all unvisited vertices of v into quee
    for(p=g[v];p!=NULL;p=p->next)
    {
    w=p->vertex;
    if(visited[w]==0)
    {
        enquee(&x,w);
        visited[w]=1;
        printf("\nVisit->%d",w);
    }
     }
  }
}


int empty(q *p)
{
  if(p->r==-1 &&p->f==-1)
    return(1);
  return(0);
}

int full(q *p)
{
  if(p->r==MAX-1)
    return(1);
  return(0);

}

void enquee(q *p,int x)
{

  if(p->r==-1)
  {
    p->r=p->f=1;
  }
  else
    p->r=p->r+1;
  p->data[p->r]=x;
}

int dequee(q *p)
{
  int x;
  x=p->data[p->f];
  if(p->f==p->r)
    p->r=p->f=-1;
  else
    p->f=p->f+1;
  return(x);
}
