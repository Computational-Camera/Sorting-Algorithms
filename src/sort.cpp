/************************************************************************/
/* Sorting Algorithm Practice:                                          */
/*                                                                      */
/* Sort.cpp                                                             */
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
#include <time.h>
#include "sort.h"

void Gen_Data(){

    long i;
    time_t timer;
    time(&timer);
    srand(timer);
    for(i=0;i<=n;i++)
    R[i].Key=rand();

    FILE *fp;
    fp=fopen("./data/INPUT.dat","w");
    for(i=1;i<=n;i++)
        fprintf(fp,"%d ",R[i].Key);
    fclose(fp);
}

void Load_Data(){
    long i;
    FILE *fp;
    fp=fopen("./data/INPUT.dat","r");
    for(i=1;i<=n;i++)
        if (fscanf(fp,"%d",&R[i].Key)==0)
            std::cout<<"Error in Loading Data"<<std::endl;  
    fclose(fp);
}

void Save_Data(){
    long i;
    FILE *fp;
    fp=fopen("./data/OUTPUT.dat","w");
    for(i=1;i<=n;i++)
        fprintf(fp,"%d ",R[i].Key);
    fclose(fp);
}

void Check_Data(){
    SeqList L;             
    long i;
    FILE *fp;
    fp=fopen("./data/OUTPUT.dat","r");
    for(i=1;i<=n;i++)   
        if (fscanf(fp,"%d",&L[i].Key)==0)
            std::cout<<"Load Data Error in Checking"<<std::endl;  
    for(i=1;i<n;i++)      
        if(L[i].Key>L[i+1].Key){
            printf("error");
            break;
        }
    fclose(fp);
}

int main(){
    std::cout<<"===========Sorting Algorithms Test==========="<<std::endl; 
    Gen_Data();  
    void (*fun_ptr[6])(void)  = {&InsertSort,&BubbleSort,&SelectSort,&QuickSort,&HeapSort,&MergeSort};  
    const char *info[]        = {"1.Insert Sort:   ",
                                 "2.Bubble Sort:   ",
                                 "3.Select Sort:   ",
                                 "4.Quick  Sort:   ",
                                 "5.Heap   Sort:   ",
                                 "6.Merge  Sort:   "};
    //============Test==========
    for (int k=0; k<6; k++){
        std::cout<<info[k];//printf("\n     1.Insert Sort:   ");
        Load_Data();
        clock_t start=clock();
        (*fun_ptr[k])();
        std::cout<<clock()-start<<" ticks"<<std::endl;
        Save_Data();
        Check_Data();    
    }     
    std::cout<<"===========       Finish Test     ==========="<<std::endl;
    return 0;
}
