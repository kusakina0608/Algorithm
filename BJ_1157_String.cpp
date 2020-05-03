//
// Created by Kina on 2020/02/09.
//
#include <iostream>
#include <cstring>
using namespace std;

int main(void){
    char str[1000001];
    static int alpha[26];
    cin>>str;
    int len=strlen(str);
    for(int i=0; i<len; i++){
        alpha[tolower(str[i])-'a']++;
    }

    int count=1, max=0;
    for(int i=1; i<26; i++){
        if(alpha[i]>alpha[max]){
            max=i;
            count=1;
        }
        else if(alpha[i]==alpha[max]){
            count++;
        }
    }
    if(count>1) {
        cout<<'?';
    }else{
        cout<<char(max+'A');
    }
}