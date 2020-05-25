//
// Created by Kina on 2020/02/15.
//
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int sum=0, val;
    cin>>val;
    while(val){
        sum+=val%10;
        val/=10;
    }
    cout<<sum;
    return 0;
}