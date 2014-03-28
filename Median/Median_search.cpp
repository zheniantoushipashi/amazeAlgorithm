#include<stdio.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>

using  namespace  std;

int  Partition(int  r[], int i , int j){

  int   temp = r[i];
  while(i < j) {
	  while( i< j && r[j] >= temp) j--;
	  if(i < j) r[i++ ]= r[j];
	  while(i < j && r[i] <temp)  i ++;
	  if(i<j) r[j--] = r[i];

   }
	  r[i] = temp;
	  return i;

}

int  Partition1(int  array[], int left, int right)
{  int   i = left;
   int   j = right;	
   //int  randomPosition = rand() % (end - begin + 1) + begin;
   int  randomPosition = 1;
   int  pivot = array[randomPosition];
   while(i <= j)
   {
       while(array[i] < pivot)
       i++;
       while(array[j] > pivot)
       j--;
       if(i <= j)
       {
         int tmp = array[i];
	 array[i] = array[j];
	 array[j] = tmp;
	 i++;
	 j--;
       }
   }
   return  1; 
   
}
double  Median_search(int array[], int begin, int end, int  midPos)
{       
        int  arrayLength = end - begin + 1;
        std::cout<<"数组为"<<std::endl;
	for(int i = begin; i <= end; i++)
	{
	   std::cout<<array[i]<<std::endl;
	}
	if(arrayLength == 1)
	{
	  return  array[begin];
	}
	srand(time(NULL));
  	int  randomPosition = rand() % (end - begin +1) + begin;
	int  randomElement  = array[randomPosition];
//	int temp = randomElement;
//	array[randomPosition] = array[begin];
//	array[begin] = temp;

        int q = Partition(array, begin, end);
        std::cout<<"patition后的位置"<<std::endl;
	std::cout<<std::endl<<q<<std::endl;
	if(q < midPos)
	{
	   return  Median_search(array, q + 1, end, midPos);
	}
	else if(q > midPos)
	{
	   return  Median_search(array, begin, q - 1, midPos);
	}
	else
	{
	   if(arrayLength % 2)
		   return  array[q];
	   else{
	          int j, m = array[0];
		  for(j = 1; j < q; ++j)
		  {
		    if(array[j] > m)
	            m = array[j];		    
		  }
		  return  (double)(array[q] + m)/2;
	       }
	}
}

double do_Median_search(int array[], int begin, int end)
{   
    int midPos = (end - begin + 1) / 2;
    return  Median_search(array, begin, end, midPos);
}
int  main(){
	int  array[] = {0, -2, 11, -4 ,6,12,48,1,-6 };
	int  array1[] = {1,3,2};
	int array2[] = {1,2,3,4};
        int Median =  do_Median_search(array, 0, 8);
	std::cout<<"数组为"<<std::endl;
	for(int i = 0; i <= 8 ; i++){
	std::cout<<array[i]<<""<<std::endl;
	}
	std::cout<<std::endl;
        std::cout<<"数组的中位数为"<< Median<<std::endl;

        int Median1 =  do_Median_search(array1, 0, 2);
	std::cout<<"数组为"<<std::endl;
	for(int i = 0; i <= 2 ; i++){
	std::cout<<array1[i]<<""<<std::endl;
	}
	std::cout<<std::endl;
        std::cout<<"数组的中位数为"<< Median1<<std::endl;


        double Median2=  do_Median_search(array2, 0, 3);
	std::cout<<"数组为"<<std::endl;
	for(int i = 0; i <= 3 ; i++){
	std::cout<<array2[i]<<""<<std::endl;
	}
	std::cout<<std::endl;
        std::cout<<"数组的中位数为"<< Median2<<std::endl;
	
	return  0;
}

