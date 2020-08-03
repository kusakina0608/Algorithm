//
// Created by Kina on 2020/02/08.
//
#include <iostream>
using namespace std;

int main(void){
    int a, b, c, res;
    int counter[10] = {0,0,0,0,0,0,0,0,0,0};
    cin>>a>>b>>c;
    res=a*b*c;
    while(res){
        counter[res%10]++;
        res/=10;
    }
    for(int i=0; i<10; i++){
        cout<<counter[i]<<endl;
    }
    return 0;
}