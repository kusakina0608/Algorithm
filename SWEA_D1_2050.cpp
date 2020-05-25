//
// Created by Kina on 2020/02/15.
//
#include<iostream>
using namespace std;

int UpperAlpha2Int(char c){
    return int(c-'A')+1;
}

int LowerAlpha2Int(char c){
    return int(c-'a')+1;
}

int a2i(char c){
    if(c>='A' && c<='Z') return UpperAlpha2Int(c);
    if(c>='a' && c<='z') return LowerAlpha2Int(c);
    else return -1;
}

int main(int argc, char** argv)
{
    char c;
    while(cin>>c){
        cout<<a2i(c)<<' ';
    }
    return 0;
}