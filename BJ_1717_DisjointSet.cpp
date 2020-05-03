//
// Created by Kina on 2020/04/17.
//
#include <iostream>
#include <string.h>

using namespace std;

int N, M;
int parent[1000050];
int command[100050][3];

int find_set(int x){
    while(parent[x] != -1){
        x = parent[x];
    }
    return x;
}

int find_set(int x, int &rank) {
    while(parent[x] != -1){
        x = parent[x];
        rank++;
    }
    return x;
}

void union_set(int x, int y) {
    int rank_x = 0, rank_y = 0;
    x = find_set(x, rank_x);
    y = find_set(y, rank_y);
    if (x != y) {
        if (rank_x < rank_y) {
            parent[x] = y;
        } else {
            parent[y] = x;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(parent, -1, sizeof(parent));
    cin>>N>>M;

    for(int i=0; i<M; i++){
        cin>>command[i][0]>>command[i][1]>>command[i][2];
    }
    for(int i=0; i<M; i++){
        if(command[i][0]==0){
            union_set(command[i][1], command[i][2]);
        }
        else{
            cout<<((find_set(command[i][1])==find_set(command[i][2]))?"YES\n":"NO\n");
        }
    }
    return 0;
}