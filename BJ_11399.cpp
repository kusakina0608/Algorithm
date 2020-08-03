//
// Created by Kina on 2020/02/08.
//
#include <iostream>
using namespace std;

int main(void){
    int num, sum=0;
    int* leadTime=NULL;

    cin>>num;
    leadTime=new int[num];
    for(int i=0; i<num; i++){
        cin>>leadTime[i];
    }

    for(int i=num-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(leadTime[j]>leadTime[j+1]){
                leadTime[ j ] = leadTime[ j ]^leadTime[j+1];
                leadTime[j+1] = leadTime[ j ]^leadTime[j+1];
                leadTime[ j ] = leadTime[ j ]^leadTime[j+1];
            }
        }

    }
    for(int i=0; i<num; i++){
        sum+=leadTime[i]*(num-i);
    }

    cout<<sum;

    delete[] leadTime;
    return 0;
}