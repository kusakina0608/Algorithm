//
// Created by Kina on 2020/05/25.
//
#include <stdio.h>
#include <memory.h>

int n;
int snake[21][2];//지렁이 및 좌표
int visit[21];
long long minimum;

void dfs(int ptr, int cnt)
{
    if (cnt == n / 2)
    {
        long long x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            if (visit[i] == 0)
            {
                x += snake[i][0];
                y += snake[i][1];
            }
            else
            {
                x -= snake[i][0];
                y -= snake[i][1];
            }
        }
        if (x*x + y*y < minimum)
            minimum = x*x + y*y;
        return;
    }

    for (int i = ptr; i < n; i++)
    {
        if (visit[i] == 0)//이미 짝이 있는 지렁이는 패스
        {
            visit[i] = 1;
            dfs(i + 1, cnt + 1);
            visit[i] = 0;
        }
    }
}
int main(void) {
    int T;
    setbuf(stdout, NULL);
    scanf("%d\n", &T);
    for (int test_case = 1; test_case <= T; test_case++)
    {
        memset(visit, 0, sizeof(visit));
        memset(snake, 0, sizeof(snake));
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &snake[i][0], &snake[i][1]);
        }
        minimum = 1e18;

        dfs(0, 0);

        printf("#%d %lld\n", test_case, minimum);

    }
    return 0;
}