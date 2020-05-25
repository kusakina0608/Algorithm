//
// Created by Kina on 2020/05/25.
//
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    string s;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>s;
        bool res=true;
        int len=s.length();
        for(int i=0; i<len/2; i++){
            if(s[i]!=s[len-i-1]){
                res=false;
                break;
            }
        }
        cout<<'#'<<test_case<<' '<<res<<endl;
    }
    return 0;
}