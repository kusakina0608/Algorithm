//
// Created by Kina on 2020/02/09.
//
#include <iostream>
using namespace std;

int check(int n){
    int count=1;
    while(n/=10) { count++; }
    return count;
}

int calcHansu(int n){
    bool flag=true;
    int count=99;
    int num=100;
    int diff;
    if(n<100)
        return n;
    for(int i=100; i<=n; i++){
        num=i;
        diff=(num%10)-((num/10)%10);
        flag=true;
        for(int j=check(i)-1; j>0; j--){
            if(diff==((num%10)-((num/10)%10))) {
                num = (num / 10);
            }else{
                flag=false;
                break;
            }
        }
        if(flag) count++;
    }
    return count;
};

int main(void){
    int n;
    cin>>n;
    cout<<calcHansu(n);
    return 0;
}