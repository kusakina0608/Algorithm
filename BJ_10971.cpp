//
// Created by Kina on 2020/02/11.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int weight[10][10];

int main(void){
    int nCity;
    scanf("%d", &nCity);

    for(int i=0; i<nCity; i++){
        for(int j=0; j<nCity; j++){
            scanf("%d", &weight[i][j]);
        }
    }
    vector<int> route(nCity);
    for(int i=0; i<nCity; i++){
        route[i]=i;
    }
    int min=2147483647;
    do{
        if(route[0]!=0) break;
        bool ok=true;
        int sum=0;
        for(int i=0; i<nCity-1; i++){
            if(weight[route[i]][route[i+1]]==0){
                ok=false;
                break;
            }
            sum+=weight[route[i]][route[i+1]];
        }
        if(weight[route[nCity-1]][route[0]]==0){
            ok=false;
        }
        sum+=weight[route[nCity-1]][route[0]];
        if(ok && sum<min){
            min=sum;
        }
    }while(next_permutation(route.begin(), route.end()));

    printf("%d", min);
    return 0;
}