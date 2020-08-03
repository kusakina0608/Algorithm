//
// Created by Kina on 2020/02/18.
//
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void dfs(vector<int>* edge, bool* check, int index){
    check[index]=true;
    for(int i=0; i<edge[index].size(); i++){
        int x=edge[index][i];
        if(check[x]==false){
            dfs(edge, check, x);
        }
    }
}

int main(void){
    int n_vertex, n_edge;
    scanf("%d %d", &n_vertex, &n_edge);
    vector<int>* edge= new vector<int>[n_vertex+1];
    for(int i=0; i<n_edge; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        edge[v1].push_back(v2);
        edge[v2].push_back(v1);
    }

    bool* check=new bool[n_vertex+1];
    memset(check, false, sizeof(bool)*(n_vertex+1));
    int count=0;
    for(int i=1; i<=n_vertex; i++){
        if(check[i]==false){
            count++;
            dfs(edge, check, i);
        }
    }
    cout<<count<<endl;
    delete[] check;
    delete[] edge;
    return 0;
}