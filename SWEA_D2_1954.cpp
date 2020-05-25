//
// Created by Kina on 2020/05/25.
//
#include<iostream>

using namespace std;

typedef struct{
    int y;
    int x;
} point;

inline bool check_range(point next_point, int n){
    return ( (next_point.y>=n) || (next_point.x >=n) ) || ( (next_point.y<0) || (next_point.x<0) );
}
point next_coordinate(int direction, int y, int x){
    point next_point;
    next_point.y = y;
    next_point.x = x;
    switch(direction){
        case 0:
            next_point.x++;
            break;
        case 1:
            next_point.y++;
            break;
        case 2:
            next_point.x--;
            break;
        case 3:
            next_point.y--;
    }
    return next_point;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int snail[10][10];
        int n = 0;
        int y=0, x=0;
        int direction=0;
        point next_point;

        cin >> n;
        for(int i = 0; i <n*n; i++){
            //printf(&quot;(%d,%d)\n&quot;, y, x);
            snail[y][x] = i+1;
            next_point = next_coordinate(direction, y, x);
            if( ( check_range(next_point, n) ) || ( ((snail[next_point.y][next_point.x])!=0) ) ){
                direction = (direction+1)%4;
                //cout<< &quot;turn to &quot;<< direction<<endl;
                next_point = next_coordinate(direction, y, x);
            }
            y = next_point.y;
            x = next_point.x;
        }
        printf(&quot;#%d\n&quot;,test_case);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                printf(&quot;%d &quot;, snail[i][j]);
            }
            printf(&quot;\n&quot;);
        }
        for(int i = 0; i<10; i++)
            for(int j = 0; j<10; j++)
                snail[i][j] = 0;
    }
    return 0;
}