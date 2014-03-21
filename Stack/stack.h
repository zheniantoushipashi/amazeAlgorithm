#pragma noce
template<class T>
struct  Node
{
   T data;
   Node * next;
};
template<class T>
class  LinkStack
{
          Node<T> * top, *p, *q,*s;
	public:
          LinkStack();
	  LinkStack(T array[], int length);
	  ~LinkStack();
	  void Push(T x);
	  T Pop();
	  T Top();
	  bool  Empty();
	  void displayElements();
};

