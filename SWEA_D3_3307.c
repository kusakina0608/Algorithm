//
// Created by Kina on 2020/05/25.
//
#include <stdio.h>
int main(void)
{
    int test_case;
    int T;
    int n, i, j, len;

    setbuf(stdout, NULL);
    scanf("%d", &T);

    for (test_case = 1; test_case <= T; ++test_case)
    {
        unsigned int seq[1001];
        int love[1001];
        scanf("%d", &n);

        seq[0] = 0;

        for(i=1; i<=n; i++){
            scanf("%u", seq+i);
        }

        for(i=1; i<=n; i++){
            len = 0;
            for(j=0; j<i; j++){
                if(seq[j] < seq[i]){
                    if(len < love[j]){
                        len = love[j];
                    }
                }
            }
            love[i] = len+1;
        }

        len = 0;
        for(i=1; i<=n; i++){
            if(len < love[i]){
                len = love[i];
            }
        }

        printf("#%d %d\n", test_case, len);
    }
    return 0;
}