#include<iostream>
using  namespace  std;
int  main()
{
   char  name[20], addr[50];
   cout << "请输入你的姓名" << endl;
   cin.getline(name, 20);
   cout << "请输入你的网址" << endl;
   cin.getline(addr, 20);
   cout << " 你的姓名为" << name <<endl <<"网址"<< addr << endl;
   return  0;
}	
