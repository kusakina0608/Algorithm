//
// Created by LKina on 2020-02-25.
//
#include <iostream>
using namespace std;
int max2(int a, int b){
    return a>b?a:b;
}
int max3(int a, int b, int c){
    if(a>=b && a>=c)
        return a;
    if(b>=c && b>=a)
        return b;
    return c;
}

int main(void){
    int T, tc;
    scanf("%d", &T);
    for(tc=1; tc<=T; ++tc){
        int n;
        scanf("%d", &n);
        int** score=new int*[2];
        for(int i=0; i<2; i++){
            score[i]=new int[n];
            for(int j=0; j<n; j++){
                scanf("%d", &score[i][j]);
            }
        }
        int** d=new int*[n];
        for(int i=0; i<n; i++){
            d[i]=new int[3];
        }
        d[0][0]=0;
        d[0][1]=score[0][0];
        d[0][2]=score[1][0];
        for(int i=1; i<n; i++){
            d[i][0]=max3(d[i-1][0], d[i-1][1], d[i-1][2]);
            d[i][1]=max2(d[i-1][0], d[i-1][2])+score[0][i];//take upper side
            d[i][2]=max2(d[i-1][0], d[i-1][1])+score[1][i];//take lower side
        }
        printf("%d\n", max3(d[n-1][0], d[n-1][1], d[n-1][2]));

        for(int i=0; i<n; i++){
            delete[] d[i];
        }
        delete[] d;
        delete[] score[1];
        delete[] score[0];
        delete[] score;
    }
    return 0;
}