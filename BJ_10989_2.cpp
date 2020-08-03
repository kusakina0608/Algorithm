//
// Created by Kina on 2020/05/03.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int check[10001];
vector<int> a;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int tmp;
    for(int i=0; i<N; i++){
        cin>>tmp;
        if(check[tmp]==0) {
            a.push_back(tmp);
        }
        check[tmp]++;
    }
    sort(a.begin(), a.end());
    for(int val : a){
        while(check[val]!=0){
            cout<<val<<'\n';
            check[val]--;
        }
    }
    return 0;
}