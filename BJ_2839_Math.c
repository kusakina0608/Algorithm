//
// Created by Kina on 2020/05/25.
//
#include <stdio.h>

int main(void){
    // Check 3a+5b=N
    int a=0, b=0, n=0, remainder, quotient;
    scanf("%d", &n);

    for(b=(n/5)*5;b>=0;b-=5){
        if((n-b)%3==0){
            a= b/5 + (n-b)/3;
            printf("%d\n",a);
            return 0;
        }
    }
    printf("%d\n",-1);
    return 0;
}