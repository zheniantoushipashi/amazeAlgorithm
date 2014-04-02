#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#define  x  9999
#define  max  9999
int data[10][10];
int dist[10];
int path[10];
int  kmin(int , int)
void  fpath(int a[][10]);
int   froute(int a[][10]);
  

void  main()
{
      int  i, m;
      int  a[10][10] = {
       {x,4,2,3,x,x,x,x,x,x},
       {x,x,x,x,10,9,x,x,x,x},
       {x,x,x,x,6,7,10,x,x,x},
       {x,x,x,x,x,3,8,x,x,x},
       {x,x,x,x,x,x,x,4,8,x},
       {x,x,x,x,x,x,x,9,6,x},
       {x,x,x,x,x,x,x,5,4,x},
       {x,x,x,x,x,x,x,x,x,8},
       {x,x,x,x,x,x,x,x,x,4},
       {x,x,x,x,x,x,x,x,x,x}};
      fpath(a);
      std::cout<<"最短路径大小为"<<
}
