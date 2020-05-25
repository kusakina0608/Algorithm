//
// Created by Kina on 2020/02/14.
//
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int max=0, val=0;
        for(int i=0; i<10; i++){
            cin>>val;
            max=val>max?val:max;
        }
        cout<<'#'<<test_case<<' '<<max<<endl;
    }
    return 0;
}