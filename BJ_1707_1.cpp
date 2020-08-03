//
// Created by Kina on 2020/05/03.
//
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int K, V, E;

bool bfs(vector<int>* edge, int* color, int idx){
    color[idx] = 1;
    queue<int> q;
    q.push(idx);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i<edge[cur].size(); i++){
            if(color[edge[cur][i]] == color[cur]){
                return false;
            }
            if(color[edge[cur][i]]==0) {
                color[edge[cur][i]] = 3 - color[cur];
                q.push(edge[cur][i]);
            }
        }
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>K;
    for(int test_case=0; test_case<K; ++test_case){
        cin>>V>>E;
        vector<int>* edge = new vector<int>[V+1];
        int* color = new int[V+1];
        memset(color, 0, sizeof(int)*(V+1));
        string res = "YES\n";
        int v1, v2;
        for(int i=0; i<E; i++){
            cin>>v1>>v2;
            edge[v1].push_back(v2);
            edge[v2].push_back(v1);
        }
        for(int i=1; i<=V; i++) {
            if(color[i]==0){
                if(!bfs(edge, color, i)) {
                    res="NO\n"; break;
                }
            }
        }
        cout<<res;
        delete[] color;
        delete[] edge;
    }
    return 0;
}
