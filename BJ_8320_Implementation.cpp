//
// Created by Kina on 2020/02/08.
//
#include <iostream>
using namespace std;

int main(void){
    int num, count;
    cin>>num;

    count=0;
    for(int i=1; i<=num; i++){
        for(int j=i; j<=num; j++){
            if(i*j<=num) {
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}