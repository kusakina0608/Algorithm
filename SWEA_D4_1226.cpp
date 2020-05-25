//
// Created by Kina on 2020/02/14.
//
#include<iostream>
using namespace std;

char maze[16][16];
bool visited[16][16];

bool go(int i, int j){
    if(i<0 || i>=16 || j<0 || j>=16) return false;
    if(maze[i][j]=='1') return false;
    if(maze[i][j]=='3') return true;
    //cout<<"go("<<i<<", "<<j<<")"<<endl;
    visited[i][j]=true;
    bool a=false, b=false, c=false, d=false;
    if(!visited[i-1][j]) a=go(i-1, j);
    if(!visited[i+1][j]) b=go(i+1, j);
    if(!visited[i][j-1]) c=go(i, j-1);
    if(!visited[i][j+1]) d=go(i, j+1);
    return a || b || c || d;
}

int main(int argc, char** argv)
{
    int test_case;
    for(test_case = 1; test_case <= 10; ++test_case)
    {
        int no;
        cin>>no;
        int start_i, start_j;
        for(int i=0; i<16; i++){
            for(int j=0; j<16; j++){
                visited[i][j]=false;
                cin>>maze[i][j];
                if(maze[i][j]=='2'){
                    start_i=i;
                    start_j=j;
                }
            }
        }
        cout<<'#'<<no<<' ';
        if(go(start_i, start_j)){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}