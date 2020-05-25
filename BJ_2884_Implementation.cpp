//
// Created by Kina on 2020/02/08.
//
#include <iostream>
using namespace std;

int main(void){
    int hour, min;
    cin>>hour>>min;
    for(int i=0; i<45; i++){
        min--;
        if(min<0){
            min=59;
            hour--;
            if(hour<0)
                hour=23;
        }
    }
    cout<<hour<<' '<<min;
}