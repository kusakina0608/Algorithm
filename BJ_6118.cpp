//
// Created by Kina on 2020/05/02.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_N 20050
#define INF 2147483647
using namespace std;

int N, M, Start=1;
int A, B;
int Dist[MAX_N];
bool Visit[MAX_N];
vector<int> Edge[MAX_N];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;

    for(int n_edge=0; n_edge<M; n_edge++){
        cin>>A>>B;
        Edge[A].push_back(B);
        Edge[B].push_back(A);
    }
    queue<int> q;
    q.push(Start);
    for(int vertex_idx=2; vertex_idx<=N; vertex_idx++){
        Dist[vertex_idx] = INF;
    }

    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int next : Edge[current]){
            int new_dist = Dist[current]+1;
            if(!Visit[next]){
                if(Dist[next]>new_dist) {
                    Dist[next] = new_dist;
                    q.push(next);
                }
            }
        }
        Visit[current] = true;
    }

    int max_idx = 1;
    int max_dist = 0;
    int cnt = 1;
    for(int i=2; i<=N; i++){
        if(max_dist<Dist[i]){
            max_idx=i;
            max_dist=Dist[i];
            cnt=1;
        }else if(max_dist==Dist[i]){
            cnt++;
        }
    }
    cout<<max_idx<<' '<<max_dist<<' '<<cnt<<'\n';
    return 0;
}