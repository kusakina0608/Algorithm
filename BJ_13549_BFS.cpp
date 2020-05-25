//
// Created by Kina on 2020/02/19.
//
#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
using namespace std;

int bfs(deque<pair<int, int>> dq, bool* check, int dest){
    int x, nx, count=0;
    while(!dq.empty()){
        x=dq.front().first;
        count=dq.front().second;
        if(x==dest) return count;
        dq.pop_front();
        nx=2*x;
        if(nx<=100001){
            if(check[nx]==false) {
                dq.push_front(make_pair(nx, count));
                check[nx] = true;
            }
        }
        nx=x-1;
        if(0<=nx){
            if(check[nx]==false) {
                dq.push_back(make_pair(nx,count+1));
                check[nx]=true;
            }
        }
        nx=x+1;
        if(nx<=100001){
            if(check[nx]==false) {
                dq.push_back(make_pair(nx,count+1));
                check[nx]=true;
            }
        }
    }
}

int main(void){
    int start, dest;
    scanf("%d %d", &start, &dest);
    bool* check=new bool[100001];
    memset(check, 0, sizeof(check));
    deque<pair<int, int>> dq;
    dq.push_back(make_pair(start, 0));
    check[start]=true;
    int result=bfs(dq, check, dest);
    printf("%d",result);
    return 0;
}