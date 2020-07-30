//
// Created by Kina on 2020/07/29.
//
#include<iostream>
using namespace std;

int test_case, T, N, M, i, j, max_sum, sum;
int *a, *b;

int go(int* a, int* b, int size_a, int size_b){
    max_sum = -2147483648;
    for(i=0; i<=size_a-size_b; i++){
        sum = 0;
        for(j=0; j<size_b; j++){
            sum += a[i+j]*b[j];
        }
        if(max_sum<sum){
            max_sum=sum;
        }
    }
    return max_sum;
}

int main(int argc, char** argv)
{
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>N>>M;
        a = new int[N];
        b = new int[M];
        for(i=0; i<N; i++){
            cin>>a[i];
        }
        for(i=0; i<M; i++){
            cin>>b[i];
        }

        if(N>M){
            go(a,b,N,M);
        }else{
            go(b,a,M,N);
        }
        cout<<'#'<<test_case<<' '<<max_sum<<'\n';
    }
    return 0;
}