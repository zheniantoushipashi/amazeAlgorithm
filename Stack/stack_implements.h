#include<stdio.h>
#include<stdlib.h>
#include<iostream>
template<class T>
LinkStack<T>::LinkStack()
{
   top = NULL;
};
template<class T>
void LinkStack<T>::Push(T x)
{
   s = new Node<T>;
   s -> data = x;
   s -> next = top;
   top = s;
};


template<class T>
LinkStack<T>::LinkStack(T array[], int  length)
{
    top = NULL;
    for(int i= 0; i < length; i++)
    {
        Push(array[i]);
    }
};

template<class T>
void LinkStack<T>::displayElements()
{   
    if(top == NULL)
    {
      std::cerr<<"你打印的stack is NULL"<<std::endl;
    }
    p = top;
    while(p)
    {  
       std::cout << p -> data<<std::endl; 
       p = p -> next;
    }
};
template<class T>
T LinkStack<T>::Pop()
{
   if(top == NULL)
   {
	   std::cerr<<"下溢"<<std::endl;
	   exit(1);
   }
   int  x = top -> data;
   p = top;
   top = top -> next;
   delete p;
   return x;
};

template<class T>
T  LinkStack<T>::Top()
{
   if(top == NULL)
   {
     std::cerr<<"下溢"<<std::endl;
     exit(1);
   }
   return top -> data;
};

template<class T>
bool LinkStack<T>::Empty()
{
   return top == NULL;
};

template <class T>
LinkStack<T>::~LinkStack()
{
   p = top();
   while(p)
   {
     q = p;
     p = p -> next;
     delete q;
   }
   top = NULL;
};






























