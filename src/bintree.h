#include "stdio.h"
#define NULL 0
#define QueueSize 100
typedef char DataType;
typedef struct node{DataType data;             /*树结点定义*/
		    struct node *lchild,*rchild;}BinTNode;
typedef BinTNode *BinTree;       /*树结点指针*/
BinTree root;                    /*根结点指针*/
int i=0,j=0;                         /*结点计数，叶子计数*/
typedef struct{int front;                     /*循环队列定义*/
	       int rear;
	       int count;
	       BinTree data[QueueSize];}CirQueue;
CirQueue *Q;                     /*队列指针*/


BinTree CreatBinTree()                                        /*建立二叉树函数*/
{char ch;
 BinTree T;
 if((ch=getchar())==' ')
 T=NULL;
 else{
      T=(BinTNode *)malloc(sizeof(BinTNode));i++;/*结点计数*/
      T->data=ch;
      T->lchild=CreatBinTree();
      T->rchild=CreatBinTree();
      }
 return T;
 }

void Preorder(BinTree T)                                      /*先序遍历函数*/
{if(T){
	  printf("%c",T->data);
	  Preorder(T->lchild);
	  Preorder(T->rchild);
	 }
}

void Inorder(BinTree T)                                       /*中序遍历函数*/
{if(T){
	  Inorder(T->lchild);
	  printf("%c",T->data);
	  Inorder(T->rchild);
	 }
}

void Postorder(BinTree T)                                     /*后序遍历函数*/
{if(T){
	  Postorder(T->lchild);
	  Postorder(T->rchild);
	  printf("%c",T->data);
       }
}

CirQueue  *InitQueue()                                        /*队列初始化函数*/
{Q=(CirQueue*)malloc(sizeof(CirQueue));
 Q->front=Q->rear=0;
 Q->count=0;
 return(Q);}

int QueueEmpty()                                              /*判队空函数*/
{return Q->count==0;}

int QueueFull()                                    /*判队满函数*/
{return Q->count==QueueSize;}

void EnQueue(BinTree T)                                       /*入队函数*/
{if(QueueFull(Q)) printf("error");
 Q->count++;
 Q->data[Q->rear]=T;
 Q->rear=(Q->rear+1)%QueueSize;}

BinTree DeQueue()                                             /*出队函数*/
{BinTree temp;
 temp=Q->data[Q->front];
 Q->count--;
 Q->front=(Q->front+1)%QueueSize;
 return temp;}

void Levorder(BinTree T)                                      /*层次遍历函数*/
{BinTree p;
 Q=InitQueue();
 if(T!=NULL)
 {EnQueue(T);
 while(!QueueEmpty())
 {p=DeQueue();
  if(!(p->lchild||p->rchild)) j++;     /*叶子结点计数*/
  printf("%c",p->data);
  if(p->lchild!=NULL) EnQueue(p->lchild);
  if(p->rchild!=NULL) EnQueue(p->rchild);}
}
}




main()                                                        /*主函数*/
{char r,s[100];
 printf("******欢迎使用二叉树操作程序******\n");
A:printf("请按先序遍历顺序输入结点（空结点用空格表示）：\n");
 root=CreatBinTree();
 printf("先序遍历为：");Preorder(root);printf("\n");
 printf("中序遍历为：");Inorder(root);printf("\n");
 printf("后序遍历为：");Postorder(root);printf("\n");
 printf("层次序遍历为：");Levorder(root);printf("\n");
 printf("叶子数为：%d，结点数为：%d\n",j,i);
C:printf("是否继续使用（y,n）？");
 scanf("\n%c",&r);gets(s);
 if(r=='y'||r=='Y') {i=j=0;goto A;}
 if(r=='n'||r=='N') goto B;
 else goto C;
B:printf("谢谢使用！");}