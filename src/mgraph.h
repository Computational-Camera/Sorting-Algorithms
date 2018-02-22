#include "stdio.h"
#define MaxVertexNum 100
#define QueueSize 100
typedef char VertexType;
typedef int EdgeType;
typedef struct{                               /*�ڽӾ���Ķ���*/
	       VertexType vexs[MaxVertexNum];
	       EdgeType edges[MaxVertexNum][MaxVertexNum];
	       int n,e;
}MGraph;
MGraph  *G;                      /*ͼ��ָ��*/

typedef struct{int front;                     /*ѭ�����ж���*/
	       int rear;
	       int count;
	       int data[QueueSize];}CirQueue;
CirQueue *Q;                     /*����ָ��*/

typedef enum{FALSE,TRUE}Boolean;
Boolean visited[MaxVertexNum];                /*������������*/


MGraph *CreatMGraph1()                        /*��������ͼ�ڽӾ�����*/
{int i,j,k,w;
 char ch[100];
 G=(MGraph *)malloc(sizeof(MGraph));
 printf("������ͼ�Ķ�������");
 scanf("%d",&G->n);
 gets(ch);
 printf("������ͼ�ı�����");
 scanf("%d",&G->e);
 gets(ch);
 printf("�����붥������ƣ�");
 for(i=0;i<G->n;i++)
     G->vexs[i]=getchar();
 gets(ch);
 for(i=0;i<G->n;i++)
    for(j=0;j<G->n;j++)
    G->edges[i][j]=0;
 printf("������ߣ���ʽ��ʼ�㣬�յ㣬�ߵ�Ȩ���� ��\n");
 for(k=0;k<G->e;k++)
    {scanf("%d,%d,%d",&i,&j,&w);
     gets(ch);
     G->edges[i][j]=w;
     G->edges[j][i]=w;}
return G;}


MGraph *CreatMGraph2()                         /*��������ͼ�ڽӾ�����*/
{int i,j,k,w;
 char ch[100];
 G=(MGraph *)malloc(sizeof(MGraph));
 printf("������ͼ�Ķ�������");
 scanf("%d",&G->n);
 gets(ch);
 printf("������ͼ�ı�����");
 scanf("%d",&G->e);
 gets(ch);
 printf("�����붥������ƣ�");
 for(i=0;i<G->n;i++)
     G->vexs[i]=getchar();
 gets(ch);
 for(i=0;i<G->n;i++)
    for(j=0;j<G->n;j++)
    G->edges[i][j]=0;
 printf("������ߣ���ʽ��ʼ�㣬�յ㣬�ߵ�Ȩ���� ��\n");
 for(k=0;k<G->e;k++)
    {scanf("%d,%d,%d",&i,&j,&w);
     gets(ch);G->edges[i][j]=w;}
return G;}


void Display()                                   /*��ʾ�ڽӾ�����*/
{int i,j;
  puts("�������ڽӾ���Ϊ:");
  printf("     ");for(i=0;i<G->n;i++) {printf("%4c ",G->vexs[i]);}
  printf("\n\n");
  for(i=0;i<G->n;i++)
     {printf("%4c ",G->vexs[i]);
     for(j=0;j<G->n;j++)
     {printf("%4d ",G->edges[i][j]);}
     printf("\n");}}


void DFSM(int i)                                  /*���������������*/
{int j;
 printf("���ʶ��㣺%c  ",G->vexs[i]);
 visited[i]=TRUE;
 for(j=0;j<G->n;j++)
    {if(G->edges[i][j]!=0&&!visited[j])
      DFSM(j);}}


void DFSTraverse()                                /*������ȱ�������*/
{int i;
puts("��������ȱ������㣺");
for(i=0;i<G->n;i++)
   visited[i]=FALSE;
for(i=0;i<G->n;i++)
   {if(!visited[i])
     DFSM(i);}}

CirQueue  *InitQueue()                 /*���г�ʼ������*/
{Q=(CirQueue*)malloc(sizeof(CirQueue));
 Q->front=Q->rear=0;
 Q->count=0;
 return(Q);}

int QueueEmpty()                       /*�жӿպ���*/
{return Q->count==0;}

int QueueFull()                        /*�ж�������*/
{return Q->count==QueueSize;}

void EnQueue(int i)                    /*��Ӻ���*/
{if (QueueFull()) printf("error");
 Q->count++;
 Q->data[Q->rear]=i;
 Q->rear=(Q->rear+1)%QueueSize;}

int DeQueue()                          /*���Ӻ���*/
{int temp;
 temp=Q->data[Q->front];
 Q->count--;
 Q->front=(Q->front+1)%QueueSize;
 return temp;}

void BFSM(int k)                                    /*���������������*/
{int i,j;
 Q=InitQueue();
 printf("���ʶ��㣺%c  ",G->vexs[k]);
 visited[k]=TRUE;
 EnQueue(k);
 while(!QueueEmpty()){
 i=DeQueue();
 for(j=0;j<G->n;j++)
     if(G->edges[i][j]!=0&&!visited[j])
	 {printf("���ʶ��㣺%c  ",G->vexs[j]);
	 visited[j]=TRUE;
         EnQueue(j);}}}


void BFSTraverse()                                   /*������ȱ�������*/
{int i;
puts("\n��������ȱ������㣺");
for(i=0;i<G->n;i++)
   visited[i]=FALSE;
for(i=0;i<G->n;i++)
   {if(!visited[i])
     BFSM(i);}}



main()                                               /*������*/
{char d;
 char ch[100];
 printf("******��ӭʹ��ͼ�ı�������******\n");
 A:printf("��ѡ������ͼ���ͣ�a.����ͼ  b.����ͼ����");
 scanf("%c",&d);
 gets(ch);
 if(d=='a'||d=='A') G=CreatMGraph1();
 else if(d=='b'||d=='B') G=CreatMGraph2();
 else goto A;
 Display();
 DFSTraverse();
 BFSTraverse();
C:printf("\n�Ƿ����ʹ�ã�y,n����");
 scanf("\n%c",&d);gets(ch);
 if(d=='y'||d=='Y') goto A;
 if(d=='n'||d=='N') goto B;
 else goto C;
B:printf("ллʹ�ã�");}