//
// Created by Kina on 2020/02/17.
//
#include <iostream>
using namespace std;

void go(int* arr, int index, int count, int n, int m){
    if(count==m){
        for(int i=0; i<m; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    if(index>n) return;
    for(int i=1; i<=n; i++){
        arr[count]=i;
        go(arr, index, count+1, n, m);
    }
}

int main(void){
    int N, M;
    cin>>N>>M;
    int* arr=new int[M];
    go(arr, 1, 0, N, M);
    delete[] arr;
    return 0;
}