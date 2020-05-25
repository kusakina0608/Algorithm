//
// Created by Kina on 2020/05/25.
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int test_case;
    int T;
    int n, max_weight, weight_sum, weight; //과자의 수, 최대 무게, 무게 합계, 가지고 갈 수 있는 무게
    int* product = NULL;
    int i,j;
    setbuf(stdout, NULL);
    scanf("%d", &T);

    for (test_case = 1; test_case <= T; ++test_case)
    {
        printf("#%d ", test_case);
        scanf("%d %d", &n, &max_weight);
        weight = -1;
        product = (int*)malloc(sizeof(int)* n);
        if(product == NULL)
            printf("error\n");
        for(i = 0; i<n; i++){
            scanf("%d", &product[i]);
        }
        for(i = 0; i<n-1; i++){
            for(j = i+1; j<n; j++){
                weight_sum = product[i] + product[j];
                if( (weight_sum <= max_weight) && (weight_sum > weight) ){
                    weight = weight_sum;
                }
            }
        }
        printf("%d\n", weight);
    }
    return 0;
}