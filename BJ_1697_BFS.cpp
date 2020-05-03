//
// Created by Kina on 2020/02/19.
//
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int NextPos(int x, int index){
    switch(index){
        case 0:
            return x+1;
        case 1:
            return x-1;
        case 2:
            return x*2;
    }
    return -1;
}

int bfs(queue<pair<int, int>> q, bool* check, int dest){
    int x, time;
    while(!q.empty()){
        x=q.front().first;
        time=q.front().second;
        q.pop();
        if(x==dest) return time;
        for(int i=0; i<3; i++){
            int nx=NextPos(x, i);
            if(0<=nx && nx<=100000){
                if(check[nx]==false){
                    q.push(make_pair(nx, time+1));
                    check[nx]=true;
                }
            }
        }
    }
    return -1;
}

int main(void){
    int start, dest;
    scanf("%d %d", &start, &dest);
    bool* check=new bool[100001];
    memset(check, 0, sizeof(bool)*100001);
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    check[start]=true;
    int result=bfs(q, check, dest);
    printf("%d", result);
    delete[] check;
    return 0;
}