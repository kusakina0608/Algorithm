// TODO change to C++ style
// Created by Kina on 2020/02/08.
//
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int num, max_count, jump_amount, cur_idx, sum;
    int* counter=NULL;

    scanf("%d %d %d", &num, &max_count, &jump_amount);
    counter=(int*)malloc(sizeof(int)*num);

    cur_idx=0;
    sum=0;
    while(1){
        counter[cur_idx]++;
        sum++;
        if(counter[cur_idx]==max_count)
            break;
        if(counter[cur_idx]%2==1){
            cur_idx+=jump_amount;
            if(cur_idx>=num){
                cur_idx%=num;
            }
        }else{
            cur_idx-=jump_amount;
            if(cur_idx<0){
                cur_idx+=num;
            }
        }
    }
    printf("%d", sum-1);
    free(counter);
}