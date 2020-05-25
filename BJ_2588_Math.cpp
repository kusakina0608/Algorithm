//
// Created by Kina on 2020/02/08.
//
#include <iostream>
using namespace std;

int main(void){
    int a, b;
    int d2, d1, d0;
    cin>>a>>b;
    d0=b%10;
    d1=b%100/10;
    d2=b/100;
    cout<<a*d0<<endl;
    cout<<a*d1<<endl;
    cout<<a*d2<<endl;
    cout<<a*b<<endl;
}