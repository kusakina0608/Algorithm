//
// Created by Kina on 2020/05/03.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#define INF 2147483647
using namespace std;

int N;
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

int map[128][128];
int weight[128][128];
bool Kangaroo(int i, int j){
    return 0<=i && 0<=j && i<N && j<N;
}

struct compare{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return weight[a.first][a.second] > weight[b.first][b.second];
    }
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int p_num = 0;
    while(true){
        cin>>N;
        if(N==0) break;
        p_num++;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>map[i][j];
                weight[i][j] = INF;
            }
        }
        weight[0][0] = map[0][0];
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
        q.push(make_pair(0, 0));
        while(!q.empty()){
            pair<int, int> current = q.top();
            q.pop();
            int i = current.first;
            int j = current.second;
            if(i==N-1 && j==N-1) break;
            for(int k=0; k<4; k++){
                int new_i = i+di[k];
                int new_j = j+dj[k];
                if(Kangaroo(new_i, new_j)){ // 갈 수 있는 좌표일 경우
                    int new_weight = weight[i][j]+map[new_i][new_j];
                    if(weight[new_i][new_j] > new_weight) {
                        weight[new_i][new_j] = new_weight;
                        q.push(make_pair(new_i, new_j));
                    }
                }
            }
        }
        cout<<"Problem "<<p_num<<": "<<weight[N-1][N-1]<<'\n';
    }
}