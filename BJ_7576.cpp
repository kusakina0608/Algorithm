//
// Created by Kina on 2020/02/19.
//
#include <iostream>
#include <queue>
using namespace std;

void ShowBox(int**box, int height, int width){
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            printf("%2d ", box[i][j]);
        }
        printf("\n");
    }
}

int bfs(int** box, queue<pair<int, int>> q, queue<int> day, int height, int width){
    int i, j, d;
    int di[]={1, 0, -1, 0};
    int dj[]={0, 1, 0, -1};
    while(!q.empty()){
        i=q.front().first;
        j=q.front().second;
        d=day.front();
        q.pop();
        day.pop();
        //printf("\nday %d\n", d);
        //ShowBox(box, height, width);
        for(int k=0; k<4; k++){
            int ni=i+di[k];
            int nj=j+dj[k];
            if(0<=ni && 0<=nj && ni<height && nj<width){
                if(box[ni][nj]==0){
                    q.push(make_pair(ni, nj));
                    day.push(d+1);
                    box[ni][nj]=1;
                }
            }
        }
    }
    return d;
}

bool CheckBox(int** box, int height, int width){
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            if(box[i][j]==0) return false;
        }
    }
    return true;
}

int main(void){
    int height, width;
    queue<pair<int, int>> tomato;
    queue<int> day;
    scanf("%d %d", &width, &height);
    int** box=new int*[height];
    for(int i=0; i<height; i++){
        box[i]=new int[width];
        for(int j=0; j<width; j++){
            scanf("%d", &box[i][j]);
            if(box[i][j]==1){
                tomato.push(make_pair(i, j));
                day.push(0);
            }
        }
    }
    int result=bfs(box, tomato, day, height, width);
    printf("%d", CheckBox(box, height, width)?result:-1);
    for(int i=0; i<height; i++){
        delete[] box[i];
    }
    delete[] box;
    return 0;
}