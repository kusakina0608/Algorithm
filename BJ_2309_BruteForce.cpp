//
// Created by Kina on 2020/02/10.
//
#include <iostream>
using namespace std;

int height[9];

int main(void){
    int height_sum=0;
    for(int i=0; i<9; i++){
        cin>>height[i];
        height_sum+=height[i];
    }

    bool found=false;
    int spy1, spy2;
    for(spy1=0; spy1<8; spy1++){
        for(spy2=1; spy2<9; spy2++){
            if(height_sum-height[spy1]-height[spy2]==100){
                found=true;
                break;
            }
        }
        if(found) break;
    }
    int result[7];
    int temp=128, temp_idx=-1;
    for(int i=0; i<7; i++){
        for(int j=0; j<9; j++){
            if(j!=spy1 && j!=spy2 && height[j]<temp) {
                temp = height[j];
                temp_idx=j;
            }
        }
        result[i]=temp;
        height[temp_idx]=temp=128;
    }
    for(int i=0; i<7; i++)
        cout<<result[i]<<endl;
    return 0;
}