//
// Created by Kina on 2020/02/17.
//
#include <iostream>
using namespace std;

void go(int* data, int* index, int idx, int cnt, int n, int m){
    if(cnt==m){
        for(int i=0; i<m; i++){
            cout<<data[index[i]]<<' ';
        }
        cout<<'\n';
        return;
    }
    if(idx==n) return;
    for(int i=idx; i<n; i++){
        index[cnt]=i;
        go(data, index, i, cnt+1, n, m);
    }
}

int main(void){
    int n, m;
    cin>>n>>m;
    int* data=new int[n];
    for(int i=0; i<n; i++){
        cin>>data[i];
    }
    int* index=new int[m];
    for(int i=n-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(data[j]>data[j+1]){
                data[j]=data[j]^data[j+1];
                data[j+1]=data[j]^data[j+1];
                data[j]=data[j]^data[j+1];
            }
        }
    }
    go(data, index, 0, 0, n, m);
    delete[] data;
    delete[] index;
    return 0;
}