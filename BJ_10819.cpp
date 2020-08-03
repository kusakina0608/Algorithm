//
// Created by Kina on 2020/02/11.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        scanf("%d", &vec[i]);
    }
    sort(vec.begin(), vec.end());
    int max=0;
    do{
        int sum=0;
        for(int i=0; i<n-1; i++){
            sum+=abs(vec[i]-vec[i+1]);
        }
        if(max<sum){
            max=sum;
        }
    }while(next_permutation(vec.begin(), vec.end()));

    printf("%d", max);

    return 0;
}