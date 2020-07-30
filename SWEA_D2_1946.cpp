//
// Created by Kina on 2020/07/29.
//
#include<iostream>
using namespace std;

int test_case, T, N, cnt, col;
char c;

int main(int argc, char** argv)
{
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>N;
        col = 0;
        cout<<'#'<<test_case<<'\n';
        for(int i=0; i<N; i++){
            cin>>c>>cnt;
            while(cnt){
                cout<<c;
                col++;
                if(col==10){
                    cout<<'\n';
                    col = 0;
                }
                cnt--;
            }
        }
        if(col!=0) cout<<'\n';
    }
    return 0;
}