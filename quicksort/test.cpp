
#include "stdio.h"
#include <iostream>

using  namespace  std;

int  Partition(int  r[], int i , int j){

  int   temp = r[i];
  while(i <j) {
	  while( i< j && r[j] >= temp) j--;
	  if(i < j) r[i++ ]= r[j];
	  while(i < j && r[i] <temp)  i ++;
	  if(i<j) r[j--] = r[i];

   }
	  r[i] = temp;
	  return i;

}

 
void  QuickSort(int  a[], int p, int r){
	if(p < r){
	  int  q = Partition(a, p, r);
	  QuickSort(a, p, q-1);
	  QuickSort(a, q+1, r);
	
	}

}
int  main(){
	int  array[] = {0, -2, 11, -4 ,6,12,48,1,-6 };
	QuickSort(array, 0 , 7);
	for(int i = 0; i <= 7 ; i++){
	std::cout<<array[i]<<"";
	std::cout<<std::endl;
	}
	return  0;
}
 
