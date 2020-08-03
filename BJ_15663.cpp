//
// Created by Kina on 2020/02/17.
//
#include <iostream>
using namespace std;

void go(int* data, int* index, int* count, int cnt, int n, int m){
    if(cnt==m){
        for(int i=0; i<m; i++){
            cout<<data[index[i]]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0; i<n; i++){
        if(count[i]>0){
            count[i]--;
            index[cnt]=i;
            go(data, index, count, cnt+1, n, m);
            count[i]++;
        }
    }
}

int main(void){
    int n, m;
    cin>>n>>m;
    int* data=new int[n];
    int* count=new int[n];
    int* index=new int[m];
    for(int i=0; i<n; i++){
        cin>>data[i];
        count[i]=1;
    }
    for(int i=n-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(data[j]>data[j+1]){
                data[j]=data[j]^data[j+1];
                data[j+1]=data[j]^data[j+1];
                data[j]=data[j]^data[j+1];
            }
        }
    }
    int new_n=n;
    for(int i=0; i<n-1; i++){
        if(data[i]==data[i+1]) new_n--;
    }
    int* new_data=new int[new_n];
    new_data[0]=data[0];
    for(int i=1, new_i=1; i<n; i++){
        if(data[i-1]!=data[i]){
            new_data[new_i++]=data[i];
        }else{
            count[new_i-1]++;
        }
    }
    /*for(int i=0; i<n; i++){
        cout<<data[i]<<' ';
    }
    cout<<endl;
    for(int i=0; i<new_n; i++){
        cout<<new_data[i]<<'('<<count[i]<<')'<<' ';
    }
    cout<<endl<<endl;*/
    go(new_data, index, count, 0, new_n, m);
    delete[] new_data;
    delete[] index;
    delete[] count;
    delete[] data;
    return 0;
}