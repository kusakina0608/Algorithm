//
// Created by Kina on 2020/04/15.
//
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 2147483647

int budget[131072];
int N, M, MAX=0;

bool findMin(int mid){
    int cnt=1;
    int current=mid;
    if(mid<MAX) return false;
    for(int i=0; i<N; i++){
        if(current<budget[i]){
            current=mid;
            cnt++;
        }
        current-=budget[i];
    }
    return M>=cnt;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int budget_min=1, budget_max=0;

    int sum;
    cin>>N>>M;
    for(int i=0; i<N; i++) {
        cin>>budget[i];
        budget_max+=budget[i];
        MAX=budget[i]>MAX?budget[i]:MAX;
    }

    int result = 0;
    while (budget_min <= budget_max){
        int mid = (budget_min + budget_max) / 2;
        if (findMin(mid)){
            result = mid;
            budget_max = mid - 1;
        }
        else
            budget_min = mid + 1;
    }
    cout<<result;
    return 0;
}
