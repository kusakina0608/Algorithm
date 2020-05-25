//
// Created by Kina on 2020/05/25.
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int test_case;
    int T;
    int k;
    int val;
    int* stack;
    int top=0;
    int sum=0;

    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d", &k);
        stack = (int*)malloc(sizeof(int)*k);
        top=0;
        for(int i=0; i<k; i++){
            scanf("%d", &val);
            if(val==0){
                top--;
            }else{
                stack[top++]=val;
            }
        }
        sum=0;
        for(int i=0; i<top; i++){
            sum+=stack[i];
        }
        printf("#%d %d\n", test_case, sum);
    }
    return 0;
}