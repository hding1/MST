#ifndef forest_hpp
#define forest_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include "UnionFind.hpp"
using namespace std;
typedef struct
{
    int u;//start
    int v;//end
    int weight;
    bool mand;
}Edge;
struct CompareWeight {
    bool operator()(Edge const & e1, Edge const & e2) {
        return e1.weight > e2.weight;
    }
};
typedef struct
{
    vector<int> vertex;
    vector<Edge> mandEdges;
    priority_queue<Edge,vector<Edge>, CompareWeight> edgeSet;
}Graph;

class Forest
{
public:
    //Constructor
    Forest();
    //Modifier
    void bid(int node1,int node2, int cost);
    void mandatory(int node1,int node2,int cost);
    //Observer
    int getCost();
    int getComponent();
    bool getCycle();
    void getList();
    void shortestPath(int start, int end);
private:
    void kruskal(Graph G);
    vector<Edge> findAllPathFrom(int vertexNum);
    void shortestPathHelper(int start, int end, vector<Edge> sum,int num[]);
    int cost;
    bool cycle;
    Graph input;
    Graph result;
    int component;
    map<int,int> cityToIndex;
};
#endif /* forest_hpp */
