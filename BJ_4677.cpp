//
// Created by Kina on 2020/05/03.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool grid_check[128][128];
int di[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dj[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int N, M;

bool Kangaroo(int i, int j){
    return 0<=i && 0<=j && i<N && j<M;
}

void go(int i, int j){
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;
        grid_check[i][j] = true;
        for(int k=0; k<8; k++){
            int new_i = i + di[k];
            int new_j = j + dj[k];
            if(Kangaroo(new_i, new_j)){
                if(!grid_check[new_i][new_j]){
                    q.push(make_pair(new_i, new_j));
                }
            }
        }
    }
}

int main(void){
    int c;
    while(true){
        cin>>N>>M;
        if(N==0) break;
        for(int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                scanf(" %c", &c);
                grid_check[i][j] = c == '*' ? true : false;
            }
        }
        int cnt=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(!grid_check[i][j]){
                    go(i, j);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}