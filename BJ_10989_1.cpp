//
// Created by Kina on 2020/08/02.
//
#include <iostream>
using namespace std;

int N, tmp;
int cnt[10001];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>tmp;
        cnt[tmp]++;
    }
    for(int i=0; i<10001; i++){
        while(cnt[i]>0){
            cout<<i<<'\n';
            cnt[i]--;
        }
    }
    return 0;
}
