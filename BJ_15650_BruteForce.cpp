//
// Created by Kina on 2020/02/17.
//
#include <iostream>
using namespace std;

void go(int* arr, int index, int selected, int n, int m){
    if(selected==m){
        for(int i=0; i<m; i++){
            cout<<arr[i]<<' ';
        }
        cout<<endl;
        return;
    }
    if(index>n) return;
    arr[selected]=index;
    go(arr, index+1, selected+1, n, m);
    go(arr, index+1, selected, n, m);

}

int main(void){
    int N, M;
    cin>>N>>M;
    int* arr=new int[M];
    go(arr, 1, 0, N, M);
}