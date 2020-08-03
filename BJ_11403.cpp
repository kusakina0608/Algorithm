//
// Created by Kina on 2020/08/03.
//
#include <iostream>
using namespace std;

int N, top;
int** matrix;
int k_stack[10000];
bool* visited;

void init_visit(){
    visited = new bool[N];
    for(int i=0; i<N; i++) {
        visited[i] = false;
    }
}

void delete_visit(){
    delete[] visited;
}

bool dfs(int v1, int v2){
    bool answer = false;
    int cv;
    init_visit();
    top = 0;
    k_stack[top] = v1;
    while(top>=0){
        cv = k_stack[top];
        top--;
        if(!visited[cv]){
            visited[cv] = true;
            for(int i=0; i<N; i++){
                if(matrix[cv][i]==1) {
                    if(i==v2) answer = true;
                    if (!visited[i]) {
                        top++;
                        k_stack[top] = i;
                    }
                }
            }
        }
    }
    delete_visit();
    return answer;
}

int main(void){
    cin>>N;
    matrix = new int*[N];
    for(int i=0; i<N; i++){
        matrix[i] = new int[N];
        for(int j=0; j<N; j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(dfs(i, j)){
                cout<<1;
            }else{
                cout<<0;
            }
            cout<<' ';
        }
        cout<<'\n';
    }
    return 0;
}