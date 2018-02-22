#ifndef _LINKLIST
#define _LINKLIST

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define NULL  0
#define MAX 100

typedef char DataType[MAX];

typedef struct node{
    DataType data;      
    struct node *next;
}ListNode;

typedef ListNode *LinkList;
ListNode *r,*s;             /*Link node pointers*/
LinkList head;              /*Header pointer*/

LinkList CreatList(){       /*Creat link list*/
    DataType ch;
    printf("Please input link list, use END as finish \n");
    head=(LinkList)malloc(sizeof(ListNode));
    s=head;
    while (strcmp(ch,"END")){   /*Linklist tail flag*/
        r=(ListNode*)malloc(sizeof(ListNode));
        gets(ch);
        strcpy((r->data),ch);
        s->next=r;
        s=r;
    }
    s->next=NULL;
    return head;
}

void Display(){             /*Display the link list*/
    DataType ch;
    printf("Link list elements are");
    s=head->next;
    strcpy(ch,(s->data));
    printf("BEGIN");
    while((s->next)!=NULL){
        printf("-->");
        printf("%s",ch);
        s=s->next;
        strcpy(ch,s->data);
    }
    printf("-->%s\n",ch);
}

ListNode *GetNode(LinkList head,int i){        /*Find node element*/ 
    int j=0; s=head;
    while(s->next&&j<i){
        s=s->next;
        j++;
    }
    if(i==j)
    return s;
    else return NULL;
}

CheckList(DataType x){                        /*Check (repeat) node*/
    int i=0;
    s=head;
    while(s->next!=NULL){
        if(!strcmp((s->next->data),x)){
            printf("Node already exit \n",x);
            i++;
        }
        s=s->next;
    }
    return i;
}


void InsertList(){                             /*Insert node*/
    int i;
    DataType x,pool;
    printf("Insert node \n");
    scanf("%s",&x);
    printf("Input position \n");
    scanf("%d",&i);
    gets(pool);
    if(!CheckList(x)){
        r=GetNode(head,i-1);
        if(r==NULL||r->next==NULL)
            printf("\n");
        else {
            s=(ListNode *)malloc(sizeof(ListNode));
            strcpy(s->data,x);
            s->next=r->next;
            r->next=s;
        }
    }
}

void DeleteList(){                            /*Delete a node*/
    DataType x;
    int i=1;
    char ch;
    s=head;
    printf("Input the string (node) to delete\n");
    scanf("%s",&x);
    while(strcmp(x,s->next->data)&&(s)) 
        {s=s->next;i++;}
    if((!s)||(!strcmp(x,"END"))) 
        printf("Not able to find the node %s!\n",x);
    else{
        printf("The position of the node is %d\n",i);
        printf("Delete, confirm (y,n)\n");
        scanf("\n%c",&ch);
        if(ch=='y') {
            r=s->next;
            s->next=s->next->next;
            free(r);
        }
    }
}

void Menu(){                     
char i;
A: printf("Choose Option\n");
    printf("a.Insert\n");
    printf("b.Delete\n");
    printf("c.Finish\n");
    scanf("\n%s",&i);
    if(i=='a'){
        InsertList();
        Display();
        goto A;
    }
    else if(i=='b'){
        DeleteList();
        Display();
        goto A;
    }
    else if(i=='c')
        printf("Thank You \n");
    else {
        printf("Choose Option Agagin\n");
        goto A;
    }
}

#endif
