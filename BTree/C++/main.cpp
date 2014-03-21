#include<stdio.h>
#include "BTree.h"
#include "BTree_implements.h"
#include <iostream>
#define  NUM  19
int main()
{
   int a[] = {1,-2,9,4,17,72,24,15,41,23,2,3,5,90,22,12,14,6,7};
   int i;
   BinTree  bt;
   BinTreeNode * btn =  NULL, *p = NULL, *pT = NULL;
   for(i = 0; i < NUM; i++)
   {
      bt.BTreeInsert(btn, a[i]);     
   }
   bt.BTreePreOrder(btn);
   BinTreeNode * btnSearch = NULL;
   BinTreeNode  *  searchResult = bt.BTreeSearch(btn, 24, btnSearch);
   std::cout<< "the  search result  value  is"<<std::endl;
   std::cout << searchResult->key<<std::endl;
 //  std::cout <<"we  now  delete the value 15"<<std::endl;
//   bt.BTreeDelete(btn, 15);
   std::cout <<"the value  the Tree  contained  display"<<std::endl;
   bt.BTreePreOrder(btn);
   std::cout<<"先序遍历"<<std::endl;;
   bt.BTreePreOrder(btn);
   std::cout<<"中序遍历"<<std::endl;;
    bt.BTreeInOrder(btn);
   std::cout<<"后序遍历"<<std::endl;;
   bt.BTreePostOrder(btn);

}


