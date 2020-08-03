// TODO Solve(BruteForce, BFS)
// Created by Kina on 2020/02/11.
//
#include <iostream>
using namespace std;

int map[8][8];
int copyMap[8][8];

void copyArr(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            copyMap[i][j]=map[i][j];
        }
    }
}

void SpreadVirus(int i, int j, int nrow, int ncol){
    if(copyMap[i][j]==2) {

        if (i - 1 >= 0 && copyMap[i - 1][j] == 0) {
            copyMap[i - 1][j] = 2;
            SpreadVirus(i - 1, j, nrow, ncol);
        }
        if (i + 1 < nrow && copyMap[i + 1][j] == 0) {
            copyMap[i + 1][j] = 2;
            SpreadVirus(i + 1, j, nrow, ncol);
        }
        if (j - 1 >= 0 && copyMap[i][j - 1] == 0) {
            copyMap[i][j - 1] = 2;
            SpreadVirus(i, j - 1, nrow, ncol);
        }
        if (j + 1 < ncol && copyMap[i][j + 1] == 0) {
            copyMap[i][j + 1] = 2;
            SpreadVirus(i, j + 1, nrow, ncol);
        }
    }
}

int main(void){
    int nrow, ncol;
    cin>>nrow>>ncol;
    for(int i=0; i<nrow; i++){
        for(int j=0; j<ncol; j++){
            cin>>map[i][j];
        }
    }
    int max=0;
    int len=nrow*ncol;
    for(int i=0; i<len; i++){
        if(map[i/ncol][i%ncol]!=0)
            continue;
        for(int j=i+1; j<len; j++){
            if(map[j/ncol][j%ncol]!=0)
                continue;
            for(int k=j+1; k<len; k++){
                if(map[k/ncol][k%ncol]!=0)
                    continue;
                copyArr();
                copyMap[i/ncol][i%ncol]=1;
                copyMap[j/ncol][j%ncol]=1;
                copyMap[k/ncol][k%ncol]=1;
                for(int l=0; l<len; l++){
                    SpreadVirus(l/ncol, l%ncol, nrow, ncol);
                }

                int count=0;
                for(int i=0; i<nrow; i++){
                    for(int j=0; j<ncol; j++){
                        if(copyMap[i][j]==0)
                            count++;
                    }
                }
                if(max<count){
                    max=count;
                }
            }
        }
    }
    cout<<max;
}