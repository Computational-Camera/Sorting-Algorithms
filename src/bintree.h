/************************************************************************/
/* Binary Tree                                                          */
/*                                                                      */
/* btree.h                                                              */
/* Copyright 2002-2018                                                  */
/*                                                                      */
/* Permission is hereby granted, free of charge, to any person          */
/* obtaining a copy of this software and associated documentation       */
/* files (the "Software"), to deal in the Software without restriction, */
/* including without limitation the rights to use, copy, modify, merge, */
/* publish, distribute, sublicense, and/or sell copies of the Software, */
/* and to permit persons to whom the Software is furnished to do so,    */
/* subject to the following conditions:                                 */
/*                                                                      */
/* The above copyright notice and this permission notice shall be       */
/* included in all copies or substantial portions of the Software.      */
/*                                                                      */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,      */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF   */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND                */
/* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  */
/* BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN   */
/* ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN    */
/* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE     */
/* SOFTWARE.                                                            */
/*                                                                      */
/************************************************************************/

#ifndef _BINTREE
#define _BINTREE

#include <iostream>
#include <cstring>
#include <stdio.h>;

#define NULL 0
#define QueueSize 100

typedef char DataType;
typedef struct node{
    DataType data;             /*Binary Tree Node Structure*/
    struct node *lchild,*rchild;
    }BinTNode;
    
typedef BinTNode *BinTree;    /*Binary Tree Node Pointer*/
BinTree root;                 /*Root Ponter*/

int i=0,j=0;                  /*Note number and Leave number*/

typedef struct{
    int front;                /*Tree?*/
    int rear;
    int count;
    BinTree data[QueueSize];
}CirQueue;

CirQueue *Q;                 /**/


BinTree CreatBinTree() {
    char ch;
    BinTree T;
    if((ch=getchar())==' ')
        T=NULL;
    else{
        T=(BinTNode *)malloc(sizeof(BinTNode));
        i++;                 /*first node*/
        T->data=ch;
        T->lchild=CreatBinTree();
        T->rchild=CreatBinTree();
    }
    return T;
}

void Preorder(BinTree T){                                     /*Preoder*/
    if(T){
        printf("%c",T->data);
        Preorder(T->lchild);
        Preorder(T->rchild);
	 }
}

void Inorder(BinTree T){                                      /*Inorder*/
    if(T){
        Inorder(T->lchild);
        printf("%c",T->data);
        Inorder(T->rchild);
    }
}

void Postorder(BinTree T){                                    /*Postorder*/
    if(T){
	    Postorder(T->lchild);
	    Postorder(T->rchild);
	    printf("%c",T->data);
    }
}


CirQueue  *InitQueue(){                                      /*Initialize the queue*/
    Q=(CirQueue*)malloc(sizeof(CirQueue));
    Q->front=Q->rear=0;
    Q->count=0;
    return(Q);
}

int QueueEmpty(){                                            /*Check if queue is empty*/
    return Q->count==0;
}

int QueueFull(){                                             /*Check if queue is full*/
    return Q->count==QueueSize;
}

void EnQueue(BinTree T){                                     /*Enter queue*/
    if(QueueFull()) printf("error");
    Q->count++;
    Q->data[Q->rear]=T;
    Q->rear=(Q->rear+1)%QueueSize;
}

BinTree DeQueue(){                                           /*Leave queue*/
    BinTree temp;
    temp=Q->data[Q->front];
    Q->count--;
    Q->front=(Q->front+1)%QueueSize;
    return temp;
}

void Levorder(BinTree T){                                    /*Level traversal function*/
    BinTree p;
    Q=InitQueue();
    if(T!=NULL){
        EnQueue(T);
        while(!QueueEmpty()){
            p=DeQueue();
            if(!(p->lchild||p->rchild)) j++;                 /*node counter*/
            printf("%c",p->data);
            if(p->lchild!=NULL) EnQueue(p->lchild);
            if(p->rchild!=NULL) EnQueue(p->rchild);
        }
    }
}

#endif
