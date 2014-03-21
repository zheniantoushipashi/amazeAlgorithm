#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"stack.h"
#include"stack_implements.h"
int main()
{
   int  a[] = {1,4,2,10,-1,-5,57,91,8,-3,9};
   LinkStack<int>*  ls = new  LinkStack<int>(a, 11);
   ls -> displayElements();  
   std::cout<<"now  we  push  the value 1112"<<std::endl;
   ls -> Push((int)1112);
   std::cout<<"the stack now is"<<std::endl;
   ls -> displayElements();
   std::cout<<"we  pop is top element"<<std::endl;
   ls -> Pop();
   std::cout<<"the stack now is"<<std::endl;
   ls -> displayElements();
   std::cout<<"the top  value is"<<ls -> Top() << std::endl;
}

