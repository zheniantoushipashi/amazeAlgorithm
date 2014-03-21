#include "BTree.h"
#include<stdio.h>
#include<iostream>
BinTreeNode* BinTree::BTreeSearch(BinTreeNode* bt, keyType k, BinTreeNode * &p)
{
    BinTreeNode * q = NULL;
    q = bt;
    while(q)
    {
       p = q;
       if(q -> key == k)
       {
          return (p);
       }
       if(q -> key > k)
	 q = q -> lchild;
       else 
         q = q -> rchild;
    }
    return NULL;
}

void  BinTree::BTreeInsert(BinTreeNode *&bt, keyType k)
{
   BinTreeNode * p = NULL, *q;
   q = bt;
   if(BTreeSearch(q, k, p) == NULL)
   {
       BinTreeNode * r = new BinTreeNode;
       r -> key =k;
       r -> rchild = r -> rchild = NULL;
       if(q == NULL)
       {
         bt = r;
       }
       if(p && k < p -> key)
         p -> lchild = r;
       else if(p)
	 p -> rchild = r;      
   }
}

/*******
 *
 *
 *中序遍历
 *
 */

void  BinTree::BTreePreOrder(BinTreeNode * bt)
{
   if(bt != NULL)
   {
      std::cout << bt -> key <<""<<std::endl;
      BTreePreOrder(bt -> lchild);
      BTreePreOrder(bt -> rchild);
   }
}

void  BinTree::BTreeInOrder(BinTreeNode * bt)
{
    if(bt != NULL)
    {
       BTreeInOrder(bt -> lchild);
       std::cout<<bt->key<<""<<std::endl;
       BTreeInOrder(bt -> rchild);
    }
}

void BinTree::BTreePostOrder(BinTreeNode * bt)
{
    if(bt != NULL)
    {
       BTreePostOrder(bt -> lchild);
       BTreePostOrder(bt -> rchild);
       std::cout<<bt->key<<""<<std::endl;
    }
}
int  BinTree::BTreeDelete(BinTreeNode * &bt, keyType k)
{
    BinTreeNode * f, *p, *q, *s;
    p = bt;
    f = NULL;
    while(p && p -> key != k)
    {
       f = p;
       if(p -> key > k)
	  p = p -> lchild;
       else
	  p = p -> rchild;     
    }
    if(p == NULL)
        return  0;
    if(p ->  lchild == NULL)
    {
       if(f == NULL)
	  bt = p -> rchild;
       else if(f -> lchild == p)
	  f -> lchild = p -> rchild;
       else  
	  f -> rchild = p -> rchild;     
    }
    else 
    {
        q = p;
	s = p -> lchild;
	while(s -> rchild)
	{
	   q = s;
	   s = s -> rchild;
	}
	if(q == p)
	   q -> lchild = s -> lchild;
	else
	   q -> rchild = s -> lchild;
	p -> key = s -> key;
	delete  s;
    }
    return  1;
}




























