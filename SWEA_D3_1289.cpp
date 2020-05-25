//
// Created by Kina on 2020/05/25.
//
#include<iostream>
#include<cstring>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    static int len, count, i;
    char c = '0';
    char mem[51];

    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> mem;

        c = '0';
        len = strlen(mem);
        count = 0;

        for(i = 0; i<len; i++){
            if(mem[i] != c){
                c = mem[i];
                count++;
            }
        }
        cout<<"#"<<test_case<<" "<<count<<endl;
    }
    return 0;
}