//
// Created by Kina on 2020/12/02.
//
#include<iostream>

using namespace std;

int T, N, M, test_case, max_depth;
int edge[16][16];

void init_edge(){
    for(int y=0; y<16; y++){
        for(int x=0; x<16; x++){
            edge[y][x] = -1;
        }
    }
}

bool is_visit(int visits, int v){
    return ((visits>>v)&1) == 1;
}

void set_visit(int *visits, int v){
    *visits |= 1<<v;
}

void dfs(int visit, int cur, int depth){
    set_visit(&visit, cur);
    depth++;
    if(max_depth < depth){
        max_depth = depth;
    }
    for(int i=1; i<=N; i++){
        if(edge[cur][i] == 1 && !is_visit(visit, i)){
            dfs(visit, i, depth);
        }
    }
}

int main(int argc, char** argv) {
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        max_depth = 0;
        init_edge();
        cin >> N >> M;
        for(int i=0; i<M; i++){
            register int v1, v2;
            cin>> v1 >> v2;
            edge[v1][v2] = 1;
            edge[v2][v1] = 1;
        }
        for(int v1 = 1; v1<=N; v1++){
            dfs(0, v1, 0);
        }
        cout<<'#'<<test_case<<' '<<max_depth<<endl;
    }
    return 0;
}