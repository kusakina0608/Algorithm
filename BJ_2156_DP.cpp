//
// Created by LKina on 2020-02-25.
//
#include <iostream>
using namespace std;
int main(void){
    int n;
    scanf("%d", &n);
    int* a=new int[n];
    int* d=new int[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    d[0]=a[0];
    d[1]=d[0]+a[1];
    d[2]=(a[1]+a[2])>d[1]?(a[1]+a[2]):d[1];
    if(d[0]+a[2]>d[2]) d[2]=d[0]+a[2];
    for(int i=3; i<n; i++){
        d[i]=d[i-1];
        int tmp=d[i-2]+a[i];
        if(tmp>d[i]) d[i]=tmp;
        tmp=d[i-3]+a[i-1]+a[i];
        if(tmp>d[i]) d[i]=tmp;
    }
    printf("%d", d[n-1]);
    return 0;
}