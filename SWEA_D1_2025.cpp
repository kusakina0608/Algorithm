//
// Created by Kina on 2020/02/15.
//
#include<iostream>
using namespace std;

int res(int n, int sum, int i){
    if(i>n)
        return sum;
    return res(n, sum+i, i+1);
}

int main(int argc, char** argv)
{
    int n;
    cin>>n;
    cout<<res(n,0,0)<<endl;
    return 0;
}