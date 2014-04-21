#include <iostream>
#include <ctime>
#include <string>
#include "ALGraph.h"

using namespace std;
using namespace graphspace;

int main()
{
    ALGraph<string, int> g;
    clock_t start1,finish1;
    double duration;

    
    g.insertAVertex("A");
    g.insertAVertex("B");
    g.insertAEdge("A", "B", 16);
    g.insertAEdge("A", "B", 26);
    g.insertAEdge("A", "B", 36);
    g.insertAEdge("A", "B", 46);
    g.insertAEdge("A", "B", 6);

    g.insertAVertex("C");
    g.insertAVertex("D");
    g.insertAVertex("E");
    g.insertAVertex("F");
    cout<<g<<endl<<endl;

    g.insertAEdge("A", "B", 6);
    g.insertAEdge("A", "C", 3);
    g.insertAEdge("B", "C", 2);
    g.insertAEdge("B", "D", 5);
    g.insertAEdge("C", "D", 3);
    g.insertAEdge("C", "E", 4);
    g.insertAEdge("D", "E", 2);
    g.insertAEdge("D", "F", 3);
    g.insertAEdge("E", "F", 5);


    g.insertAEdge("B", "A", 6);
    g.insertAEdge("C", "A", 3);
    g.insertAEdge("C", "B", 2);
    g.insertAEdge("D", "B", 5);
    g.insertAEdge("D", "C", 3);
    g.insertAEdge("E", "C", 4);
    g.insertAEdge("E", "D", 2);
    g.insertAEdge("F", "D", 3);
    g.insertAEdge("F", "E", 5);

    cout<<g<<endl<<endl;

    g.Dijkstra("A");
    
    /*
    char vertex[9];
    srand((unsigned)time(0));
    string str[10000];

    for(int i=0; i<10000; i++)      //随机生成1 W个顶点
    {
        for(int j=0; j<8; j++)
        {
            vertex[j] = rand()%26 + 97;
            str[i] += vertex[j];
        }
        g.insertAVertex(str[i]);
    }
    cout<<g<<endl<<endl;

    for(int i=0; i<100000; i++)    //随机生成10W条边
    {
        int num1 = rand()%10000;
        int num2 = rand()%10000;
        int num3 = rand()%10;
        g.insertAEdge(str[num1], str[num2], num3);
    }

    string lastname = "test";
    g.insertAVertex(lastname);
    for(int i=0; i<5000; i++)     //单个顶点关联的边并不多，这里单独加一个顶点，关联5K条边
    {
        int num5 = rand()%10000;
        int num6 = rand()%10000;
        g.insertAEdge(lastname, str[num5], num6);
    }
    cout<<g<<endl<<endl;
    
    string vertex1;
    string vertex2;
    cout<<"entry 2 vertem name"<<endl;
    cin>>vertex1;
    cin>>vertex2;
    while(vertex1 != "q")
    {
        start1 = clock();
        g.edgeExist(vertex1, vertex2);
        finish1 = clock();
        duration = (double)(finish1 - start1) / CLOCKS_PER_SEC; 
        cout<<duration<<" seconds"<<endl;
        cout<<"entry 2 vertem name"<<endl;
        cin>>vertex1;
        cin>>vertex2;
    }
    */
    system("pause");
    return 0;
}
