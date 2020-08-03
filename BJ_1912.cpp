//
// Created by LKina on 2020-02-27.
//
#include <iostream>
using namespace std;

int main(void){
    int n, max=-2147483648;
    scanf("%d", &n);
    int* seq=new int[n];
    int* res=new int[n];
    scanf("%d", &seq[0]);
    res[0]=seq[0];
    for(int i=1; i<n; i++){
        scanf("%d", &seq[i]);
        if(res[i-1]+seq[i]<seq[i]){
            res[i]=seq[i];
        }
        else{
            res[i]=res[i-1]+seq[i];
        }
    }
    for(int i=0; i<n; i++){
        if(max<res[i]) max=res[i];
    }
    delete[] seq;
    delete[] res;
    printf("%d", max);
    return 0;
}