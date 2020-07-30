//
// Created by Kina on 2020/07/29.
//
#include<iostream>
using namespace std;

int test_case, T, N;
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

bool can_go(int newi, int newj, int n, int** a){
    return 0<=newi && newi<n && 0<=newj && newj<n && a[newi][newj]==0;
}

void snail(int n){
    int** a = new int*[n];
    for(int i=0; i<n; i++){
        a[i] = new int[n];
        for(int j=0; j<n; j++){
            a[i][j] = 0;
        }
    }
    int i=0, j=0, d=0, cnt=0, value = 1;

    while(true){
        a[i][j] = value++;
        if(!can_go(i+di[d], j+dj[d], n, a)){
            (++d)%=4;
        }
        if(!can_go(i+di[d], j+dj[d], n, a))
            break;
        i += di[d];
        j += dj[d];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
        delete[] a[i];
    }
    delete[] a;
}

int main(int argc, char** argv)
{
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>N;
        cout<<'#'<<test_case<<'\n';
        snail(N);
    }
    return 0;
}