//
// Created by Kina on 2020/02/21.
//
#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
using namespace std;

int bfs(int** map, int height, int width){
    int i=0, j=0;
    int distance=1;
    bool destroy=true;
    bool*** check=new bool**[2];
    for(int k=0; k<2; k++){
        check[k]=new bool*[height];
        for(int l=0; l<height; l++){
            check[k][l]=new bool[width];
            memset(check[k][l], 0, sizeof(check[k][l]));
        }
    }
    int di[]={-1, 0, 1, 0};
    int dj[]={0, 1, 0, -1};
    queue<pair<int, int>> q;
    queue<int> dist;
    queue<bool> can;
    q.push(make_pair(i, j));
    dist.push(distance);
    can.push(destroy);
    check[1][i][j]=1; // check[1].... 아직 벽을 안뽀갬, check[0].... 벽을 뽀갬
    while(!q.empty()){
        i=q.front().first;
        j=q.front().second;
        distance=dist.front();
        destroy=can.front();
        q.pop();
        dist.pop();
        can.pop();
        if(i==height-1 && j==width-1){
            return distance;
        }
        for(int k=0; k<4; k++){
            int ni=i+di[k];
            int nj=j+dj[k];
            if(0<=ni && 0<=nj && ni<height && nj<width){
                if(destroy){
                    if(map[ni][nj]==0){ //이동가능할경우
                        if(check[1][ni][nj]==false){
                            q.push(make_pair(ni, nj));
                            dist.push(distance+1);
                            can.push(true);
                            check[1][ni][nj]=true;
                        }
                    }else{ //벽뽀개고갈경우
                        if(check[0][ni][nj]==false){
                            q.push(make_pair(ni, nj));
                            dist.push(distance+1);
                            can.push(false);
                            check[0][ni][nj]=true;
                        }
                    }
                }else{//더이상벽을뽀갤수없당
                    if(map[ni][nj]==0) { //이동가능할경우
                        if (check[0][ni][nj] == false) {
                            q.push(make_pair(ni, nj));
                            dist.push(distance + 1);
                            can.push(false);
                            check[0][ni][nj] = true;
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main(void){
    int height, width;
    scanf("%d %d", &height, &width);
    int** map=new int*[height];
    char* str=new char[width+1];
    for(int i=0; i<height; i++){
        map[i]=new int[width];
        scanf("%s", str);
        for(int j=0; j<width; j++){
            map[i][j]=str[j]-'0';
        }
    }
    delete[] str;
    int result=bfs(map, height, width);
    printf("%d", result);
    for(int i=0; i<height; i++){
        delete[] map[i];
    }
    delete[] map;
    return 0;
}