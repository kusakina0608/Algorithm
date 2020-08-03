//
// Created by LKina on 2020-02-25.
//
#include <stdio.h>
int d[1000001];
int main() {
    d[0] = 1;
    for (int i=1; i<=1000000; i++) {
        if (i-1 >= 0) {
            d[i] += d[i-1];
        }
        if (i-2 >= 0) {
            d[i] += d[i-2];
        }
        if(d[i]>=1000000009){
            d[i] %= 1000000009;
        }
        if (i-3 >= 0) {
            d[i] += d[i-3];
        }
        if(d[i]>=1000000009){
            d[i] %= 1000000009;
        }
    }
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",d[n]);
    }
}