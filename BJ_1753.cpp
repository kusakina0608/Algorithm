//
// Created by Kina on 2020/05/02.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2147483647
#define V_MAX 20050
using namespace std;

int V, E, START, DST;

int prevVertex[V_MAX];
int weightSum[V_MAX];
bool visited[V_MAX];

struct cmp{
    bool operator()(pair<int, int> a,  pair<int, int> b){
        return a.second > b.second;
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v, w;
    cin >> V >> E >> START;
    vector<pair<int, int>> *edgeList = new vector<pair<int, int>>[V + 1];
    for (int edge = 0; edge < E; edge++) {
        cin >> u >> v >> w;
        edgeList[u].push_back(make_pair(v, w));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (int i = 1; i <= V; i++) {
        if(i==START)
            pq.push(make_pair(START, 0));
        else
            weightSum[i]=INF;
    }
    while (!pq.empty()) {
        int current = pq.top().first;
        pq.pop();
        for (pair<int, int> p : edgeList[current]) {
            int next = p.first;
            int next_weight = weightSum[current] + p.second;
            if (!visited[next]) { // 방문하지 않았으면
                if (weightSum[next] > next_weight) {
                    prevVertex[next] = current;
                    weightSum[next] = next_weight;
                    pq.push(make_pair(next, next_weight));
                }
            }
        }
        visited[current] = true;
    }
    for(int i=1; i<=V; i++){
        if (visited[i]) {
            cout << weightSum[i] << '\n';
        } else {
            cout << "INF" << '\n';
        }
    }
    return 0;
}