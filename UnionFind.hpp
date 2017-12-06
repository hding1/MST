#ifndef UnionFind_hpp
#define UnionFind_hpp
#include <vector>
#include <stdio.h>
using namespace std;
class UnionFind
{
public:
    //Constructor
    UnionFind(int N);
    //Modifier
    void unite(int p,int q);
    //Observer
    int getCount();
    bool connected(int p, int q);
    int find(int p);
private:
    vector<int> id;
    int count;//components
};
#endif /* UnionFind_hpp */
