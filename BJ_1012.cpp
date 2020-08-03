//
// Created by Kina on 2020/08/03.
//
#include <iostream>
using namespace std;

int T, H, W, K, tc, ci, cj, ni, nj, cnt;
int **map;
int k_stack[10000][2];
int top;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

bool k_can_go(int i, int j){
    return 0<=i && i<H && 0<=j && j<W && map[i][j]==-1;
}

void dfs(int i, int j){
    top = 0;
    k_stack[top][0] = i;
    k_stack[top][1] = j;
    while(top>=0){
        ci = k_stack[top][0];
        cj = k_stack[top][1];
        top--;
        if(map[ci][cj]==-1){ // not visited
            map[ci][cj] = cnt;
            for(int k=0; k<4; k++){
                ni = ci + di[k];
                nj = cj + dj[k];
                if(k_can_go(ni, nj)){
                    top++;
                    k_stack[top][0] = ni;
                    k_stack[top][1] = nj;
                }
            }
        }
    }
}

int main(void){
    cin>>T;
    for(tc=1; tc<=T; tc++){
        cnt = 0;
        cin>>H>>W>>K;
        map = new int*[H];
        for(int i=0; i<H; i++){
            map[i] = new int[W];
            for(int j=0; j<W; j++){
                map[i][j] = 0;
            }
        }
        for(int i=0; i<K; i++){
            cin>>ci>>cj;
            map[ci][cj] = -1;
        }
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(map[i][j]==-1){
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout<<cnt<<'\n';
    }
}