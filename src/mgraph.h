/************************************************************************/
/* Graph                                                                */
/*                                                                      */
/* MGraph.h                                                             */
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

#include <stdio.h>
#include "bintree.h"
#define MaxVertexNum 100
#define QueueSize 100

typedef char VertexType;
typedef int EdgeType;

typedef struct{         
    VertexType vexs[MaxVertexNum];
    EdgeType edges[MaxVertexNum][MaxVertexNum];
	    int n,e;
}MGraph;

typedef enum{FALSE,TRUE} Boolean;
Boolean visited[MaxVertexNum];  

void CreatMGraph1(MGraph* G) {                  /*Create directed graph*/ 
    int i,j,k,w;
    char ch[100];
    G=(MGraph *)malloc(sizeof(MGraph));
    printf("Please input the number of graph vertices: ");
    scanf("%d",&G->n);
    gets(ch);
    printf("Please input the number of graph edges: ");
    scanf("%d",&G->e);
    gets(ch);
    printf("Please input the name of the vertex: ");
    for(i=0;i<G->n;i++)
        G->vexs[i]=getchar();
        gets(ch);
    for(i=0;i<G->n;i++)
        for(j=0;j<G->n;j++)
            G->edges[i][j]=0;
    printf("Pelase input the edge (format: start, end, weight) \n");
    for(k=0;k<G->e;k++){
        scanf("%d,%d,%d",&i,&j,&w);
        gets(ch);
        G->edges[i][j]=w;
        G->edges[j][i]=w;
    }
}

void CreatMGraph2(MGraph* G){                    /*Create undirected graph*/  
    int i,j,k,w;
    char ch[100];
    G=(MGraph *)malloc(sizeof(MGraph));
    printf("Please input the number of graph vertices: ");
    scanf("%d",&G->n);
    gets(ch);
    printf("Please input the number of graph edges: ");
    scanf("%d",&G->e);
    gets(ch);
    printf("Please input the name of the vertex: ");
    for(i=0;i<G->n;i++)
        G->vexs[i]=getchar();
    gets(ch);
    for(i=0;i<G->n;i++)
        for(j=0;j<G->n;j++)
        G->edges[i][j]=0;
    printf("Pelase input the edge (format: start, end, weight) \n");
    for(k=0;k<G->e;k++){
        scanf("%d,%d,%d",&i,&j,&w);
        gets(ch);G->edges[i][j]=w;}
}

void Display(MGraph* G){
    int i,j;
    puts("The graph matrix is:");
    printf("     ");
    for(i=0;i<G->n;i++){
        printf("%4c ",G->vexs[i]);
    }
    printf("\n\n");
    for(i=0;i<G->n;i++){
        printf("%4c ",G->vexs[i]);
        for(j=0;j<G->n;j++){
        printf("%4d ",G->edges[i][j]);
        }
        printf("\n");
        }
}

void DFSM(int i, MGraph* G){                                 /*Depth first search*/
    int j;
    printf("Vertex is %c  ",G->vexs[i]);
    visited[i]=TRUE;
    for(j=0;j<G->n;j++){
        if(G->edges[i][j]!=0&&!visited[j])
            DFSM(j, G);
    }
}

void DFSTraverse(MGraph* G){                                /*Depth first visit*/
    int i;
    puts("Vertex in depth first: ");
    for(i=0;i<G->n;i++)
       visited[i]=FALSE;
    for(i=0;i<G->n;i++)
       {if(!visited[i])
         DFSM(i, G);}
}

void BFSM(int k, MGraph* G){                               /*Breadth first search*/
    int i,j;
    Q=InitQueue();
    printf("Vertex is %c  ",G->vexs[k]);
    visited[k]=TRUE;
    EnQueue(k);
    while(!QueueEmpty()){
    i=DeQueue();
    for(j=0;j<G->n;j++)
        if(G->edges[i][j]!=0&&!visited[j]){
        printf("Vertex is %c  ",G->vexs[j]);
	    visited[j]=TRUE;
        EnQueue(j);
        }
    }
}

void BFSTraverse(MGraph* G){                                   /*Breadth first vist*/
    int i;
    puts("\nVertex in broad first: ");
    for(i=0;i<G->n;i++)
       visited[i]=FALSE;
    for(i=0;i<G->n;i++){
        if(!visited[i])
         BFSM(i, G);
    }
}
