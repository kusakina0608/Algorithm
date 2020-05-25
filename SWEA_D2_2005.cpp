//
// Created by Kina on 2020/05/25.
//
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    int ** pascal=NULL;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin>>n;
        pascal = new int*[n];
        cout<<'#'<<test_case<<endl;
        for(int i=0; i<n; i++){
            pascal[i] = new int[i+1];
            for(int j=0; j<i+1; j++){
                if(j==0 || j==i)
                    pascal[i][j]=1;
                else
                    pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
                cout<<pascal[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}