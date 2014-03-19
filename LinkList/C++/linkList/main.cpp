#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<iostream>
#include"list.h"
#include"list_implements.h"
int main()
{
   int a[] = {1,9,3,5,19,38,29,2,4,25,61,-1,7};
   LinkList<int>* list = new LinkList<int>(a, 13);
   list->PrintLinkList();
   int listlength = list->ListLength();
   std::cout<<"the list length is"<<listlength<<std::endl;
   int theLastElement = list->Get(13);
   assert(theLastElement == 7);
   std::cout<<"the last  element value   is"<< theLastElement << std::endl;
   std::cout<<"the values  that  the  array  contained currently display"<<std::endl;
   list->PrintLinkList();
   std::cout<<std::endl;
   std::cout<<"delete the  eigth element 2";
   std::cout<<std::endl;
   list->Delete(8);
   std::cout<<"the values  that  the  array  contained currently display"<<std::endl;
   std::cout<<"the  position of 61 is";
   std::cout<<std::endl;
   int position = list->Locate(61);
   std::cout<<std::endl;
   std::cout<<position<<std::endl;
   std::cout<<"the values  that  the  array  contained currently display"<<std::endl;
   list->PrintLinkList();
   std::cout<<std::endl;
    std::cout<<"now we add a value  at first  position"<<std::endl;
   list->Insert(1, 11111);
   std::cout<<"the values  that  the  array  contained currently display"<<std::endl;
   list->PrintLinkList();
   std::cout<<std::endl;
   list->Invert();
   std::cout<<"the  invert  array list is"<<std::endl;
   list->PrintLinkList();
}


