//
// Created by Kina on 2020/05/25.
//
#include <stdio.h>
int main(void){
    int test_case;
    int T;
    int num;
    static int score[101];
    int mode = 0;
    int val;

    setbuf(stdout, NULL);
    scanf("%d", &T);

    for (test_case = 1; test_case <= T; ++test_case){
        scanf("%d", &num);
        for(int i = 0; i<1000; i++){
            scanf("%d", &val);
            score[val]++;
        }
        for(int i = 0; i<101; i++){
            if(score[mode] <= score[i]){
                mode = i;
            }
        }
        printf("#%d %d\n", num, mode);

        for(int i=0; i < 101; i++){
            score[i] = 0;
        }
    }
    return 0;
}