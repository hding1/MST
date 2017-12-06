#include "forest.hpp"
#include <limits>
#include <iostream>
vector< vector<Edge> > edgesVertex;
Forest::Forest()
{
    cost = 0;
    cycle = false;
}

void Forest::bid(int node1,int node2, int cost){
    Edge temp;
    temp.u = node1; temp.v = node1; temp.u = node2; temp.weight = cost; temp.mand = false;
    input.edgeSet.push(temp);
    vector<int>::iterator it;
    it = find(input.vertex.begin(),input.vertex.end(),node1);
    if(it==input.vertex.end()){
        input.vertex.push_back(node1);
        cityToIndex[node1] = input.vertex.size()-1;
    }
    it = find(input.vertex.begin(),input.vertex.end(),node2);
    if(it==input.vertex.end()){
        input.vertex.push_back(node2);
        cityToIndex[node2] = input.vertex.size()-1;
    }
    kruskal(input);
}
void Forest::kruskal(Graph G){
    cycle = false;
    cost=0;
    int k = 0;
    result.vertex = G.vertex;
    priority_queue<Edge,vector<Edge>, CompareWeight> empty;
    result.edgeSet.swap(empty);
    priority_queue<Edge,vector<Edge>, CompareWeight> edges = G.edgeSet;
    
    int vSet[input.vertex.size()];
    for(int i=0;i<input.vertex.size();i++){
        vSet[i] = i;
    }
    UnionFind mySet(input.vertex.size());
    for(int i = 0; i<input.mandEdges.size();i++){
        int index1 = cityToIndex[input.mandEdges[i].u];
        int index2 = cityToIndex[input.mandEdges[i].v];
        result.edgeSet.push(input.mandEdges[i]);
        cost+=input.mandEdges[i].weight;
        if(mySet.connected(index1, index2)){
            cycle = true;
        }
        mySet.unite(index1,index2);
    }
    while(!edges.empty()){
        Edge temp = edges.top();
        int index1 = cityToIndex[temp.u];
        int index2 = cityToIndex[temp.v];
        if(!mySet.connected(index1, index2)){
            k++;
            result.edgeSet.push(temp);
            mySet.unite(index1,index2);
            cost+=temp.weight;
        }
        edges.pop();
    }
    component = mySet.getCount();
}
int Forest::getCost(){
    return cost;
}
void Forest::getList(){
    priority_queue<Edge,vector<Edge>, CompareWeight> temp = result.edgeSet;
    while(!temp.empty()){
        cout<<"("<<temp.top().v<<","<<temp.top().u<<") ";
        temp.pop();
    }
    cout<<endl;
}
bool Forest::getCycle(){
    return cycle;
}
int Forest::getComponent(){
    return component;
}
void Forest::mandatory(int node1,int node2,int cost){
    Edge temp;
    temp.u = node1; temp.v = node1; temp.u = node2; temp.weight = cost;
    input.mandEdges.push_back(temp);
    vector<int>::iterator it;
    it = find(input.vertex.begin(),input.vertex.end(),node1);
    if(it==input.vertex.end()){
        input.vertex.push_back(node1);
        cityToIndex[node1] = input.vertex.size()-1;
    }
    it = find(input.vertex.begin(),input.vertex.end(),node2);
    if(it==input.vertex.end()){
        input.vertex.push_back(node2);
        cityToIndex[node2] = input.vertex.size()-1;
    }
    kruskal(input);
}
void Forest::shortestPath(int start, int end){
    edgesVertex.clear();
    int num[input.vertex.size()];
    for(int i = 0; i<input.vertex.size(); i++){
        num[i] = 0;
    }
    int sum = numeric_limits<int>::max();
    vector<Edge> min;
    vector<Edge> edgesSum;
    shortestPathHelper(start, end, edgesSum, num);
    for(int i=0;i<edgesVertex.size();i++){
        int tempMin = 0;
        for(int j=0;j<edgesVertex[i].size();j++){
            tempMin+=edgesVertex[i][j].weight;
        }
        if(tempMin<sum){
            sum = tempMin;
            min = edgesVertex[i];
        }
    }
    for(int i=0;i<min.size();i++){
        if(i==0){
            cout<<min[i].u<<" ";
        }
        cout<<min[i].v<<" ";
    }
    cout<<endl;
}
void Forest::shortestPathHelper(int start, int end, vector<Edge> sum, int num[]){
    if(start == end){
        edgesVertex.push_back(sum);
    }
    vector<Edge> tempEdge = findAllPathFrom(start);
    for(int i=0;i<tempEdge.size();i++){
        Edge temp = tempEdge[i];
        if(num[cityToIndex[temp.v]]==0){
            sum.push_back(temp);
            num[cityToIndex[temp.u]]=1;
            num[cityToIndex[temp.v]]=1;
            shortestPathHelper(temp.v, end, sum, num);
        }
    }
}
vector<Edge> Forest::findAllPathFrom(int vertexNum){
    vector<Edge> edgesNum;
    priority_queue<Edge,vector<Edge>, CompareWeight> temp = input.edgeSet;
    while(!temp.empty()){
        Edge tempEdge = temp.top();
        if(tempEdge.u==vertexNum || tempEdge.v==vertexNum){
            if(tempEdge.v==vertexNum){
                int swap = tempEdge.u;
                tempEdge.u = tempEdge.v;
                tempEdge.v = swap;
            }
            edgesNum.push_back(tempEdge);
        }
        temp.pop();
    }
    return edgesNum;
}

