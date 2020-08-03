//
// Created by Kina on 2020/04/17.
//
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>

using namespace std;

int V, E;
int parent[10050];

class Edge{
private:
    int v1, v2;
    int weight;
public:
    Edge() : v1(0), v2(0), weight(0) { }
    Edge(int v1, int v2, int weight)
            : v1(v1), v2(v2), weight(weight) { }
    friend bool cmp(const Edge e1, const Edge e2);
    friend ostream& operator<<(ostream& os, Edge& e);
    int getV1() const { return v1; }
    int getV2() const { return v2; }
    int getWeight() const { return weight; }
};
bool cmp(const Edge e1, const Edge e2){
    return e1.weight<e2.weight;
}
ostream& operator<<(ostream& os, Edge& e){
    os<<'['<<e.v1<<", "<<e.v2<<']';
    return os;
}

int find(int x){
    if(parent[x]==-1)
        return x;
    else
        return find(parent[x]);
}

void union_set(int x, int y){
    x = find(x);
    y = find(y);

    parent[y] = x;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>V>>E;
    vector<Edge> edge;
    vector<int>* elist = new vector<int>[V];
    int a, b, c;
    for(int i=0; i<E; i++){
        cin>>a>>b>>c; // vertex1, vertex2, weight
        edge.push_back(Edge(a, b, c));
    }
    sort(edge.begin(), edge.end(), cmp);
    // Kruskal
    int weightSum=0;

    memset(parent, -1, sizeof(parent));
    int v1, v2;
    for(int i=0; i<edge.size(); i++){
        v1 = edge[i].getV1();
        v2 = edge[i].getV2();
        if(find(v1)!=find(v2)){
            union_set(v1, v2);
            weightSum += edge[i].getWeight();
        }
    }
    cout<<weightSum;
    return 0;
}