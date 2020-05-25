//
// Created by Kina on 2020/02/08.
//
#include <iostream>
using namespace std;

int main(void){
    bool check[42];
    for(int i=0; i<42; i++){
        check[i] =false;
    }
    for(int i=0; i<10; i++){
        int val;
        cin>>val;
        check[val%42]++;
    }
    int count=0;
    for(int i=0; i<42; i++){
        count+=check[i];
    }
    cout<<count;
    return 0;
}