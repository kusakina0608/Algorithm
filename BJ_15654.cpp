//
// Created by Kina on 2020/02/17.
//
#include <iostream>
using namespace std;

void go(int* arr, int* res, bool* check, int index, int count, int n, int m){
    if(count==m){
        for(int i=0; i<m; i++){
            printf("%d ", res[i]);
        }
        putchar('\n');
        return;
    }
    if(index>=n) return;
    for(int i=0; i<n; i++){
        if(!check[i]) {
            res[count] = arr[i];
            check[i]=true;
            go(arr, res, check, index + 1, count + 1, n, m);
            check[i]=false;
        }
    }
}

int main(void){
    int n, m;
    cin>>n>>m;
    int* arr=new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=n-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(arr[j]>arr[j+1]){
                arr[ j ]=arr[ j ]^arr[j+1];
                arr[j+1]=arr[ j ]^arr[j+1];
                arr[ j ]=arr[ j ]^arr[j+1];
            }
        }
    }
    bool* check=new bool[m];
    int* res=new int[m];
    go(arr, res, check, 0, 0, n, m);
    delete[] arr;
    delete[] check;
    delete[] res;
}