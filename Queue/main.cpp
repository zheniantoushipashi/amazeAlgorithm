#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"queue.h"
#include"queue_implements.h"
using  namespace  std;
int main()
{
   int a[] = {1,24,-2,7,4,91,-9,48,9};
   LinkQueue<int> * lq = new LinkQueue<int>(a, 9);
   lq -> displayElements();
   cout << "队列头出列"<<endl;
   lq -> DeQueue();
   cout << "数组为"<<endl;
   lq -> displayElements();
   cout << "数组是否为空"<< endl << (lq -> Empty() == 0) ? "为空" : "不为空" ;
}
