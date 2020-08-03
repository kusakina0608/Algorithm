//
// Created by Kina on 2020/02/08.
//
#include <iostream>
using namespace std;

int main(void){
    int n, max, min, val;
    cin>>n;
    max=-2147483648;
    min=2147483647;
    while(n--){
        cin>>val;
        if(max<val){
            max=val;
        }
        if(min>val){
            min=val;
        }
    }
    cout<<min<<' '<<max;
}