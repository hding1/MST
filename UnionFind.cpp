#include "UnionFind.hpp"
UnionFind::UnionFind(int N){
    count = N;
    for(int i=0;i<N;i++){
        id.push_back(i);
    }
}

int UnionFind::getCount(){
    return count;
}

bool UnionFind::connected(int p,int q){
    return find(p) == find(q);
}

int UnionFind::find(int p){
    return id[p];
}

void UnionFind::unite(int p,int q){
    int pID = find(p);
    int qID = find(q);
    if(pID == qID)
        return;
    for(int i = 0; i<id.size();i++){
        if(id[i]==pID)
            id[i] = qID;
    }
    count--;
}
