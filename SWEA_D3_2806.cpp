//
// Created by Kina on 2020/02/01.
#include <iostream>
using namespace std;

class Chess{
private:
    int board[10][10];
    int boardSize;
    int numOfCase;
public:
    Chess(const int &boardSize)
            : boardSize(boardSize), numOfCase(0) {
        for(int i=0; i<10; i++){
            fill_n(board[i], 10, 0);
        }
    }
private:
    void CheckBoard(int i, int j){
        for(int k=0; k<boardSize; k++){
            board[i][k]++;
            board[k][j]++;
        }
        int min = i<j?i:j;
        for(int k=-min; (i+k<boardSize) && (j+k<boardSize); k++){
            board[i+k][j+k]++;
        }
        min = ((boardSize-1)-i)<=j?((boardSize-1)-i):j;
        for(int k=-min; (i-k>=0) && (j+k<boardSize); k++){
            board[i-k][j+k]++;
        }
    }
    void UncheckBoard(int i, int j){
        for(int k=0; k<boardSize; k++){
            board[i][k]--;
            board[k][j]--;
        }
        int min = i<j?i:j;
        for(int k=-min; (i+k<boardSize) && (j+k<boardSize); k++){
            board[i+k][j+k]--;
        }
        min = ((boardSize-1)-i)<=j?((boardSize-1)-i):j;
        for(int k=-min; (i-k>=0) && (j+k<boardSize); k++){
            board[i-k][j+k]--;
        }
    }
public:
    void CalcNCase(int start_i, int start_j, int nQueen){
        int sj = start_j;
        if(nQueen==boardSize){
            numOfCase++;
            UncheckBoard(start_i, start_j);
            return;
        }
        if(nQueen<start_i) return;
        for(int i=start_i; i<boardSize; i++){
            for(int j=sj; j<boardSize; j++){
                if(i>nQueen) {
                    UncheckBoard(start_i, start_j);
                    return;
                }
                if(board[i][j]==0) {
                    this->CheckBoard(i, j);
                    this->CalcNCase(i, j, nQueen + 1);
                }
            }
            sj=0;
        }
        UncheckBoard(start_i, start_j);
        return;
    }
    int getNumOfCase() const {
        return numOfCase;
    }
};

int main(int argc, char** argv)
{
    int test_case;
    int T;

    scanf("%d", &T);
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n=0;
        int result = 0;
        scanf("%d", &n);
        Chess chess(n);
        chess.CalcNCase(0,0,0);
        printf("#%d %d\n", test_case, chess.getNumOfCase());
    }
    return 0;
}