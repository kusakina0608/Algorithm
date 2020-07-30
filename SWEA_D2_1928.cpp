//
// Created by Kina on 2020/07/29.
//
#include<iostream>
using namespace std;

char buffer[3];
char str[100001];

int main(int argc, char** argv)
{
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>str;
        int i=0, j=0, code=0;
        while(str[i]!='\0'){
            buffer[j++] = str[i++];
            if(j==3){
                code=0;
                buffer
            }
        }
    }
    return 0;
}