//
// Created by Kina on 2020/02/18.
//
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int>* vec, bool* check, int start_v){
    check[start_v]=true;
    printf("%d ", start_v);
    for(int i=0; i<vec[start_v].size(); i++){
        int x=vec[start_v][i];
        if(check[x]==false){
            dfs(vec, check, x);
        }
    }
}

void bfs(vector<int>* vec, bool* check, int start_v){
    queue<int> q;
    check[start_v]=true;
    q.push(start_v);
    while(!q.empty()){
        int x=q.front(); q.pop();
        printf("%d ", x);
        for(int i=0; i<vec[x].size(); i++){
            int y=vec[x][i];
            if(check[y]==false){
                check[y]=true;
                q.push(y);
            }
        }
    }
}

int main(void){
    int n_vertex, n_edge, start_v;
    scanf("%d %d %d", &n_vertex, &n_edge, &start_v);
    vector<int>* vec=new vector<int>[n_vertex+1];
    for(int i=0; i<n_edge; i++){
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        vec[n1].push_back(n2);
        vec[n2].push_back(n1);
    }
    for(int i=1; i<=n_vertex; i++){
        sort(vec[i].begin(), vec[i].end());
    }
    bool* check=new bool[n_vertex+1];
    memset(check, false, sizeof(bool)*(n_vertex+1));
    dfs(vec, check, start_v);
    cout<<endl;
    memset(check, false, sizeof(bool)*(n_vertex+1));
    bfs(vec, check, start_v);
    delete[] vec;
    delete[] check;
    return 0;
}