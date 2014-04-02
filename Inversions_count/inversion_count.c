#include <stdio.h>
#include <stdlib.h>
#include <iostream>
 

typedef struct  data
{
   int *  array;
   unsigned  long  inversions;
}data;

data * sortAndCount(int * array, int length);

data * mergeAndCountSplitInv(int * leftArray, int * rightArray, int lengthLeft, int lengthRight);

data  *  sortAndCount(int * array, int  length)
{
    int  lengthLeft, lengthRight;
    int  leftArray[length/2], rightArray[length - length/2];
    data * X, *Y, *Z, * processedData;
    processedData =(data *) malloc(sizeof(data));
    if(length < 2)
    {
       processedData -> inversions = 0L;
       processedData -> array =array;
    
    }
    else
    {
       processedData -> inversions = 0L;
       lengthLeft = length / 2;
       lengthRight = length - length / 2;
       X =(data *) malloc(sizeof(data));
       Y =(data *) malloc(sizeof(data));
       Z =(data *) malloc(sizeof(data));
       for(int  i = 0; i < lengthLeft; i++)
       {
          leftArray[i] = array[i];
       }   
       for(int i = 0; i < lengthRight; i++)
       {
          rightArray[i] = array[i + lengthLeft];
       }
       X = sortAndCount(leftArray, lengthLeft);
       Y = sortAndCount(rightArray, lengthRight);
       Z = mergeAndCountSplitInv(X -> array, Y-> array,lengthLeft, lengthRight);
       processedData -> array = Z -> array;
       processedData -> inversions = X -> inversions + Y -> inversions + Z ->inversions;
 //      free(X -> array);
   //    free(Y -> array);
   //    free(X);
   //    free(Y);
   //    free(Z);
    }

    return processedData;

}	


data * mergeAndCountSplitInv(int * leftArray, int * rightArray, int lengthLeft, int lengthRight)
{    
     int i,j,k;
     data * processedData =(data *) malloc(sizeof(data));
     processedData -> array =(int *) malloc((lengthLeft + lengthRight)*sizeof(int) );
     processedData -> inversions = 0L;
     i = 0;
     j = 0;
     k = 0;
     while((j < lengthLeft) && (k < lengthRight))
    {
        if(leftArray[j] < rightArray[k])
	 {
	   processedData -> array[i] = leftArray[j];
           j ++;
	 
	 }
	else
	{
	   processedData -> array[i] = rightArray[k];
	   processedData -> inversions += (lengthLeft - j);
	   k ++;
	}
        i ++;
    } 
    
     if(j == lengthLeft)
     {
        while(i < lengthLeft + lengthRight)
	{
	   processedData -> array[i] = rightArray[k];
	   i ++;
	   k ++;
	}	
     }
     else
     {
       while(i < lengthLeft + lengthRight)
       {
         processedData -> array[i] = leftArray[j];
	 i ++ ;
	 j ++;

       }   
     
     }
     return  processedData;
}	











int  main()
{
   int  array1[] = {1, 3, 5, 2 , 4, 6};
   int array2[] = {1, 5, 3, 2, 4};
   int  array3[] = {9, 12, 3, 1, 6, 8, 2, 5, 14, 13, 11, 7, 10, 4, 0};
   data * result;
   result = sortAndCount(array1, 6);
   
   std::cout<<"数组一的逆序对数为"<<result->inversions<<std::endl;
   free(result -> array);
   free(result);

   result = sortAndCount(array2, 5);
    std::cout<<"数组一的逆序对数为"<<result->inversions<<std::endl;
   free(result -> array);
   free(result);

   result = sortAndCount(array3, 15);
    std::cout<<"数组一的逆序对数为"<<result->inversions<<std::endl;
   free(result -> array);
   free(result);
   return  0;


}
	


















