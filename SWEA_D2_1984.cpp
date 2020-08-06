//
// Created by Kina on 2020/08/05.
//
#include <iostream>
#include <cmath>
using namespace std;

int T;
int arr[10];

int main() {
    cin>>T;
    for(int t=1; t<=T; t++){
        int min=2147483647;
        int min_idx=-1;
        int max=-2147483648;
        int max_idx=-1;
        for(int i=0; i<10; i++){
            cin>>arr[i];
            if(arr[i]>max){
                max=arr[i];
                max_idx=i;
            }
            if(arr[i]<min){
                min=arr[i];
                min_idx=i;
            }
        }
        int sum = 0;
        for(int i=0; i<10; i++){
            if(i!=min_idx && i!=max_idx){
                sum+=arr[i];
            }
        }
        cout<<'#'<<t<<' '<<round(sum/8.0)<<'\n';
    }
    return 0;
}