//
// Created by Kina on 2020/02/19.
//
#include <iostream>
#include <queue>
using namespace std;

int main(void){
    int height, width;
    scanf("%d %d", &height, &width);
    char** maze=new char*[height];
    for(int i=0; i<height; i++){
        maze[i]=new char[width+1];
        scanf("%s", maze[i]);
    }

    int di[]={0, 1, 0, -1};
    int dj[]={1, 0, -1, 0};
    queue<pair<int, int>> q;
    queue<int> dist;
    int i=0, j=0, d=1;
    q.push(make_pair(i, j));
    dist.push(d);
    maze[i][j]='2';
    while(!q.empty()){
        i=q.front().first;
        j=q.front().second;
        d=dist.front();
        q.pop();
        dist.pop();
        if(i==height-1 && j==width-1) break;
        for(int k=0; k<4; k++){
            int ni=i+di[k];
            int nj=j+dj[k];
            if(0<=ni && 0<=nj && ni<height && nj<width){
                if(maze[ni][nj]=='1'){
                    q.push(make_pair(ni, nj));
                    dist.push(d+1);
                    maze[ni][nj]='2';
                }
            }
        }
    }
    printf("%d",d);
    for(int i=0; i<height; i++){
        delete[] maze[i];
    }
    delete[] maze;
    return 0;
}