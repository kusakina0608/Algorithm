//
// Created by Kina on 2020/04/17.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M;
int parent[1024];

int find_set(int x){
    if(parent[x] == -1)
        return x;
    else
        return find_set(parent[x]);
}

void union_set(int x, int y){
    x = find_set(x);
    y = find_set(y);

    parent[y] = x;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int a, b, c;
    vector<pair<int, pair<int, int>>> edge;
    for(int i=0; i<M; i++){
        cin>>a>>b>>c;
        edge.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(edge.begin(), edge.end());
    memset(parent, -1, sizeof(parent));
    int weight=0, v1=0, v2=0, total_weight=0;
    for(int i=0; i<edge.size(); i++){
        weight = edge[i].first;
        v1 = edge[i].second.first;
        v2 = edge[i].second.second;
        if(find_set(v1) != find_set(v2)){
            union_set(v1, v2);
            total_weight += weight;
        }
    }
    cout<<total_weight;
    return 0;
}