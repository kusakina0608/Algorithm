//
// Created by Kina on 2020/02/18.
//
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

void dfs(int** m, bool* check, int n_vertex, int i){
    check[i]=true;
    printf("%d ", i);
    for(int j=1; j<=n_vertex; j++){
        if(m[i][j]==1 && check[j]==false){
            dfs(m, check, n_vertex, j);
        }
    }
}

void bfs(int** m, bool* check, int n_vertex, int start_v){
    queue<int> q;
    check[start_v]=true;
    q.push(start_v);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        printf("%d ", x);
        for(int i=1; i<=n_vertex; i++){
            if(m[x][i]==1 && check[i]==false){
                check[i]=true;
                q.push(i);
            }
        }
    }
}

int main(void){
    int n_vertex, n_edge, start_v;
    scanf("%d %d %d", &n_vertex, &n_edge, &start_v);
    int** m=new int*[n_vertex+1];
    bool* check=new bool[n_vertex+1];
    memset(check, 0, sizeof(bool)*(n_vertex+1));
    for(int i=1; i<=n_vertex; i++){
        m[i]=new int[n_vertex+1];
        //check[i]=false;
        memset(m[i], 0, sizeof(int)*(n_vertex+1));
        /*for(int j=1; j<=n_vertex; j++){
            m[i][j]=0;
        }*/
    }
    for(int i=0; i<n_edge; i++){
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        m[n1][n2]=1;
        m[n2][n1]=1;
    }
    dfs(m, check, n_vertex, start_v);
    cout<<endl;
    memset(check, 0, sizeof(bool)*(n_vertex+1));
    /*for(int i=1; i<=n_vertex; i++){
        check[i]=false;
    }*/
    bfs(m, check, n_vertex, start_v);
    for(int i=1; i<=n_vertex; i++){
        delete[] m[i];
    }
    delete[] m;
}