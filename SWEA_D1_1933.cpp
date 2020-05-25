//
// Created by Kina on 2020/02/15.
//
#include<iostream>
using namespace std;

int main(int argc, char** argv){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        if(n%i==0){
            cout<<i<<' ';
        }
    }
    return 0;
}
