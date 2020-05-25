//
// Created by Kina on 2020/05/01.
//
#include <iostream>
#include <string.h>
#define INF 2147483647
using namespace std;

int N;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    int* d = new int[N+1];
    for(int i=0; i<N; i++){
        cin>>d[i]>>d[i+1];
    }

    int** memo = new int*[N+1];
    for(int i=0; i<=N; i++){
        memo[i] = new int[N+1];
        memset(memo[i], 0, sizeof(memo));
    }

    for(int L=1; L<N; L++){
        for(int i=1; i<=N-L; i++){ // condition i<N-L is equal to i+L<N. and j=i+L therefore i<N-L is equal to j<N
            int j = i+L;
            memo[i][j] = INF; // initialize value
            for(int k=i; k<j; k++){ // k = [i, j-1]
                int tmp = memo[i][k] + memo[k+1][j] + d[i-1]*d[k]*d[j];
                if(tmp<memo[i][j])
                    memo[i][j] = tmp;
            }
        }
    }

    cout<< memo[1][N];
    for(int i=0; i<=N; i++){
        delete[] memo[i];
    }
    delete[] memo;
    return 0;
}