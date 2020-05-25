//
// Created by Kina on 2020/05/25.
//
#include <stdio.h>

typedef struct {
    int score;
    int calorie;
} ingredients;

int main(void)
{
    int test_case;
    int T;
    int n, cal_sum, max_cal, score_sum, final_score, i, count, flag;

    setbuf(stdout, NULL);
    scanf("%d", &T);

    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d %d", &n, &max_cal);
        ingredients data[20];	//ingredients array
        int rank[20];				  //Ranking index of ingredients
        final_score = 0;
        cal_sum = 0;

        /* Scan Input data and calculate score:calorie ratio */
        for (i=0; i<n;i++){
            scanf("%d %d", &((data+i)->score),  &((data+i)->calorie));
        }
        /* End Scan*/

        count = 1<<n;
        flag = 0;

        while(flag <= count){
            flag++;
            score_sum = 0;
            cal_sum = 0;
            for (i=0; i<n ;i++){
                if(flag&(1<<i)){
                    score_sum += (data+i)->score;
                    cal_sum +=(data+i)->calorie;
                }
            }
            if(cal_sum<=max_cal && score_sum > final_score){
                final_score = score_sum;
            }
        }
        /* Print result */
        printf("#%d %d\n", test_case, final_score);
    }
    return 0;
}