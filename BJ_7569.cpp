//
// Created by Kina on 20. 11. 3..
//
#include <iostream>

using namespace std;

int map[100][100][100], N, M, H, cnt, total;
int queue[110000][3];
int front, rear;
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

bool is_in(int x, int y, int z){
    return 0<=x && x<N && 0<=y && y<M && 0<=z && z<H;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cnt = 0;
    front = 0;
    rear = 0;
    cin>>N>>M>>H;
    for(int z=0; z<H; z++){
        for(int y=0; y<M; y++){
            for(int x=0; x<N; x++){
                cin>>map[x][y][z];
                if(map[x][y][z] == 1){
                    queue[rear][0] = x;
                    queue[rear][1] = y;
                    queue[rear][2] = z;
                    rear++;
                    cnt++;
                }
                if(map[x][y][z] != -1){
                    total++;
                }
            }
        }
    }
    queue[rear][0] = -1;
    queue[rear][1] = -1;
    queue[rear][2] = -1;
    rear++;
    int day = 0;
    while(front < rear){
        int x = queue[front][0];
        int y = queue[front][1];
        int z = queue[front][2];
        front++;
        if(x == -1 && y == -1 && z == -1){
            day++;
            queue[rear][0] = -1;
            queue[rear][1] = -1;
            queue[rear][2] = -1;
            rear++;
        }
        for(int k=0; k<6; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nz = z + dz[k];
            if(is_in(nx, ny, nz) && map[nx][ny][nz] == 0){
                map[nx][ny][nz] = 1;
                cnt++;
                queue[rear][0] = nx;
                queue[rear][1] = ny;
                queue[rear][2] = nz;
                rear++;
            }
        }
    }
    if(total == cnt){
        cout<<day;
    }
    else{
        cout<<-1;
    }
    return 0;
}