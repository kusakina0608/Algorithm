//
// Created by Kina on 2020/02/18.
//
#include <iostream>
#include <queue>
using namespace std;

int di[]={-1, -1, -1, 0, 1, 1, 1, 0};
int dj[]={-1, 0, 1, 1, 1, 0, -1, -1};

void bfs(int** map, int height, int width, int i, int j, int count) {
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    map[i][j]+=count;
    while(!q.empty()){
        i=q.front().first;
        j=q.front().second;
        q.pop();
        for(int k=0; k<8; k++){
            int ni=i+di[k];
            int nj=j+dj[k];
            if (0 <= ni && 0 <= nj && ni < height && nj < width) {
                if(map[ni][nj]==1){
                    q.push(make_pair(ni, nj));
                    map[ni][nj]+=count;
                }
            }
        }
    }
}

int main(void){
    while(true){
        int width, height;
        scanf("%d %d", &width, &height);
        if(width==0 && height==0) break;
        int** map=new int*[height];
        for(int i=0; i<height; i++){
            map[i]=new int[width];
            for(int j=0; j<width; j++){
                scanf("%d", &map[i][j]);
            }
        }
        int count=0;
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                if(map[i][j]==1){
                    bfs(map, height, width, i, j, ++count);
                }
            }
        }
        printf("%d\n", count);
        for(int i=0; i<height; i++){
            delete[] map[i];
        }
        delete[] map;
    }
    return 0;
}