//
// Created by Kina on 2020/05/25.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        cin>>N;
        int a, sum = 0;
        vector<int> price;
        for(int i=0; i<N; i++){
            cin>>a;
            price.push_back(a);
        }
        sort(price.begin(), price.end(), cmp);
        for(int i=N-1; i>=0; i--){
            if(i%3==2) continue;
            else sum+=price[i];
        }
        cout<<'#'<<test_case<<' '<<sum<<'\n';
    }
    return 0;
}