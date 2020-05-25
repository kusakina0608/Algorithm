//
// Created by Kina on 2020/05/25.
//
#include <stdio.h>
int main(void)
{
    int test_case;
    int T;
    char board[5][15];
    int len[5];
    int count;
    char str[16];
    char c;
    setbuf(stdout, NULL);
    scanf("%d", &T);

    for (test_case = 1; test_case <= T; ++test_case)
    {
        for(int i = 0; i<5; i++){
            for(int j = 0; j<15; j++){
                board[i][j] = '\0';
            }
        }

        for(int i = 0; i<5; i++){
            count = 0;
            scanf("%s", str);
            count = 0;
            while(1){
                c = str[count];
                if(c == '\0'){
                    break;
                }
                board[i][count] = c;
                count++;
            }
            len[i] = count;
        }
        printf("#%d ", test_case);
        for(int i = 0; i<15; i++){
            for(int j = 0; j<5; j++){
                c = board[j][i];
                if(c != '\0'){
                    printf("%c", c);
                }
            }
        }
        printf("\n");
    }
    return 0;
}