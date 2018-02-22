//#include "sort.h"
//#include "linklist.h"
#include "bintree.h"

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

/*
int main(){
    std::cout<<"===========Linklist Algorithms Test==========="<<std::endl; 
    head=CreatList();
    Display();
    Menu();
    return 0;
}
*/


int main(){                                                       /*Ö÷º¯Êý*/
    char r,s[100];
    std::cout<<"===========Binary Tree Algorithms Test==========="<<std::endl; 
    A:printf(" Input nodes in preoder fashion\n");
    root=CreatBinTree();
    printf("Preorder result is ");      Preorder(root);   printf("\n");
    printf("Inorder result is ");       Inorder(root);    printf("\n");
    printf("Postorder result is");      Postorder(root);  printf("\n");
    printf("Level traversal result is");Levorder(root);   printf("\n");
    printf("numer of leaves: %d  number of nodes: %d\n",j,i);
    C:printf("Give another try? ");
    scanf("\n%c",&r);gets(s);
    if(r=='y'||r=='Y') 
        {i=j=0;goto A;}
    if(r=='n'||r=='N') 
        goto B;
    else goto C;
    B:std::cout<<"===========       Finish Test     ==========="<<std::endl;
    return 0;
}
