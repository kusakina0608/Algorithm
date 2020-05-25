//
// Created by Kina on 2020/05/25.
//
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T, num;

    for(test_case = 1; test_case <= 10; ++test_case)
    {
        cin >> num;
        int arr[100][100];
        bool check[100][100];
        int val = 0, x = 0, y = 0, i = 0, j =0;

        for(i = 0; i < 100; i++){
            for(j = 0; j < 100; j++){
                scanf("%d", &val);
                arr[i][j] = val;
                check[i][j] = true;
                if (val == 2) { x=j; y=i; }
            }
        }
        while(y > 0){
            check[y][x] = false;
            if( x>0 && check[y][x-1] && arr[y][x-1] ){ // move left
                x--;
            }else if( x<99 && check[y][x+1] && arr[y][x+1] ){ // move right
                x++;
            }
            else{ // move upward
                y--;
            }
        }
        printf("#%d %d\n", test_case, x);
    }
    return 0;
}