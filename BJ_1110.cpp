//
// Created by Kina on 2020/05/03.
//
#include <iostream>
using namespace std;

int N, M, Count;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    M=N;
    do{
        M = (M%10)*10 + (M/10+M%10)%10;
        Count++;
    }while(M!=N);

    cout<<Count;
    return 0;
}