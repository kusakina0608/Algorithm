//
// Created by Kina on 2020/05/03.
//
#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647
using namespace std;

int N, M, Start, Dest;
vector<pair<int, int>> Edge[1024];
int Dist[1024];

struct compare{
    bool operator()(int a, int b){
        return Dist[a] > Dist[b];
    }
};

void initDist(int start){
    for(int i=1; i<=N; i++){
        Dist[i] = INF;
    }
    Dist[start] = 0;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<M; i++){
        int v1, v2, w;
        cin>>v1>>v2>>w;
        Edge[v1].push_back(make_pair(v2, w));
    }
    cin>>Start>>Dest;
    priority_queue<int, vector<int>, compare> pq;
    pq.push(Start);
    initDist(Start);
    while(!pq.empty()){
        int current_idx = pq.top();
        if(current_idx == Dest) break;
        pq.pop();
        int num_edge = Edge[current_idx].size();
        for(int i=0; i<num_edge; i++){
            int next_idx = Edge[current_idx][i].first;
            int next_weight = Edge[current_idx][i].second;
            if(Dist[next_idx] > Dist[current_idx] + next_weight){
                Dist[next_idx] = Dist[current_idx] + next_weight;
                pq.push(next_idx);
            }
        }
    }
    cout<<Dist[Dest];
    return 0;
}