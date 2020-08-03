//
// Created by Kina on 2020/07/30.
//
#include <iostream>
using namespace std;

int H, W, max_time, cur_time;
char** map;
bool** visited;

int di[] = {0, 0, -1, 1};
int dj[] = {1, -1, 0, 0};

int queue[10000][3];
int front, rear;

bool k_can_go(int i, int j){
    return 0<=i && i<H && 0<=j && j<W && map[i][j]=='L';
}

void init_visited(){
    visited = new bool*[H];
    for(int i=0; i<H; i++){
        visited[i] = new bool[W];
        for(int j=0; j<W; j++){
            visited[i][j] = false;
        }
    }
}

void delete_visited(){
    for(int i=H-1; i>=0; i--){
        delete[] visited[i];
    }
    delete[] visited;
}

int go(int i, int j){
    int max_t = 0;
    init_visited();
    front = rear = -1;
    rear++;
    queue[rear][0] = i;
    queue[rear][1] = j;
    queue[rear][2] = 0;
    while(front!=rear){
        front++;
        int ci = queue[front][0];
        int cj = queue[front][1];
        int ct = queue[front][2];
        if(!visited[ci][cj]){
            visited[ci][cj] = true;
            if(max_t<ct){
                max_t=ct;
            }
            for(int k=0; k<4; k++){
                int ni = ci + di[k];
                int nj = cj + dj[k];
                if(k_can_go(ni, nj) && !visited[ni][nj]){
                    rear++;
                    queue[rear][0] = ni;
                    queue[rear][1] = nj;
                    queue[rear][2] = ct + 1;
                }
            }
        }
    }
    delete_visited();
    return max_t;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>H>>W;
    map = new char*[H];
    for(int i=0; i<H; i++){
        map[i] = new char[W];
        for(int j=0; j<W; j++){
            cin>>map[i][j];
        }
    }
    max_time = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(map[i][j]=='L'){
                cur_time = go(i, j);
                if(max_time<cur_time){
                    max_time=cur_time;
                }
            }
        }
    }
    cout<<max_time;
    for(int i=H-1; i>=0; i--){
        delete[] map[i];
    }
    delete[] map;
    return 0;
}