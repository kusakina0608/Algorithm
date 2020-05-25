// TODO read
// Created by Kina on 2020/02/19.
//
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int check[1001][1001];

void act(int& s, int& c, int index){
    switch(index){
        case 0: //copy
            c=s; return;
        case 1: //paste
            s+=c; return;
        case 2: //delete
            s--; return;
    }
    return;
}

int bfs(queue<pair<int, int>>& q, const int& target){
    int s, c;
    while(!q.empty()){
        s=q.front().first;
        c=q.front().second;
        q.pop();
        if(s==target) return check[s][c];
        for(int i=0; i<3; i++){
            int ns=s;
            int nc=c;
            act(ns, nc, i);
            if(0<=ns && ns<=1000){
                if(check[ns][nc]==-1){
                    q.push(make_pair(ns, nc));
                    check[ns][nc]=check[s][c]+1;
                }
            }
        }
    }
}

int main(void){
    int target;
    scanf("%d", &target);
    memset(check, -1, sizeof(int)*(1001)*(1001));
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    check[1][0]=0;

    printf("%d",bfs(q, target));
    return 0;
}