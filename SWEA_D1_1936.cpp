//
// Created by Kina on 2020/02/15.
//
#include<iostream>
using namespace std;

int main(int argc, char** argv){
    int A, B;
    cin>>A>>B;
    if(A==B){
        cout<<"비기는 경우는 없다고 했습니다.";
    }else if(A-B==1 || A-B==2){
        cout<<'A';
    }else{
        cout<<'B';
    }
    return 0;
}