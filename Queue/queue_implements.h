#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"queue.h"
template<class T>
LinkQueue<T>::LinkQueue()
{
   Node<T> * s = new Node<T>;
    s -> next = NULL;
    front = rear = s;
}
template<class T>
void LinkQueue<T>::EnQueue(T x)
{
   Node<T>* s = new Node<T>;
   s -> data = x;
   s -> next = NULL;
   rear -> next = s;
   rear = s;
}
template<class T>
T LinkQueue<T>::DeQueue()
{
   if(rear == front)
   {
      std::cerr<<"下溢"<<std::endl;
      exit(1);
   }
   Node<T>* p = front -> next;
   T  x = p -> data;
   front -> next = p -> next;
   if(p -> next == NULL)
   {
     rear = front;
   }
   delete p;
   return x;
}
template<class T>
T LinkQueue<T>::GetQueue()
{
   if(rear == front)
   {
      std::cerr<<"下溢"<<std::endl;
      exit(1);
   }
   Node<T> *p = front -> next;
   T x = p -> data;
   return x;
}
template<class T>
bool LinkQueue<T>::Empty()
{
	return front == rear;
}
template<class T>
LinkQueue<T>::LinkQueue(int array[], int length)
{  
   Node<T> * s = new Node<T>;
   s -> next = NULL;
   front = rear = s; 
 
   for(int i = 0; i < length; i++)
   {
      EnQueue(array[i]);
   }
}
template<class T>
void LinkQueue<T>::displayElements()
{
   Node<T>* p = front -> next;
   while(p)
   {
      std::cout << p -> data <<  std::endl;
      p = p -> next;
   }
}





















