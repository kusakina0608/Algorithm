//
// Created by LKina on 2020-02-25.
//
#include <iostream>
#include <string.h>
using namespace std;

int main(void){
    int n, max=1;
    scanf("%d", &n);
    int* seq=new int[n];
    int* len=new int[n];
    scanf("%d", &seq[0]);
    len[0]=1;
    for(int i=1; i<n; i++){
        scanf("%d", &seq[i]);
        len[i]=1;
        for(int j=0; j<i; j++){
            if(seq[j]<seq[i] && len[j]>=len[i]){
                len[i]=len[j]+1;
            }
        }
        if(max<len[i]) max=len[i];
    }
    //for(int i=0; i<n; i++) cout<<len[i]<<' ';
    printf("%d", max);
    delete[] seq;
    return 0;
}