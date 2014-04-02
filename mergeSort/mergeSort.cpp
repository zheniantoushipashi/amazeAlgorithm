#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using  namespace  std;
void   MergeSort(int array[], int begin, int end);
void   Merge(int  array[], int begin, int mid, int end);
int   main()
{
     int a[]  = {12,4,19,2,4,1,0,-2,-3};
     int  length = sizeof(a)/sizeof(*a);
     std::cout<<"原来的数组为"<<std::endl;
     for(int i = 0; i < length; i++)
     {
         std::cout<<a[i]<<std::endl;
     }
     MergeSort(a,0,9);
     std::cout<<"排序后的数组为"<<std::endl;
     for(int i = 0; i < length; i++)
     {
         std::cout<<a[i]<<std::endl;
     }
     return  0;
}

void  MergeSort(int array[], int begin, int end)
{  
    std::cout<<"数组的开始位置"<<begin<<std::endl;
    std::cout<<"数组的结束位置"<<end<<std::endl;
    int length = end - begin;
    std::cout<<"调用数组长度"<<length<<std::endl;
    std::cout<<"数组为"<<std::endl;
    for(int k = begin; k <= length; k++)
    {
      std::cout<<array[k]<<std::endl;
    }
    if(begin < end)
    {
       int mid = (begin + end) / 2;
       MergeSort(array, begin, mid);
       MergeSort(array, mid + 1, end);
       Merge(array, begin, mid, end);
    }  
}
   



void  Merge(int array[], int begin, int mid, int end)
{    
     int  tmp[10];
     int   tmpPointer = begin;
     int i = begin, j = mid + 1, m = mid, n = end;
     while(i <= m && j <= n)
     {
         if(array[i] < array[j])
	 {
		 tmp[tmpPointer ++] = array[i ++];     
	 }
	 else
	 {
	     tmp[tmpPointer ++] = array[j ++];
	 }
     }
     while(i <= m)
     {
          tmp[tmpPointer ++] = array[i ++];  
     }
     while(j <= n)
     {
          tmp[tmpPointer ++] = array[j ++];
     }
     std::cout<<"合并后的数组为"<<std::endl;
     for(int l = begin; l <= end ; l++)
     {
        std::cout<<tmp[l]<<std::endl;
     }
     for(int k = begin; k <= end; k++)
     {
          array[k] = tmp[k];
     }
}
