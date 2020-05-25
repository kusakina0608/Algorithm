//
// Created by Kina on 2020/04/19.
//
#include <iostream>
#include <string.h>

using namespace std;

int V, E, cnt;

int parent[128];

int find_set(int x){
    while(parent[x] != -1){
        x = parent[x];
    }
    return x;
}

void union_set(int x, int y){
    x = find_set(x);
    y = find_set(y);
    if(x!=y) {
        parent[x] = y;
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(parent, -1, sizeof(parent));

    cin>>V>>E;

    int v1, v2;
    for(int i=0; i<E; i++){
        cin>>v1>>v2;
        union_set(v1, v2);
    }

    int set_no = find_set(1);
    for(int i=2; i<=V; i++){
        if(find_set(i) == set_no) cnt++;
    }

    cout<<cnt;
}