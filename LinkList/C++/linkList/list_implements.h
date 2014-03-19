#include<stdio.h>
#include<stdlib.h>
#include"list.h"
#include<iostream>
template <class T>
LinkList<T>::LinkList()
{
   head = new Node<T>; 
   head -> next = NULL;
}	


template <class T>
LinkList<T>::LinkList(T a[], int n)
{
   head = new Node<T>;
   Node<T>* r = head;
   for(int i = 0; i < n; i++)
   {
    Node<T>*  s = new Node<T>;
      s-> data = a[i];
      r->next = s;
      r = s;
   }
   r->next = NULL;
}


template<class T>
int LinkList<T>::ListLength()
{
 int  num = 0;
 Node<T>* p = head->next;
  while(p)
   {
     p = p-> next;
     num++;
   }	  
  return  num;
}

template<class T>
T LinkList<T>::Get(int pos)
{
  Node<T>* p = head->next;
   int   j = 1;
   while(p && j < pos)
   {
      p = p->next;
      j++;
   }
   if(!p)
   {
	   std::cerr<<"查找位置非法";
           exit(1);
    }
    else{
      return p-> data;
    }

}


template<class T>
int LinkList<T>::Locate(T item)
{
    Node<T>* p = head->next;
    int	j = 1;
	while(p && p->data != item)
	{
	  p = p->next;
	  j++;
	}
	if(p)
	  return  j;
	else  
           return 0;
}

template<class T>
void   LinkList<T>::PrintLinkList()
{
   Node<T>*    p = head->next;
    while(p)
    {
	    std::cout << p->data << std::endl;
       p = p->next;
    }
}


template<class T>
void LinkList<T>::Insert(int i, T item)
{
  Node<T>*  p = head;
  int  j = 0;
   while(p && j < i-1)
   {
      p = p->next;
      j++;
   }
   if(!p)
   {
	   std::cerr<<"插入位置非法";
     exit(1);
   }
   else
   {
     Node<T>* s = new Node<T>;
     s->data = item;
     s->next = p->next;
     p->next = s;
   }
}


template<class T>
T LinkList<T>::Delete(int i)
{
Node<T>*   p = head;
 int  j = 0;
   while(p && j < i - 1)
   {
       p = p->next;
       j++;
   }
   if(!p||!p->next)
   {
	   std::cerr<<"删除位置非法"<<std::endl;
      exit(1);
   }
   else
   {
   Node<T>*    q = p->next;
     int  x = q->data;
     p->next = q->next;
     delete q;
     return x;
   }
}
template<class T>
LinkList<T>::~LinkList()
{
  Node<T>  p = head;
    while(p)
    {
    Node<T>  q = p;
      p = p->next;
      delete q;
    }
    head = NULL;
}


template<class T>
void LinkList<T>::Invert()
{
   p = head->next;
   head->next = NULL;
   while(p != NULL)
   {
     Node<T>* q = p;
     p = p->next;
     q->next = head->next;
     head->next = q;
   } 
}

template<class T>
void LinkList<T>::Merge(LinkList& L1, LinkList& L2)
{
  Node<T>* p1 = L1.head -> next;
  Node<T>* p2 = L2.head -> next;
  Node<T>* p3 = L1.head;
  while((p1 != NULL) && (p2 != NULL))
  {
    if((p1 -> data) < (p2 -> data))
    {
      p3 -> next = p1;
      p1 = p1 -> next;
      p3 = p3 -> next;
    }
    else
    {
      p3 -> next = p2;
      p2 = p2 -> next;
      p3 = p3 -> next;
    }
  }
  if(p1 != NULL) p3 -> next = p1;
  if(p2 != NULL) p3 -> next = p2;
  delete L2.head;
  L2.head = NULL;
}





































