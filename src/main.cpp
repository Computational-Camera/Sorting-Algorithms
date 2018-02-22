#include "sort.h"
#include "linklist.h"


/*
int main(){
    std::cout<<"===========Sorting Algorithms Test==========="<<std::endl; 
    Gen_Data();  
    void (*fun_ptr[6])(void)  = {&BubbleSort,&InsertSort,&SelectSort,&QuickSort,&HeapSort,&MergeSort};  
    const char *info[]        = {"1.Bubble Sort:   ",
                                 "2.Insert Sort:   ",
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
*/
int main(){
    printf("******Start******\n");
    head=CreatList();
    Display();
    Menu();
    return 0;
}
