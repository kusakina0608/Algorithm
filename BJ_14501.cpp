//
// Created by Kina on 2020/02/13.
//
#include <iostream>
using namespace std;

int CalcMaxProfit(int ** cost, int sum, int index, int N){
    int tmp1=0, tmp2=0;
    if(index==N) return sum;
    if(index+cost[index][0]<=N) {
        tmp1=CalcMaxProfit(cost, sum + cost[index][1], index + cost[index][0], N); //선택
    }
    if(index+1<=N) {
        tmp2=CalcMaxProfit(cost, sum, index + 1, N); //미선택
    }
    if(sum>tmp1 && sum>tmp2) return sum;
    if(tmp1>sum && tmp1>tmp2) return tmp1;
    return tmp2;
}

int main(void){
    int N;
    cin>>N;
    int** costTable = new int*[N];
    for(int i=0; i<N; i++){
        costTable[i]=new int[2];
        cin>>costTable[i][0]>>costTable[i][1];
    }
    cout<<CalcMaxProfit(costTable, 0, 0, N);
}
