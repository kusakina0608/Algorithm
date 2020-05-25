//
// Created by LKina on 2020-02-25.
//
#include <iostream>
using namespace std;

int d[101][10];

int main(void){
    for(int i=1; i<10; i++){
        d[1][i]=1;
    }
    int n;
    cin>>n;
    for(int i=2; i<=n; i++){
        d[i][0] = d[i-1][1];
        d[i][1] = d[i-1][0]+d[i-1][2]; if(d[i][1]>=1000000000) d[i][1]%=1000000000;
        d[i][2] = d[i-1][1]+d[i-1][3]; if(d[i][2]>=1000000000) d[i][2]%=1000000000;
        d[i][3] = d[i-1][2]+d[i-1][4]; if(d[i][3]>=1000000000) d[i][3]%=1000000000;
        d[i][4] = d[i-1][3]+d[i-1][5]; if(d[i][4]>=1000000000) d[i][4]%=1000000000;
        d[i][5] = d[i-1][4]+d[i-1][6]; if(d[i][5]>=1000000000) d[i][5]%=1000000000;
        d[i][6] = d[i-1][5]+d[i-1][7]; if(d[i][6]>=1000000000) d[i][6]%=1000000000;
        d[i][7] = d[i-1][6]+d[i-1][8]; if(d[i][7]>=1000000000) d[i][7]%=1000000000;
        d[i][8] = d[i-1][7]+d[i-1][9]; if(d[i][8]>=1000000000) d[i][8]%=1000000000;
        d[i][9] = d[i-1][8];
    }
    int result=0;
    for(int i=0; i<10; i++){
        result+=d[n][i];
        if(result>=1000000000) result%=1000000000;
    }
    cout<<result;
    return 0;
}