//
// Created by Kina on 2020/07/07.
//
#include <iostream>
using namespace std;

int puzzle[15][15];
int T, N, K, res;

bool is_valid(int y, int x){
    return 0<=y && y<N && 0<=x && x<N;
}

int main(void){
    cin>>T;
    for(int t=1; t<=T; t++){
        res=0;
        cin>>N>>K;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>puzzle[i][j];
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if((!is_valid(i, j-1) || puzzle[i][j-1]==0) && puzzle[i][j]==1) {
                    //cout<<'('<<i<<", "<<j<<')'<<"horizontal"<<'\n';
                    int tmp = 0;
                    int newj = j;
                    while(is_valid(i, newj) && puzzle[i][newj]==1){
                        tmp += puzzle[i][newj];
                        newj++;
                    }
                    if (tmp == K) res++;
                }
                if((!is_valid(i-1, j) || puzzle[i-1][j]==0) && puzzle[i][j]==1) {
                    //cout<<'('<<i<<", "<<j<<')'<<"vertical"<<'\n';
                    int tmp = 0;
                    int newi = i;
                    while(is_valid(newi, j) && puzzle[newi][j]==1){
                        tmp += puzzle[newi][j];
                        newi++;
                    }
                    if (tmp == K) res++;
                }
            }
        }
        cout<<'#'<<t<<' '<<res<<'\n';
    }
    return 0;
}
About