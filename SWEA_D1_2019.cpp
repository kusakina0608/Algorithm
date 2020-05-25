//
// Created by Kina on 2020/02/15.
//
#include<iostream>
using namespace std;

int main(int argc, char** argv){
    int n;
    cin>>n;
    for(int i=0; i<=n; i++){
        cout<<(1<<i)<<' ';
    }
    return 0;
}