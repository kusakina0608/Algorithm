//
// Created by Kina on 2020/02/18.
//
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void dfs(vector<int>* list, int* color, int index, int col){
    color[index]=col;
    for(int i=0; i<list[index].size(); i++){
        int x=list[index][i];
        if(color[x]==0){
            dfs(list, color, x, 3-col);
        }
    }
}

void CheckBipartite(vector<int>* list, int* color, int n_vertex){
    bool ok=true;
    for(int i=1; i<=n_vertex; i++){
        for(int j=0; j<list[i].size(); j++){
            int k=list[i][j];
            if(color[i]==color[k])
                ok=false;
        }
    }
    printf("%s\n", ok?"YES":"NO");
}

int main(void){
    int TestCase;
    scanf("%d", &TestCase);
    for(int test_case=1; test_case<=TestCase; ++test_case){
        int n_vertex, n_edge;
        scanf("%d %d", &n_vertex, &n_edge);
        vector<int>* list=new vector<int>[n_vertex+1];
        for(int i=0; i<n_edge; i++){
            int v1, v2;
            scanf("%d %d", &v1, &v2);
            list[v1].push_back(v2);
            list[v2].push_back(v1);
        }
        int* color=new int[n_vertex+1];
        memset(color, 0, sizeof(int)*(n_vertex+1));
        for(int i=1; i<=n_vertex; i++){
            if(color[i]==0){
                dfs(list, color, i, 1);
            }
        }
        CheckBipartite(list, color, n_vertex);
        delete[] color;
        delete[] list;
    }
    return 0;
}