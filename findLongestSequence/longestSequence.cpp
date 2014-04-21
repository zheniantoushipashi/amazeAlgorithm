#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace  std;
int  longestSequence(int array[], int len, int length[]);
int  main()
{
    int a[] = {5,2,8,6,3,6,9,7};
    int l[8];
    longestSequence(a,7,l);
}


int  longestSequence(int array[], int len, int length[])
{    
     int dots[len];
     for(int i = 0; i <= len; i++)
     {
        length[i] = 1;
     }
     for(int j = 0; j <= len; j++)
     {
        for(int i = 0; i <= j-1; i++)
        {
           if(array[i] < array[j])
	   {
	    if((length[i] + 1) > length[j])
	       {
	         length[j] = length[i] + 1;
	         dots[j] = i;
	       }
	       else
	       {
	         dots[j] = 0;
	       }
	   }
        }
    }
    int maxElement = length[0];
    int maxPos = 1;
    for(int k = 0; k < len; k++)
    {  
       if(maxElement < length[k])	    
       {
          maxElement = length[k];
	  maxPos = k;
       }
    }
    int  shiftPos  = maxPos;
    cout << "最长子序列为" << endl;
    cout << array[shiftPos] << endl;
    while(dots[shiftPos] != 0)
    {  
       cout << array[dots[shiftPos]] << endl;
       shiftPos = dots[shiftPos];
    }
}



































