//
// Created by Kina on 2020/05/03.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define N_MAX 1024
#define INF 2147483647
using namespace std;

int N, E;
int Weight[N_MAX];
int V1, V2;
vector<pair<int, int>> Edge[N_MAX];

void initWeight(int start){
    for(int i=1; i<=N; i++){
        Weight[i] = INF;
    }
    Weight[start] = 0;
}

struct compare{
    bool operator()(int a, int b){
        return Weight[a]>Weight[b];
    }
};

int go(int start, int dest){
    initWeight(start);
    priority_queue<int, vector<int>, compare> pq;
    pq.push(start);
    while(!pq.empty()){
        int current = pq.top();
        pq.pop();
        int num_edge = Edge[current].size();
        for(int i=0; i<num_edge; i++){
            int next_index = Edge[current][i].first;
            int next_weight = Edge[current][i].second;
            if(Weight[next_index] > Weight[current] + next_weight){
                Weight[next_index] = Weight[current] + next_weight;
                pq.push(next_index);
            }
        }
    }
    if(Weight[dest]==INF) return -1;
    return Weight[dest];
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>E;
    for(int i=0; i<E; i++){
        int v1, v2, w;
        cin>>v1>>v2>>w;
        Edge[v1].push_back(make_pair(v2, w));
        Edge[v2].push_back(make_pair(v1, w));
    }
    cin>>V1>>V2;

    int a, b, c, x, y, z;
    a = go(1, V1);
    b = go(V1, V2);
    c = go(V2, N);

    x = go(1, V2);
    y = b;
    z = go(V1, N);
    
    int result1 = 0, result2 = 0;
    if(b==-1){
        result1=INF;
        result2=INF;
    }else{
        if(a==-1 || c==-1){
            result1=INF;
        }else{
            result1=a+b+c;
        }
        if(x==-1 || z==-1){
            result2=INF;
        }else{
            result2=x+y+z;
        }
    }

    if(result1==INF && result2==INF){
        cout<<-1;
    }else{
        cout<<(result1<result2?result1:result2);
    }

    return 0;
}