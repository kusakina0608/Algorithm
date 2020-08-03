//
// Created by Kina on 2020/02/09.
//
#include <iostream>
using namespace std;

int main(void){
    char c;
    int n;
    int sum=0;
    cin>>n;

    while(n--){
        cin>>c;
        sum+=static_cast<int>(c-'0');
    }
    cout<<sum;
}