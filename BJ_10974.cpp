//
// Created by Kina on 2020/02/11.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    int n=0;
    cin>>n;
    vector<int> a(n);
    for(int i=1; i<=n; i++){
        a[i-1]=i;
    }
    do{
        for(int i=0; i<n; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
    }while(next_permutation(a.begin(), a.end()));
    return 0;
}