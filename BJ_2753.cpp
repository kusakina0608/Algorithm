//
// Created by Kina on 2020/02/08.
//
#include <iostream>
using namespace std;

int main(void){
    int year;
    cin>>year;
    bool cond1, cond2, cond3;
    cond1=year%4==0;
    cond2=year%100!=0;
    cond3=year%400==0;
    if((cond1 && cond2) || cond3){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}