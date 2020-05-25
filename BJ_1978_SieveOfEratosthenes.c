//
// Created by Kina on 2020/05/25.
//
#include <stdio.h>
#include <math.h>

int main(void){
    int n, i, j, val, count = 0, root;
    scanf("%d", &n);

    for(i=0;i<n;i++){
        scanf("%d", &val);
        if(val==1) continue;
        root = sqrt(val);
        for(j=root;j>1; j--){
            if(val%j==0)
                break;
        }
        if(j==1) count++;
    }
    printf("%d\n",count);

    return 0;
}