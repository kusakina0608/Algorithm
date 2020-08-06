//
// Created by Kina on 2020/07/07.
//
#include <iostream>

using namespace std;

int T;
int cnt;
bool flag[10];
bool error = false;
int sudoku[9][9];
int di[] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
int dj[] = {0, 3, 6, 0, 3, 6, 0, 3, 6};
void reset(){
    flag[0] = false;
    flag[1] = false;
    flag[2] = false;
    flag[3] = false;
    flag[4] = false;
    flag[5] = false;
    flag[6] = false;
    flag[7] = false;
    flag[8] = false;
    flag[9] = false;
}
int main(void){
    cin>>T;
    for(int t=1; t<=T; t++){
        error = false;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cin>>sudoku[i][j];
            }
        }
        // horizontal
        for(int i=0; !error && i<9; i++){
            reset();
            for (int j=0; !error && j<9; j++){
                int num = sudoku[i][j];
                if(flag[num]) { error = true; break; }
                flag[num] = true;
            }
        }
        // vertical
        for(int j=0; !error && j<9; j++){
            reset();
            for(int i=0; !error && i<9; i++){
                int num = sudoku[i][j];
                if(flag[num]) { error = true; break; }
                flag[num] = true;
            }
        }
        // section
        for(int k=0; !error && k<9; k++){
            reset();
            for(int i=0; !error && i<3; i++){
                for(int j=0; !error && j<3; j++){
                    int num = sudoku[i+di[k]][j+dj[k]];
                    if(flag[num]) { error = true; break; }
                    flag[num] = true;
                }
            }
        }
        cout<<'#'<<t<<' ';
        if(error) cout<<0;
        else cout<<1;
        cout<<'\n';
    }
    return 0;
}