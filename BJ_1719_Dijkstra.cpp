//
// Created by Kina on 2020/05/03.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2147483647
using namespace std;
int N, M;

vector<pair<int, int>> Edge[256];
int Path[256][256];
int Weight[256];

struct compare{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

void initWeight(int start){
    for(int i=1; i<=N; i++){
        Weight[i] = INF;
    }
    Weight[start] = 0;
    return;
}

void showResult(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j){
                cout<<'-'<<' ';
            }else{
                cout<<Path[j][i]<<' ';
            }
        }
        cout<<'\n';
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int v1, v2, weight;
    for(int i=0; i<M; i++){
        cin>>v1>>v2>>weight;
        Edge[v1].push_back(make_pair(v2, weight));
        Edge[v2].push_back(make_pair(v1, weight));
    }
    for(int start=1; start<=N; start++){
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        initWeight(start);
        pq.push(make_pair(start, 0));
        while(!pq.empty()){
            int current_idx = pq.top().first;
            int current_weight = pq.top().second;
            pq.pop();
            int num_edge = Edge[current_idx].size();
            for(int i=0; i<num_edge; i++){
                int next_idx = Edge[current_idx][i].first;
                int next_weight = Edge[current_idx][i].second;
                if(Weight[next_idx] > Weight[current_idx] + next_weight){
                    Path[start][next_idx] = current_idx;
                    Weight[next_idx] = Weight[current_idx] + next_weight;
                    pq.push(make_pair(next_idx, Weight[next_idx]));
                }
            }
        }
    }
    showResult();
    return 0;
}