//
// Created by Kina on 2020/02/08.
//
#include <iostream>
using namespace std;

int main(void){
    int index=0, max=-2147483648, val;

    for(int i=1; i<=9; i++){
        cin>>val;
        if(max<val){
            max=val;
            index=i;
        }
    }
    cout<<max<<endl<<index;
    return 0;
}