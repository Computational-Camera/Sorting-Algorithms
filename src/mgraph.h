#include "stdio.h"
#define MaxVertexNum 100
#define QueueSize 100
typedef char VertexType;
typedef int EdgeType;
typedef struct{                               /*邻接矩阵的定义*/
	       VertexType vexs[MaxVertexNum];
	       EdgeType edges[MaxVertexNum][MaxVertexNum];
	       int n,e;
}MGraph;
MGraph  *G;                      /*图的指针*/

typedef struct{int front;                     /*循环队列定义*/
	       int rear;
	       int count;
	       int data[QueueSize];}CirQueue;
CirQueue *Q;                     /*队列指针*/

typedef enum{FALSE,TRUE}Boolean;
Boolean visited[MaxVertexNum];                /*布尔向量定义*/


MGraph *CreatMGraph1()                        /*创建无向图邻接矩阵函数*/
{int i,j,k,w;
 char ch[100];
 G=(MGraph *)malloc(sizeof(MGraph));
 printf("请输入图的顶点数：");
 scanf("%d",&G->n);
 gets(ch);
 printf("请输入图的边数：");
 scanf("%d",&G->e);
 gets(ch);
 printf("请输入顶点的名称：");
 for(i=0;i<G->n;i++)
     G->vexs[i]=getchar();
 gets(ch);
 for(i=0;i<G->n;i++)
    for(j=0;j<G->n;j++)
    G->edges[i][j]=0;
 printf("请输入边（格式：始点，终点，边的权数） ：\n");
 for(k=0;k<G->e;k++)
    {scanf("%d,%d,%d",&i,&j,&w);
     gets(ch);
     G->edges[i][j]=w;
     G->edges[j][i]=w;}
return G;}


MGraph *CreatMGraph2()                         /*创建有向图邻接矩阵函数*/
{int i,j,k,w;
 char ch[100];
 G=(MGraph *)malloc(sizeof(MGraph));
 printf("请输入图的顶点数：");
 scanf("%d",&G->n);
 gets(ch);
 printf("请输入图的边数：");
 scanf("%d",&G->e);
 gets(ch);
 printf("请输入顶点的名称：");
 for(i=0;i<G->n;i++)
     G->vexs[i]=getchar();
 gets(ch);
 for(i=0;i<G->n;i++)
    for(j=0;j<G->n;j++)
    G->edges[i][j]=0;
 printf("请输入边（格式：始点，终点，边的权数） ：\n");
 for(k=0;k<G->e;k++)
    {scanf("%d,%d,%d",&i,&j,&w);
     gets(ch);G->edges[i][j]=w;}
return G;}


void Display()                                   /*显示邻接矩阵函数*/
{int i,j;
  puts("所输入邻接矩阵为:");
  printf("     ");for(i=0;i<G->n;i++) {printf("%4c ",G->vexs[i]);}
  printf("\n\n");
  for(i=0;i<G->n;i++)
     {printf("%4c ",G->vexs[i]);
     for(j=0;j<G->n;j++)
     {printf("%4d ",G->edges[i][j]);}
     printf("\n");}}


void DFSM(int i)                                  /*深度优先搜索函数*/
{int j;
 printf("访问顶点：%c  ",G->vexs[i]);
 visited[i]=TRUE;
 for(j=0;j<G->n;j++)
    {if(G->edges[i][j]!=0&&!visited[j])
      DFSM(j);}}


void DFSTraverse()                                /*深度优先遍历函数*/
{int i;
puts("按深度优先遍历顶点：");
for(i=0;i<G->n;i++)
   visited[i]=FALSE;
for(i=0;i<G->n;i++)
   {if(!visited[i])
     DFSM(i);}}

CirQueue  *InitQueue()                 /*队列初始化函数*/
{Q=(CirQueue*)malloc(sizeof(CirQueue));
 Q->front=Q->rear=0;
 Q->count=0;
 return(Q);}

int QueueEmpty()                       /*判队空函数*/
{return Q->count==0;}

int QueueFull()                        /*判队满函数*/
{return Q->count==QueueSize;}

void EnQueue(int i)                    /*入队函数*/
{if (QueueFull()) printf("error");
 Q->count++;
 Q->data[Q->rear]=i;
 Q->rear=(Q->rear+1)%QueueSize;}

int DeQueue()                          /*出队函数*/
{int temp;
 temp=Q->data[Q->front];
 Q->count--;
 Q->front=(Q->front+1)%QueueSize;
 return temp;}

void BFSM(int k)                                    /*深度优先搜索函数*/
{int i,j;
 Q=InitQueue();
 printf("访问顶点：%c  ",G->vexs[k]);
 visited[k]=TRUE;
 EnQueue(k);
 while(!QueueEmpty()){
 i=DeQueue();
 for(j=0;j<G->n;j++)
     if(G->edges[i][j]!=0&&!visited[j])
	 {printf("访问顶点：%c  ",G->vexs[j]);
	 visited[j]=TRUE;
         EnQueue(j);}}}


void BFSTraverse()                                   /*深度优先遍历函数*/
{int i;
puts("\n按广度优先遍历顶点：");
for(i=0;i<G->n;i++)
   visited[i]=FALSE;
for(i=0;i<G->n;i++)
   {if(!visited[i])
     BFSM(i);}}



main()                                               /*主函数*/
{char d;
 char ch[100];
 printf("******欢迎使用图的遍历程序******\n");
 A:printf("请选择输入图类型（a.无向图  b.有向图）：");
 scanf("%c",&d);
 gets(ch);
 if(d=='a'||d=='A') G=CreatMGraph1();
 else if(d=='b'||d=='B') G=CreatMGraph2();
 else goto A;
 Display();
 DFSTraverse();
 BFSTraverse();
C:printf("\n是否继续使用（y,n）？");
 scanf("\n%c",&d);gets(ch);
 if(d=='y'||d=='Y') goto A;
 if(d=='n'||d=='N') goto B;
 else goto C;
B:printf("谢谢使用！");}