//
// Created by Kina on 2020/07/07.
//
#include <iostream>
using namespace std;

int T, a, b, c, d;

int main(void){
    cin>>T;
    for(int t=1; t<=T; t++){
        cin>>a>>b>>c>>d;
        a += c;
        b += d;
        a += b/60;
        a %= 12;
        if(a==0) a=12;
        b %= 60;
        cout<<'#'<<t<<' '<<a<<' '<<b<<'\n';
    }
}