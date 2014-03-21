#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#pragma once
template <class T>
struct  Node
{
  T data;
  Node * next;
};

template <class T>
class  LinkQueue
{
  Node<T> * front, * rear,, *q, *p,*x; 
	
   public:
      LinkQueue();
      ~LinkQueue();
      void EnQueue(T x);
      T  DeQueue();
      T  GetQueue();
      bool Empty();
      LinkQueue(int array[], int length);
      void  displayElements();

};
