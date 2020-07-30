//
// Created by Kina on 2020/07/29.
//
#include<iostream>
using namespace std;

int month_len[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int test_case, T, m1, m2, d1, d2, res;

int main(int argc, char** argv)
{
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        res = 0;
        cin>>m1>>d1>>m2>>d2;
        while(m2!=m1){
            res += d2;
            d2 = month_len[--m2];
        }
        res += d2-d1+1;
        cout<<'#'<<test_case<<' '<<res<<'\n';
    }
    return 0;
}