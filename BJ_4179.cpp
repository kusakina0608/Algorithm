//
// Created by LKina on 2020-02-25.
//
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool checktime[1000];

int di[]={0, 0, 1, -1};
int dj[]={1, -1, 0, 0};

void checkFire(int** map,  int nrow, int ncol, int f){
    for(int i=0; i<nrow; i++){
        for(int j=0; j<ncol; j++){
            if(map[i][j]==f) {
                for (int k=0; k<4; k++) {
                    int ni=i+di[k];
                    int nj=j+dj[k];
                    if(0<=ni && 0<=nj && ni<nrow && nj<ncol){
                        if(map[ni][nj]==0) {
                            map[ni][nj]=map[i][j]+1;
                        }
                    }
                }
            }
        }
    }
}
void ShowMap(int** map, int nrow, int ncol){
    for(int i=0; i<nrow; i++) {
        for (int j=0; j<ncol; j++) {
            printf("%2d ", map[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    int nrow, ncol;
    char c;
    cin>>nrow>>ncol;
    queue<pair<int, int>> q;
    queue<int> time;
    time.push(1);
    int** map=new int*[nrow];
    bool** check=new bool*[nrow];
    for(int i=0; i<nrow; i++){
        map[i]=new int[ncol];
        check[i]=new bool[ncol];
        memset(check[i], 0, sizeof(check[i]));
        for(int j=0; j<ncol; j++){
            scanf(" %c", &c);
            switch(c){
                case '#':
                    map[i][j]=-1;
                    break;
                case '.':
                    map[i][j]=0;
                    break;
                case 'F':
                    map[i][j]=1;
                    break;
                case 'J':
                    map[i][j]=0;
                    q.push(make_pair(i, j));
                    check[i][j]=true;
            }
        }
    }
    int i, j, t;
    bool result=false;
    while(!q.empty()){
        i=q.front().first;
        j=q.front().second;
        t=time.front();
        if(i==0 || j==0 || i==nrow-1 || j==ncol-1) {
            result=true;
            break;
        }
        q.pop();
        time.pop();
        if(!checktime[t]) {
            checkFire(map, nrow, ncol, t);
            checktime[t]=true;
        }
        for(int k=0; k<4; k++){
            int ni=i+di[k];
            int nj=j+dj[k];
            if(0<=ni && 0<=nj && ni<nrow && nj<ncol){
                if(map[ni][nj]==0 && check[ni][nj]==false){
                    q.push(make_pair(ni, nj));
                    check[ni][nj]=true;
                    time.push(t+1);
                }
            }
        }
    }
    if(result)
        printf("%d\n", t);
    else
        printf("IMPOSSIBLE\n");
//    for(int i=0; i<nrow; i++){
//        delete[] check[i];
//        delete[] map[i];
//    }
//    delete[] check;
//    delete[] map;
    return 0;
}