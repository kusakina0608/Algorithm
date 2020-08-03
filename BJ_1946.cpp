//
// Created by Kina on 2020/04/23.
//
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int T, N; // T: number of test case, N: number of applicant

int main(void){
    int x, y;
    vector<pair<int, int>> ranking;
    scanf("%d", &T);
    for(int test_case=1; test_case<=T; ++test_case){
        ranking.clear();
        scanf("%d", &N);
        for(int i=0; i<N; i++){
            scanf("%d %d", &x, &y);
            ranking.push_back(make_pair(x, y));
        }
        sort(ranking.begin(), ranking.end());

        int bound = ranking[0].second;
        int count = N;

        for(int i=1; i<N; i++){
            if(ranking[i].second > bound) count--;
            else bound = ranking[i].second;
        }

        printf("%d\n", count);
    }

    return 0;
}