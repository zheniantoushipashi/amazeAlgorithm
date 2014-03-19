#pragma  once 
template<class  T>
struct Node
{
   T  data;
   Node* next;
};


template <class T>
class  LinkList
{
          Node<T> * head;
	  Node<T> * p;
	public :
          LinkList();
	  LinkList(T a[], int n);
	  ~LinkList();
	  int  ListLength();
	  T Get(int pos);
	  int Locate(T item);
	  void  PrintLinkList();
	  void Insert(int i, T item);
	  T  Delete(int i);
          void Invert();
	  void Merge(LinkList<T>&, LinkList<T>&); 
};


