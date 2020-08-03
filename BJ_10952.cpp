//
// Created by Kina on 2020/02/08.
//
#include <iostream>
using namespace std;

int main(void){
    int a, b;
    while(true){
        cin>>a>>b;
        if(a==0 && b==0)
            break;
        cout<<a+b<<endl;
    }
    return 0;
}