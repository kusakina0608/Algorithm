//
// Created by Kina on 2020/02/09.
//
#include <iostream>
#include <cstring>
using namespace std;

int main(void){
    int alphabet[26]={-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
    char str[100];
    int len;
    cin>>str;
    len=strlen(str);
    for(int i=0; i<len; i++){
        if(alphabet[str[i]-'a']==-1){
            alphabet[str[i]-'a']=i;
        }
    }
    for(int i=0; i<26; i++){
        cout<<alphabet[i]<<' ';
    }
    return 0;
}