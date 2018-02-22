/************************************************************************/
/* Sorting Algorithm Practice:                                          */
/*                                                                      */
/* Sort.h                                                               */
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

#ifndef _SORT
#define _SORT

#include <iostream>
#include <cstring>
#include <time.h>

#define n 10000

typedef int KeyType;

typedef struct{
    KeyType Key;
}RecType;      

typedef RecType SeqList[n];        
    
SeqList R;

typedef enum{
    FALSE,TRUE
}Boolean;          

//===========Bubble Sort============
void BubbleSort(){
    int i,j;
    Boolean swap;
    for(i=0;i<n;i++){
        swap=FALSE;
        for(j=n-1;j>i;j--)
            if(R[j].Key<R[j-1].Key){
                RecType temp=R[j];
                R[j]=R[j-1];
                R[j-1]=temp;
                swap=TRUE;
            }
        if(swap==FALSE)
            return;
    }
}
//============Insert Sort==========
void InsertSort(){  // O(n^2) good for online sorting
    int i,j;
    for(i=1;i<n;i++)
        if(R[i].Key<R[i-1].Key){
            RecType temp=R[i];
            j=i-1;
            while(temp.Key<R[j].Key){
                R[j+1]=R[j];
                j--;
            }
            R[j+1]=temp;
       }
}


//==========Select Sort========
void SelectSort(){ // O(n^2)
    int i,j,k;
    for(i=0;i<n;i++){
        k=i;
        for(j=i+1;j<n;j++)
            if(R[j].Key<R[k].Key)
                k=j;
        if(k!=i){
            RecType temp=R[i];
            R[i]=R[k];
            R[k]=temp;
        }
    }
}

//===========Quick Sort==========
int Partition(int i,int j){  //O(nlogn)
    RecType pivot=R[i];
    while(i<j){
        while(i<j&&R[j].Key>=pivot.Key) 
            j--;
        if(i<j) 
            R[i++]=R[j];
        while(i<j&&R[i].Key<=pivot.Key) 
            i++;
        if(i<j) 
            R[j--]=R[i];
    }
    R[i]=pivot;
    return i;
}

void QuickSort1(int low,int high){     
    int pivotpos;
    if(low<high){
        pivotpos=Partition(low,high);
        QuickSort1(low,pivotpos-1);
        QuickSort1(pivotpos+1,high);
    }
}

void QuickSort(){ 
  QuickSort1(0,n);
}
  
//==========Heap Sort============
inline void Heapify(int low,int high){
    int large;
    RecType temp=R[low];
    for(large=2*low;large<=high;large*=2){
        if(large<high&&R[large].Key<R[large+1].Key) 
            large++;
        if(temp.Key>=R[large].Key) break;
        R[low]=R[large];
        low=large;
    }
    R[low]=temp;
}

inline void BuildHeap(){
    for(int i = n>>1;i>=0;--i)
        Heapify(i,n);
}

void HeapSort(){
    BuildHeap();
    for(int i=n-1;i>0;--i){
        RecType temp=R[0];
        R[0]=R[i];
        R[i]=temp;
        Heapify(0,i-1);
    }
}

//=============Merge Sort============
void inline Merges(int low,int m,int high, RecType *R1){
    int i=low,j=m+1,p=0;
    //RecType *R1=(RecType *)malloc((high-low+1)*sizeof(RecType));
    while(i<=m&&j<=high)
        R1[p++]=(R[i].Key<=R[j].Key) ? R[i++]:R[j++];
    while(i<=m) 
        R1[p++]=R[i++];
    while(j<=high) 
        R1[p++]=R[j++];
    for(p=0,i=low;i<=high;++p,++i)
        R[i]=R1[p];
    //free(R1);
    //memcpy(R+low, R1, (high-low+1)*sizeof(RecType));
}

void MergeSort1(int low,int high, RecType *Buffer_Ptr){
    int mid;
    if(low<high){
        mid=(low+high)>>1;
        MergeSort1(low,mid,    Buffer_Ptr);
        MergeSort1(mid+1,high, Buffer_Ptr);
        Merges(low,mid,high,   Buffer_Ptr);
    }
}

void MergeSort(){
    RecType *Buffer_Ptr=(RecType *)malloc(n*sizeof(RecType));//high-low+1 is the required size in theory
    MergeSort1(0,n-1, Buffer_Ptr);
    free(Buffer_Ptr);
}

void Gen_Data(){

    long i;
    time_t timer;
    time(&timer);
    srand(timer);
    for(i=0;i<n;i++)
    R[i].Key=rand();

    FILE *fp;
    fp=fopen("./data/INPUT.dat","w");
    for(i=0;i<n;i++)
        fprintf(fp,"%d ",R[i].Key);
    fclose(fp);
}

void Load_Data(){
    long i;
    FILE *fp;
    fp=fopen("./data/INPUT.dat","r");
    for(i=0;i<n;i++)
        if (fscanf(fp,"%d",&R[i].Key)==0)
            std::cout<<"Error in Loading Data"<<std::endl;  
    fclose(fp);
}

void Save_Data(){
    long i;
    FILE *fp;
    fp=fopen("./data/OUTPUT.dat","w");
    for(i=0;i<n;i++)
        fprintf(fp,"%d ",R[i].Key);
    fclose(fp);
}

void Check_Data(){
    SeqList L;             
    int i;
    FILE *fp;
    fp=fopen("./data/OUTPUT.dat","r");
    for(i=0;i<n;i++)   
        if (fscanf(fp,"%d",&L[i].Key)==0)
            std::cout<<"Load Data Error in Checking"<<std::endl;  
    for(i=1;i<n;i++)      
        if(L[i].Key<L[i-1].Key){
            std::cout<<L[0].Key<<" "<<L[i].Key<<" "<<L[i-1].Key<<std::endl;
            std::cout<<i<<"  error"<<std::endl;
            break;
        }
    fclose(fp);
}

#endif
