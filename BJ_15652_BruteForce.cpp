//
// Created by Kina on 2020/05/25.
//
#include <iostream>
using namespace std;

void go(int* cnt, int index, int count, int n, int m){
    if(count==m){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=cnt[i]; j++){
                //printf("%d ",i);
                cout<<i<<' ';
            }
        }
        cout<<'\n';
        return;
    }
    if(index>n) return;
    for(int i=m-count; i>=1; i--){
        cnt[index]=i;
        go(cnt, index+1, count+i, n, m);
    }
    cnt[index]=0;
    go(cnt, index+1, count, n, m);
}

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);
    int* arr=new int[N+1];
    go(arr, 1, 0, N, M);
}
