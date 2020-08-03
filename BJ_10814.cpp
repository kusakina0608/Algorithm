//
// Created by Kina on 2020/05/15.
//
#include <iostream>
#include <vector>
using namespace std;

int N;
int Age;
string Name;

vector<pair<int, string>> user;
vector<pair<int, string>> counting[256];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>Age>>Name;
        user.push_back(make_pair(Age, Name));
    }

    for(int i=0; i<N; i++){
        counting[user[i].first].push_back(user[i]);
    }

    for(int i=0; i<256; i++){
        for(int j=0; j<counting[i].size(); j++){
            cout<<counting[i][j].first<<' '<<counting[i][j].second<<'\n';
        }
    }

    return 0;
}