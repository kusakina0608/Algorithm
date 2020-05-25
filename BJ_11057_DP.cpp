//
// Created by LKina on 2020-02-25.
//
#include <iostream>
using namespace std;

int d[1001][10];

int main(void){
    for(int i=0; i<10; i++){
        d[1][i]=1;
    }
    int n;
    cin>>n;
    for(int i=2; i<=n; i++){
        int sum=0;
        for(int j=0; j<10; j++){
            sum+=d[i-1][j];
            if(sum>=10007) sum%=10007;
            d[i][j]=sum;
        }
    }
    int result=0;
    for(int i=0; i<10; i++){
        result+=d[n][i];
        if(result>=10007) result%=10007;
    }
    cout<<result;
    return 0;
}