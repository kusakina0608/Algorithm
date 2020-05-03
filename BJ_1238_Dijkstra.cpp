//
// Created by Kina on 2020/05/02.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define V_MAX 1024
#define INF 2147483647
using namespace std;

int N, M, X;
int start, dest, weight;

int partyWeightSum[V_MAX];
bool partyVisited[V_MAX];

int homeWeightSum[V_MAX];
bool homeVisited[V_MAX];

vector<pair<int, int>> party_edge[V_MAX];
vector<pair<int, int>> home_edge[V_MAX];

struct cmp{
    bool operator()(pair<int, int> a,  pair<int, int> b){
        return a.second > b.second;
    }
};


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>X;
    for(int edge_idx=0; edge_idx<M; edge_idx++){
        cin>>start>>dest>>weight;
        party_edge[start].push_back(make_pair(dest, weight));
        home_edge[dest].push_back(make_pair(start, weight));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> partyPq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> homePq;
    for (int i = 1; i <= N; i++) {
        if(i==X) {
            partyPq.push(make_pair(X, 0));
            homePq.push(make_pair(X, 0));
        }
        else {
            partyWeightSum[i] = INF;
            homeWeightSum[i] = INF;
        }
    }

    while (!partyPq.empty()) {
        int current = partyPq.top().first;
        partyPq.pop();
        for (pair<int, int> p : party_edge[current]) {
            int next = p.first;
            int next_weight = partyWeightSum[current] + p.second;
            if (!partyVisited[next]) { // 방문하지 않았으면
                if (partyWeightSum[next] > next_weight) {
                    partyWeightSum[next] = next_weight;
                    partyPq.push(make_pair(next, next_weight));
                }
            }
        }
        partyVisited[current] = true;
    }

    while (!homePq.empty()) {
        int current = homePq.top().first;
        homePq.pop();
        for (pair<int, int> p : home_edge[current]) {
            int next = p.first;
            int next_weight = homeWeightSum[current] + p.second;
            if (!homeVisited[next]) { // 방문하지 않았으면
                if (homeWeightSum[next] > next_weight) {
                    homeWeightSum[next] = next_weight;
                    homePq.push(make_pair(next, next_weight));
                }
            }
        }
        homeVisited[current] = true;
    }
    int max=-1;
    for(int i=1; i<=N; i++){
        //cout<<i<<"번 학생은 파티갈때: "<<partyWeightSum[i]<<", 집에올때: "<<homeWeightSum[i]<<endl;
        int tmp = partyWeightSum[i] + homeWeightSum[i];
        if(max<tmp) max=tmp;
    }
    cout<<max;
    return 0;
}