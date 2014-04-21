#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace  std;
int  longestSequence(int array[], int len, int length[]);
int  main()
{
  //  int a[] = {5,2,8,6,3,6,9,7,100};
    int  a[] = {1,2,3,4,500,6,7,8,90,1000};
    int l[9];
    longestSequence(a,9,l);
}


int  longestSequence(int array[], int len, int length[])
{    
     int dots[len + 1];
     int end = 1000;
     dots[0] = end;
     for(int i = 0; i <= len; i++)
     {
        length[i] = 1;
     }
     for(int j = 0; j <= len; j++)
     {
        for(int i = 0; i <= j - 1; i++)
        {
           if(array[i] < array[j])
	   {
	    if((length[i] + 1) > length[j])
	       {
	         length[j] = length[i] + 1;
	         dots[j] = i;
	       }
	   }
        }
    }
    int maxElement = length[0];
    int maxPos = 1;
    cout << "指向数组的位置" << endl;
    for(int  q = 0; q <= len; q++)
    {
       cout << dots[q] << endl;
    }
    
    for(int k = 0; k <=  len; k++)
    {  
	    cout<<length[k]<<" ";
       if(maxElement < length[k])	    
       {
	      // cout<<dots[k]<<" ";
          maxElement = length[k];
	  maxPos = k;
       }
    }
    int  shiftPos  = maxPos;
    cout << "最后的指针为" << endl;
    cout << shiftPos << endl;
    cout << "最长子序列为" << endl;
    cout << array[shiftPos] << endl;
    while(dots[shiftPos] != end)
    {  
       cout << array[dots[shiftPos]] << endl;
       shiftPos = dots[shiftPos];
    }
}



































