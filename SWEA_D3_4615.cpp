//
// Created by Kina on 2020/02/09.
//
#include <iostream>
#include <cstdlib>
#define __DEBUG__
using namespace std;

class Othello{
private:
    static int di[8];
    static int dj[8];
    int** board;
    int size;
public:
    Othello(const int board_size) : size(board_size) {
        if(!(board_size==4 || board_size==6 || board_size==8)) {
            cout<<"보드 크기가 이상한데요?"<<endl;
        }
        board = new int*[board_size];
        for(int i=0; i<board_size; i++){
            board[i]=new int[board_size];
            for(int j=0; j<board_size; j++){
                board[i][j]=0;
            }
        }
        board[board_size/2-1][board_size/2-1]=2;//white
        board[board_size/2  ][board_size/2  ]=2;//white
        board[board_size/2-1][board_size/2  ]=1;//black
        board[board_size/2  ][board_size/2-1]=1;//black
    }
    bool CheckValidPosition(int i, int j){
        if(i<0 || j<0 || i>=size || j>=size)
            return false;
        return true;
    }
    void TakeTurn(int pos_j, int pos_i, int color){
        int bitflag=0;
        board[pos_i-1][pos_j-1]=color;
        int enemy=color==1?2:1;
        for(int i=0; i<8; i++){
            if(CheckValidPosition(pos_i-1+di[i], pos_j-1+dj[i])){
                if(board[pos_i-1+di[i]][pos_j-1+dj[i]]==enemy){
                    bitflag = bitflag | (1<<i);
                }
            }
        }
        for(int i=0; i<8; i++){
            if((bitflag>>i)&1){
                int nChange=1;
                nChange++;
                while(CheckValidPosition(pos_i-1+(di[i]*(nChange)), pos_j-1+(dj[i]*(nChange)))
                      && board[pos_i-1+(di[i]*(nChange))][pos_j-1+(dj[i]*(nChange))]==enemy){
                    nChange++;
                }
                if(!CheckValidPosition(pos_i-1+(di[i]*(nChange)), pos_j-1+(dj[i]*(nChange)))){
                    //noChange
                }else if((board[pos_i-1+(di[i]*(nChange))][pos_j-1+(dj[i]*(nChange))]==color)){
                    while(--nChange){
                        board[pos_i-1+(di[i]*(nChange))][pos_j-1+(dj[i]*(nChange))]=color;
                    }
                }
            }
        }
    }
    /*void ShowStatus(void) const {
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                cout<<board[i][j]<<' ';
            }
            cout<<endl;
        }
    }*/
    void ShowResult(void) const {
        int num1=0, num2=0;
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if(board[i][j]==1)
                    num1++;
                if(board[i][j]==2)
                    num2++;
            }
        }
        cout<<num1<<' '<<num2;
    }
    ~Othello(){
        for(int i=0; i<size; i++){
            delete[] board[i];
        }
        delete[] board;
    }
};

int Othello::di[8]={-1, -1, 0, 1, 1, 1, 0, -1 };
int Othello::dj[8]={0, 1, 1, 1, 0, -1, -1, -1 };

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int size, nTurn, pos_i, pos_j, color;
        cin>>size>>nTurn;
        Othello othello(size);
        for(int i=0; i<nTurn; i++){
            cin>>pos_j>>pos_i>>color;
            othello.TakeTurn(pos_j, pos_i, color);
            //othello.ShowStatus();
        }
        cout<<'#'<<test_case<<' ';
        othello.ShowResult();
        cout<<endl;
    }
    return 0;
}