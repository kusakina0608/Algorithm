//
// Created by Kina on 2020/02/15.
//
#include<iostream>
using namespace std;

bool AreYouAlpha(char c){
    if(('A'<=c && c<='Z') || ('a'<=c && c<='z'))
        return true;
    return false;
}
char Alpha2Upper(char c){
    if('a'<=c && c<='z'){
        return c-('a'-'A');
    }
    else return c;
}

int main(int argc, char** argv){
    char c;
    while(cin>>c){
        if(AreYouAlpha(c)){
            cout<<Alpha2Upper(c);
        }else{
            cout<<c;
        }
    }
    return 0;
}