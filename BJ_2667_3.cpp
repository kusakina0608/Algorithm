// TODO change to DFS
// Created by Kina on 2020/02/18.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int di[]={-1, 1, 0, 0};
int dj[]={0, 0, -1, 1};

void dfs(int** map, int size, int i, int j, int mark);
void ShowMap(int** map, int size);

int main(void){
    int size;
    scanf("%d", &size);
    int** map=new int*[size];
    for(int i=0; i<size; i++){
        map[i]=new int[size];
        memset(map[i], 0, sizeof(int)*size);
        for(int j=0; j<size; j++){
            char c;
            do{ c=getchar(); } while(c!='0' && c!='1');
            map[i][j]=(c-'0')-1;
        }
    }
    //ShowMap(map, size);
    //cout<<endl;
    int mark=1;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(map[i][j]==0){
                dfs(map, size, i, j, mark++);
            }
        }
    }
    //ShowMap(map, size);
    int n_mark=mark-1;
    vector<int> counter;
    for(int i=0; i<n_mark; i++){
        counter.push_back(0);
    }
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(map[i][j]!=-1){
                counter[map[i][j]-1]++;
            }
        }
    }
    sort(counter.begin(), counter.end());
    cout<<n_mark<<endl;
    for(int i=0; i<n_mark; i++){
        cout<<counter[i]<<endl;
    }
    for(int i=0; i<size; i++){
        delete[] map[i];
    }
    delete[] map;
    return 0;
}

void dfs(int** map, int size, int i, int j, int mark){
    map[i][j]=mark;
    for(int k=0; k<4; k++){
        int ni=i+di[k];
        int nj=j+dj[k];
        if(0<=ni && 0<=nj && ni<size && nj<size){
            if(map[ni][nj]==0){
                dfs(map, size, ni, nj, mark);
            }
        }
    }
}

void bfs(int** map, int size, int i, int j, int mark){
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    map[i][j]=mark;
    while(!q.empty()){
        i=q.front().first;
        j=q.front().second;
        q.pop();
        for(int k=0; k<4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (0 <= ni && 0 <= nj && ni < size && nj < size) {
                if(map[ni][nj]==0) {
                    q.push(make_pair(ni, nj));
                    map[ni][nj] = mark;
                }
            }
        }
    }
}

void ShowMap(int** map, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%4d ", map[i][j]);
        }
        cout<<endl;
    }
}