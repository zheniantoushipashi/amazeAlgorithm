#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>

#define  IN
#define OUT
#define INOUT

using namespace std;

namespace graphspace
{
    template <typename weight>
    struct Edge                        //边
    {
       int nDestVertex;               //邻接顶点编号
        weight edgeWeight;             //边权重
        Edge<weight> *pNextEdge;       //下一条边

        Edge(int d, weight c, Edge<weight> *p = NULL)
            :nDestVertex(d), edgeWeight(c), pNextEdge(p)
        {}
    };

    template <typename vertexNametype, typename weight>
    struct Vertex                      //顶点
    {
        vertexNametype vertexName;     //顶点名
        Edge<weight> *pAdjEdges;       //邻接边链表

        Vertex(vertexNametype x, Edge<weight> *p = NULL)
            :vertexName(x), pAdjEdges(p)
        {}
    };

    //adjacency list based graph
    template <typename vertexNametype, typename weight>
    class ALGraph
    {
    public:
        explicit ALGraph();
         ~ALGraph();

   

    public:
        
        //插入结点
        bool insertAVertex(IN const vertexNametype vertexName); 

        //插入边
        bool insertAEdge(IN const vertexNametype vertexName1, IN const vertexNametype vertexName2, IN const weight edgeWeight);

        //边是否存在
        bool edgeExist(IN const vertexNametype vertexName1, IN const vertexNametype vertexName2);

        //输出顶点的邻接表
        void vertexAdjEdges(IN const vertexNametype vertexName);

        //删除边
        bool removeAEdge(IN const vertexNametype vertexName1, IN const vertexNametype vertexName2, IN const weight edgeWeight);

        //获取最小权
        weight getMinWeight(IN const vertexNametype vertexName1, IN const vertexNametype vertexName2);

        //获取顶点索引
        int getVertexIndex(IN const vertexNametype vertexName);

        //获取顶点数
        int getVertexNumber();

        //获取顶点名
        vertexNametype getData(IN int index);

        //迪科斯彻算法，最短路径
        int Dijkstra(IN const vertexNametype vertexName1);

        //输出迪科斯彻
        void DijkstraPrint(IN int index, IN int sourceIndex, IN vector<int> vecPreVertex);

        friend ostream& operator<<(OUT ostream &out, IN const ALGraph<vertexNametype,weight> &graphInstance);   

    public:
        
        //获取边权
        weight getEdgeWeight(IN const Edge<weight> *pEdge);

        //将顶点的所有邻接边的权值放入数组或者vector中
        void getVertexEdgeWeight(IN const int v1, OUT vector<weight> &DistanceArray);

        vector< Vertex<vertexNametype, weight> > m_vertexArray;
    };

#include "ALGraph_realize.h"

}

#endif
