//
// Created by Kina on 2020/04/23.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int, int>> meeting;
    int start, end;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>start>>end;
        meeting.push_back(make_pair(start, end));
    }
    sort(meeting.begin(), meeting.end(), cmp);

    int bound=meeting[0].second;
    int count=1;
    for(int i=1; i<N; i++){
        if(bound<=meeting[i].first){
            count++;
            bound=meeting[i].second;
        }
    }
    cout<<count;
    return 0;
}