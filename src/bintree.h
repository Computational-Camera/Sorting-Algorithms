#include "stdio.h"
#define NULL 0
#define QueueSize 100
typedef char DataType;
typedef struct node{DataType data;             /*����㶨��*/
		    struct node *lchild,*rchild;}BinTNode;
typedef BinTNode *BinTree;       /*�����ָ��*/
BinTree root;                    /*�����ָ��*/
int i=0,j=0;                         /*��������Ҷ�Ӽ���*/
typedef struct{int front;                     /*ѭ�����ж���*/
	       int rear;
	       int count;
	       BinTree data[QueueSize];}CirQueue;
CirQueue *Q;                     /*����ָ��*/


BinTree CreatBinTree()                                        /*��������������*/
{char ch;
 BinTree T;
 if((ch=getchar())==' ')
 T=NULL;
 else{
      T=(BinTNode *)malloc(sizeof(BinTNode));i++;/*������*/
      T->data=ch;
      T->lchild=CreatBinTree();
      T->rchild=CreatBinTree();
      }
 return T;
 }

void Preorder(BinTree T)                                      /*�����������*/
{if(T){
	  printf("%c",T->data);
	  Preorder(T->lchild);
	  Preorder(T->rchild);
	 }
}

void Inorder(BinTree T)                                       /*�����������*/
{if(T){
	  Inorder(T->lchild);
	  printf("%c",T->data);
	  Inorder(T->rchild);
	 }
}

void Postorder(BinTree T)                                     /*�����������*/
{if(T){
	  Postorder(T->lchild);
	  Postorder(T->rchild);
	  printf("%c",T->data);
       }
}

CirQueue  *InitQueue()                                        /*���г�ʼ������*/
{Q=(CirQueue*)malloc(sizeof(CirQueue));
 Q->front=Q->rear=0;
 Q->count=0;
 return(Q);}

int QueueEmpty()                                              /*�жӿպ���*/
{return Q->count==0;}

int QueueFull()                                    /*�ж�������*/
{return Q->count==QueueSize;}

void EnQueue(BinTree T)                                       /*��Ӻ���*/
{if(QueueFull(Q)) printf("error");
 Q->count++;
 Q->data[Q->rear]=T;
 Q->rear=(Q->rear+1)%QueueSize;}

BinTree DeQueue()                                             /*���Ӻ���*/
{BinTree temp;
 temp=Q->data[Q->front];
 Q->count--;
 Q->front=(Q->front+1)%QueueSize;
 return temp;}

void Levorder(BinTree T)                                      /*��α�������*/
{BinTree p;
 Q=InitQueue();
 if(T!=NULL)
 {EnQueue(T);
 while(!QueueEmpty())
 {p=DeQueue();
  if(!(p->lchild||p->rchild)) j++;     /*Ҷ�ӽ�����*/
  printf("%c",p->data);
  if(p->lchild!=NULL) EnQueue(p->lchild);
  if(p->rchild!=NULL) EnQueue(p->rchild);}
}
}




main()                                                        /*������*/
{char r,s[100];
 printf("******��ӭʹ�ö�������������******\n");
A:printf("�밴�������˳�������㣨�ս���ÿո��ʾ����\n");
 root=CreatBinTree();
 printf("�������Ϊ��");Preorder(root);printf("\n");
 printf("�������Ϊ��");Inorder(root);printf("\n");
 printf("�������Ϊ��");Postorder(root);printf("\n");
 printf("��������Ϊ��");Levorder(root);printf("\n");
 printf("Ҷ����Ϊ��%d�������Ϊ��%d\n",j,i);
C:printf("�Ƿ����ʹ�ã�y,n����");
 scanf("\n%c",&r);gets(s);
 if(r=='y'||r=='Y') {i=j=0;goto A;}
 if(r=='n'||r=='N') goto B;
 else goto C;
B:printf("ллʹ�ã�");}