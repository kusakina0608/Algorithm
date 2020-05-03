//
// Created by Kina on 2020/02/10.
//
#include <iostream>
using namespace std;

int main(void){
    int E, S, M, e=1, s=1, m=1, year=1;
    cin>>E>>S>>M;

    while(e!=E || s!=S || m!=M){
        e++;
        s++;
        m++;
        year++;
        if(e>15)
            e=1;
        if(s>28)
            s=1;
        if(m>19)
            m=1;
    }
    cout<<year;
}