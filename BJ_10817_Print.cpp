//
// Created by Kina on 2020/02/08.
//
#include <iostream>
using namespace std;

int main(void){
    int arr[3];
    cin>>arr[0]>>arr[1]>>arr[2];
    for(int i=2; i>0; i--){
        for(int j=0; j<i; j++){
            if(arr[j]>arr[j+1]){
                arr[j]   = arr[j]^arr[j+1];
                arr[j+1] = arr[j]^arr[j+1];
                arr[j]   = arr[j]^arr[j+1];
            }
        }
    }
    cout<<arr[1];
    return 0;
}