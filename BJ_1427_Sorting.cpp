// TODO change to C++ style
// Created by Kina on 2020/05/04.
//
#include <stdio.h>
#include <string.h>

int main(void){
    char s[] = "1000000000";
    int n_digit, i, j;
    int d[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    scanf(" %s", s);

    n_digit = strlen(s);

    for(i=0; i<n_digit; i++){
        d[i] = s[i]-'0';
    }

    for(i=0; i<n_digit-1; i++){
        for(j=0; j<n_digit-i; j++){
            if(d[j]<d[j+1]){
                d[j]=d[j]^d[j+1];
                d[j+1]=d[j]^d[j+1];
                d[j]=d[j]^d[j+1];
            }
        }
    }

    for(i=0; i<n_digit; i++){
        s[i] = d[i]+'0';
    }
    s[i] = 0;

    printf("%s",s);

    return 0;
}