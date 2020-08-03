//
// Created by Kina on 2020/05/03.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
vector<string> str_list[64];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++){
        string s;
        cin>>s;
        int idx = s.size();
        str_list[idx].push_back(s);
    }
    for(int i=0; i<=50; i++){
        int num = str_list[i].size();
        sort(str_list[i].begin(), str_list[i].end());
        string prev_str = "";
        for(int j=0; j<num; j++){
            if(str_list[i][j] != prev_str)
                cout<<str_list[i][j]<<'\n';
            prev_str = str_list[i][j];
        }
    }
    return 0;
}