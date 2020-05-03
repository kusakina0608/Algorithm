//
// Created by Kina on 2020/05/03.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> a;
vector<int> b;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int val;
    for(int i=0; i<N; i++){
        cin>>val; a.push_back(val);
    }
    for(int i=0; i<N; i++){
        cin>>val; b.push_back(val);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int result = 0;
    for(int i=0; i<N; i++){
        result += a[i]* b[N-i-1];
    }
    cout<<result;
    return 0;
}