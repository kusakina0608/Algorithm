//
// Created by Kina on 2020/02/09.
//
#include <iostream>
using namespace std;

int nextNum(int origin){
    int res=0;
    res+=origin;
    while(origin!=0) {
        res += origin % 10;
        origin/=10;
    }
    return res;
}

int main(void){
    static bool boolal[10001];//checked means already tested
    int num=1;
    for(int i=1; i<10000; i++){
        num=i;
        if(boolal[num]==true)
            continue;
        else{
            printf("%d\n", num);
            while(num<10000) {
                num=nextNum(num);
                boolal[num]=true;
            }
        }
        boolal[i]=true;
    }
}