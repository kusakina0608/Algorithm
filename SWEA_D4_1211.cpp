//
// Created by Kina on 2020/05/25.
//
#include<iostream>

using namespace std;

typedef struct Start Start;

struct Start {
    int x;
    int y;
    int count;
    Start* next;
};

int main(int argc, char** argv)
{
    int test_case;
    int num;

    for(test_case = 1; test_case <= 10; ++test_case)
    {
        cin >> num;
        int arr[100][100];
        bool check[100][100];
        int val = 0, x = 0, y = 0, i, j;
        int min_cnt=2147483647, result=0;
        bool horizontal_move = false;
        Start sp;
        Start* ptr = NULL;

        ptr = &sp;
        for(i = 0; i < 100; i++){
            for(j = 0; j < 100; j++){
                scanf("%d", &val);
                if(i==0 && val==1){
                    ptr->next = new Start();
                    ptr = ptr->next;
                    ptr->x = j;
                    ptr->y = i;
                    ptr->count = 0;
                    sp.count++;
                }
                arr[i][j] = val;
                check[i][j] = true;
            }
        }
        ptr = sp.next;
        for(; ptr != NULL; ptr = ptr->next){
            x = ptr->x;
            y = ptr->y;
            //printf("(%d, %d)\t", x, y);
            //printf("(next: %p\t)", ptr->next);
            while(y<99){
                check[y][x] = false;
                if( x>0 && check[y][x-1] && arr[y][x-1] ){
                    x--;
                }else if( x<99 && check[y][x+1] && arr[y][x+1] ){
                    x++;
                }else{
                    y++;
                }
                (ptr->count)++;
            }
            if(ptr->count<min_cnt){
                result = ptr->x;
                min_cnt = ptr->count;
            }
            //printf("count: %d\n", ptr->count);
            for(i = 0; i<100; i++)
                for(j = 0; j<100; j++)
                    check[i][j] = true;
        }
        printf("#%d %d\n", num, result);
    }
    return 0;
}