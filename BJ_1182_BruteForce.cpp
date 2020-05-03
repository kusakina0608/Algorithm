//
// Created by Kina on 2020/02/13.
//
#include <iostream>
using namespace std;

int main(void){
    int set;
    int n, target, count=0;
    cin>>n>>target;
    int* arr=new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=1; i<(1<<n); i++){
        int sum=0;
        for(int j=0; j<20; j++){
            if((i>>j)&1){
                sum+=arr[j];
            }
        }
        if(sum==target) count++;
    }
    cout<<count;
}