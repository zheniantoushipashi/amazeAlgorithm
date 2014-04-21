#ifndef __GRAPH_REALIZE__H_
#define __GRAPH_REALIZE__H_


template<typename vertexNametype, typename weight>
ALGraph<vertexNametype, weight>::ALGraph()
{
    //没做重复顶点处理，因为我需要的数据是从另一个系统所得，已经确保没有重复节点
    if (!m_vertexArray.empty())
    {
        m_vertexArray.clear();
    }
    
}

template<typename vertexNametype, typename weight>
ALGraph<vertexNametype, weight>::~ALGraph()
{
    vector< Vertex< vertexNametype,  weight >  >::iterator iter;
    for(iter = m_vertexArray.begin(); iter != m_vertexArray.end(); iter++)              //删除每个结点的邻接链表
    {
        Edge<weight> *p = iter->pAdjEdges;
        while(NULL != p)  //删除邻接链表
        {
            iter->pAdjEdges = p->pNextEdge;
            delete p;
            p = iter->pAdjEdges;
        }
    }
    if (!m_vertexArray.empty())
    {
        m_vertexArray.clear();
    }
    
}

template<typename vertexNametype, typename weight>
bool ALGraph<vertexNametype, weight>::insertAVertex(IN const vertexNametype vertexName)
{
    int v = getVertexIndex(vertexName);
    if (-1 != v)
    {
        cerr << "There vertex "<<vertexName<<" is existed!" << endl;
        return false;
    }

    Vertex<vertexNametype, weight> VertexInstance(vertexName, NULL);
    m_vertexArray.push_back(VertexInstance);

    return true;
}

template<typename vertexNametype, typename weight>
bool ALGraph<vertexNametype, weight>::insertAEdge(IN const vertexNametype vertexName1, 
                            IN const vertexNametype vertexName2, IN const weight edgeWeight)
{
    int v1 = getVertexIndex(vertexName1);
    if (-1 == v1)
    {
        cerr << "There is no vertex 1" << endl;
        return false;
    }

    int v2 = getVertexIndex(vertexName2);
    if (-1 == v2)
    {
        cerr << "There is no vertex 2" << endl;
        return false;
    }

    Edge<weight> *p = m_vertexArray.at(v1).pAdjEdges;
    while(p != NULL && p->nDestVertex != v2)     //邻接链表是否存在，并且搜索V2是否已经在邻接表中了
    {
        p = p->pNextEdge;
    }

    if (NULL == p)                 //邻接表为空，或没找到顶点V2，则添加一条边
    {
        p = new Edge<weight>(v2, edgeWeight, m_vertexArray.at(v1).pAdjEdges);    
        m_vertexArray.at(v1).pAdjEdges = p;
        return true;
    }
    if (v2 == p->nDestVertex)      //若V1，V2之间已有一条边，则加一条新的边到已存在的第一条V1->V2边之后
    {
        Edge<weight> *q = p;
        p = new Edge<weight>( v2, edgeWeight, q->pNextEdge );
        q->pNextEdge = p;
        return true;
    }
    
    return false;
}

template<typename vertexNametype, typename weight>
bool ALGraph<vertexNametype, weight>::edgeExist(IN const vertexNametype vertexName1, 
                            IN const vertexNametype vertexName2)
{
    int v1 = getVertexIndex(vertexName1);
    if (-1 == v1)
    {
        cerr << "There is no vertex 1" << endl;
        return false;
    }

    int v2 = getVertexIndex(vertexName2);
    if (-1 == v2)
    {
        cerr << "There is no vertex 2" << endl;
        return false;
    }

    Edge<weight> *p = m_vertexArray.at(v1).pAdjEdges;
    while(p != NULL && p->nDestVertex != v2)    
    {
        p = p->pNextEdge;
    }

    if(NULL == p)
    {
        cout<<"dont exist"<<endl;
        return false;
    }
    if(v2 == p->nDestVertex)
    {
        cout<<"exist"<<endl;
        cout << vertexName1 << ":    ";

        while(p != NULL && p->nDestVertex == v2)     //如果v1->v2之间有几条不同的边，都输出
        {
            cout << "(" << vertexName1 << "," << vertexName2 << "," << p->edgeWeight << ")  ";
            p = p->pNextEdge;
        }
        cout << endl;
        return true;
    }
}

template<typename vertexNametype, typename weight>
void ALGraph<vertexNametype, weight>::vertexAdjEdges(IN const vertexNametype vertexName)
{
    int v1 = getVertexIndex(vertexName);
    if( -1 == v1)
    {
        cerr<<"There is no vertex: "<<vertexName<<endl;
        return ;
    }

    Edge<weigh> *p = m_vertexArray.at(v1).pAdjEdges;
    cout << vertexName << ":    ";
    while( p != NULL)
    {
        cout<<"(" << vertexName << "," << getData(p->nDestVertex) <<"," << p->edgeWeight <<") ";
    }
    cout<<endl;
}

template<typename vertexNametype, typename weight>
bool ALGraph<vertexNametype, weight>::removeAEdge(IN const vertexNametype vertexName1, 
                                          IN const vertexNametype vertexName2, IN const weight edgeWeight)
{
    int v1 = getVertexIndex(vertexName1);
    if (-1 == v1)
    {
        cerr << "There is no vertex 1" << endl;
        return false;
    }

    int v2 = getVertexIndex(vertexName2);
    if (-1 == v2)
    {
        cerr << "There is no vertex 2" << endl;
        return false;
    }

    Edge<weight> *p = m_vertexArray.at(v1).pAdjEdges;
    Edge<weight> *q = NULL;                
    while(p != NULL && p->nDestVertex != v2 )
    {
        q = p;
        p = p->pNextEdge;
    }
    if (NULL == p)
    {
        cerr << "Edge is not found" << endl;
        return false;
    }
    while( edgeWeight != p->edgeWeight && p->nDestVertex == v2)    //搜索相同边
    {
        q = p;
        p = p->pNextEdge;
    }
    if (v2 != p->nDestVertex)
    {
        cerr << "Edge is not found" << endl;
        return false;
    }

    if( q == NULL )                                  //m_vertexArray.at(v1).pAdjEdges所指的值即为所求时
        m_vertexArray.at(v1).pAdjEdges = p->pNextEdge;
    else
      q->pNextEdge = p->pNextEdge;                   //这里如果同一条边有好几个相同值，只会删除一次
    delete p;

    return true;
}

template<typename vertexNametype, typename weight>
weight ALGraph<vertexNametype, weight>::getEdgeWeight(IN const Edge<weight> *pEdge)
{
    return pEdge->edgeWeight;
}

template<typename vertexNametype, typename weight>
void ALGraph<vertexNametype, weight>::getVertexEdgeWeight(IN const int v1, OUT vector<weight> &DistanceArray)
{
    Edge<weight> *p = m_vertexArray.at(v1).pAdjEdges;
    int prevIndex = -1;
    weight tmp;

    while(NULL != p)
    {
        //需考虑相同边的存在，取最小的一个值
        if (prevIndex == p->nDestVertex)
        {
            if (tmp > p->edgeWeight)
            {
                DistanceArray[prevIndex] = p->edgeWeight;
            }
        }
        else
        {
            DistanceArray[p->nDestVertex] = p->edgeWeight;
            prevIndex = p->nDestVertex;
            tmp = p->edgeWeight;
        }
        
        p = p->pNextEdge;
    }
}

template<typename vertexNametype, typename weight>
weight ALGraph<vertexNametype, weight>::getMinWeight(IN const vertexNametype vertexName1, 
                                          IN const vertexNametype vertexName2)
{
    Edge<weight> *pEdge = NULL;
    int v1 = getVertexIndex(vertexName1);
    if (-1 == v1)
    {
        cerr << "There is no vertex 1" << endl;
        return false;
    }

    int v2 = getVertexIndex(vertexName2);
    if (-1 == v2)
    {
        cerr << "There is no vertex 2" << endl;
        return false;
    }

    Edge<weight> *p = m_vertexArray.at(v1).pAdjEdges;
    while (p != NULL && p->nDestVertex != v2)
    {
        p = p->pNextEdge;
    }
    if (NULL == p)
    {
        pEdge = NULL;
        return weight(0);
    }
    weight tmp = getEdgeWeight(p);
    pEdge = p;
    while (NULL != p && v2 == p->nDestVertex)   //相同边，取权值最小的一条
    {
        if (tmp > getEdgeWeight(p))
        {
            tmp = getEdgeWeight(p);
            pEdge = p;
        }
        p = p->pNextEdge;
    }
    return tmp;
}

template<typename vertexNametype, typename weight>
int ALGraph<vertexNametype, weight>::getVertexIndex(IN const vertexNametype vertexName)
{
    for (int i = 0; i < m_vertexArray.size(); i++)
    {
        if (vertexName == getData(i))
        {
            return i;
        }
    }
    return -1;
}

template<typename vertexNametype, typename weight>
int ALGraph<vertexNametype, weight>::getVertexNumber()
{
    return m_vertexArray.size();
}

template<typename vertexNametype, typename weight>
vertexNametype ALGraph<vertexNametype, weight>::getData(IN int index)
{
    return m_vertexArray.at(index).vertexName;
}

template<typename vertexNametype, typename weight>
int ALGraph<vertexNametype, weight>::Dijkstra(IN const vertexNametype vertexName1)
{
    int sourceIndex = getVertexIndex(vertexName1);
    if (-1 == sourceIndex)
    {
        cerr << "There is no vertex " << endl;
        return false;
    }
    int nVertexNo = getVertexNumber();

    //the array to record the points have been included, if included the value is true
    //else is false
    vector<bool> vecIncludeArray;
    vecIncludeArray.assign(nVertexNo, false);
    vecIncludeArray[sourceIndex] = true;

    //the array to record the distance from vertex1
    vector<weight> vecDistanceArray;
    vecDistanceArray.assign(nVertexNo, weight(INT_MAX));
    vecDistanceArray[sourceIndex] = weight(0);

    //prev array to record the previous vertex
    vector<int> vecPrevVertex;
    vecPrevVertex.assign(nVertexNo, sourceIndex);

    getVertexEdgeWeight(sourceIndex, vecDistanceArray);

    int vFrom, vTo;

    while(1)
    {
        weight minWeight = weight(INT_MAX);
        vFrom = sourceIndex;
        vTo = -1;
        for (int i = 0; i < nVertexNo; i++)
        {
            if (!vecIncludeArray[i] && minWeight > vecDistanceArray[i])
            {
                minWeight = vecDistanceArray[i];
                vFrom = i;
            }
        }
        if (weight(INT_MAX) == minWeight)
        {
            break;
        }
        vecIncludeArray[vFrom] = true;

        Edge<weight> *p = m_vertexArray[vFrom].pAdjEdges;
        while (NULL != p)
        {
            weight wFT = p->edgeWeight;
            vTo = p->nDestVertex;
            if (!vecIncludeArray[vTo] && vecDistanceArray[vTo] > wFT + vecDistanceArray[vFrom])
            {
                vecDistanceArray[vTo] = wFT + vecDistanceArray[vFrom];
                vecPrevVertex[vTo] = vFrom;
            }
            p = p->pNextEdge;
        }
                
    }

    //print the shortest route of all vertexes
    for (int i = 0; i < nVertexNo; i++)
    {
        if (weight(INT_MAX) != vecDistanceArray[i])
        {
            cout << getData(sourceIndex) << "->" << getData(i) << ": ";
            DijkstraPrint(i, sourceIndex, vecPrevVertex);
            cout << "" << vecDistanceArray[i];
            cout << endl;
        }
    }

    return 0;
}

template<typename vertexNametype, typename weight>  
void ALGraph<vertexNametype, weight>::DijkstraPrint(IN int index, IN int sourceIndex, IN vector<int> vecPreVertex)
{
    if (sourceIndex != index)
    {
        DijkstraPrint(vecPreVertex[index], sourceIndex, vecPreVertex);
    }
    cout << getData(index) << "";
}

template<typename vertexNametype, typename weight>   
ostream& operator<<(OUT ostream &out, IN  ALGraph<vertexNametype,weight> &graphInstance)
{
    int vertexNo = graphInstance.getVertexNumber();
    out << "This graph has " << vertexNo << "vertexes" << endl;

    for(int i = 0; i < vertexNo; i++)
    {
        vertexNametype x1 = graphInstance.getData(i);
        out << x1 << ":    ";

        Edge<weight> *p = graphInstance.m_vertexArray.at(i).pAdjEdges;
        while (NULL != p)
        {
            out << "(" << x1 << "," << graphInstance.getData(p->nDestVertex) << "," << p->edgeWeight << ")  ";
            p = p->pNextEdge;
        }
        out << endl;
    }
    return out;
}

#endif
