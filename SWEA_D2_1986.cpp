//
// Created by Kina on 2020/05/25.
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
        int n, sum=0;
        cin>>n;
        for(int i=1; i<=n; i++){
            if(i%2==1){
                sum+=i;
            }else{
                sum-=i;
            }
        }
        cout<<'#'<<test_case<<' '<<sum<<endl;
    }
    return 0;
}