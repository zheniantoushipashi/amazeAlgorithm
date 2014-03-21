#include<iostream>
#include<cstring>
#pragma  once
typedef  int keyType;
class  BinTree;
class  BinTreeNode
{
    public: 
	keyType key;
	BinTreeNode* lchild;
	BinTreeNode* rchild;
	BinTreeNode()
	{
	     lchild = NULL;
	     rchild = NULL;
	}
};

class  BinTree
{
    public:
	BinTreeNode* root;
        BinTree()
        {
	root = NULL;   
	}
	~BinTree()
	{
	  //delete root;
	}
	BinTreeNode* BTreeSearch(BinTreeNode * bt, keyType k, BinTreeNode *&p);
	void  BTreeInsert(BinTreeNode *&bt, keyType k);
	int BTreeDelete(BinTreeNode *&bt, keyType k);
	void  BTreePreOrder(BinTreeNode *bt);
	void BTreeInOrder(BinTreeNode *bt);
	void BTreePostOrder(BinTreeNode *bt);
	//void BTreeLevelOrder(BinTreeNode *bt);
	bool  IsEmpty()
	{
	  return  root == NULL;
	};
};

