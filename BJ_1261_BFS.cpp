//
// Created by Kina on 2020/02/21.
//
#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
using namespace std;

int di[]={0, 0, -1, 1};
int dj[]={-1, 1, 0, 0};

int bfs(int** map, int height, int width){
    bool** check=new bool*[height];
    for(int i=0; i<height; i++){
        check[i]=new bool[width];
        memset(check[i], 0, sizeof(check[i]));
    }
    deque<pair<int, int>> dq;
    deque<int> qq;
    dq.push_back(make_pair(0, 0));
    qq.push_back(0);
    check[0][0]=true;
    while(!dq.empty()){
        int i=dq.front().first;
        int j=dq.front().second;
        int k=qq.front();
        dq.pop_front();
        qq.pop_front();
        if(i==height-1 && j==width-1){
            for(int l=0; l<height; l++){
                delete[] check[l];
            }
            delete[] check;
            return k;
        }
        for(int l=0; l<4; l++){
            int ni=i+di[l];
            int nj=j+dj[l];
            if(0<=ni && 0<=nj && ni<height && nj<width) {
                int nk=k+map[ni][nj];
                if(check[ni][nj]==false) {
                    if (map[ni][nj] == 0) {
                        dq.push_front(make_pair(ni, nj));
                        qq.push_front(nk);
                    } else {
                        dq.push_back(make_pair(ni, nj));
                        qq.push_back(nk);
                    }
                    check[ni][nj] = true;
                }
            }
        }
    }
}

int main(void){
    int height, width;
    scanf("%d %d", &width, &height);
    int** map=new int*[height];
    for(int i=0; i<height; i++){
        map[i]=new int[width];
        char* str=new char[width+1];
        scanf("%s", str);
        for(int j=0; j<width; j++){
            map[i][j]=str[j]-'0';
        }
    }
    int result=bfs(map, height, width);
    printf("%d", result);
    for(int i=0; i<height; i++){
        delete[] map[i];
    }
    delete[] map;
    return 0;
}