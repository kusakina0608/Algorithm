//
// Created by Kina on 2020/07/16.
//
#include <iostream>

using namespace std;

int T, test_case, H, W;
int** src, ** dst;

int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void copy_fields(){
    for(int h=0; h<H; h++){
        for(int w=0; w<W; w++){
            dst[h][w] = src[h][w];
        }
    }
}

bool is_valid(int h, int w){
    return 0<=h && h<H && 0<=w && w<W;
}

int check_boundary(int y, int x){ // count # of empty grid
    int cnt = 0;
    for(int i=0; i<8; i++){
        int newy = y+dy[i];
        int newx = x+dx[i];
        if(is_valid(newy, newx)){ // if true => valid position
            if(src[newy][newx]==0){
                cnt++;
            }
        }
    }
    return cnt;
}

bool is_different(){
    for(int h=0; h<H; h++){
        for(int w=0; w<W; w++){
            if(dst[h][w] != src[h][w])
                return true;
        }
    }
    return false;
}

void big_wave(){
    copy_fields();
    for(int h=0; h<H; h++) {
        for (int w=0; w<W; w++) {
            if(0<src[h][w] && src[h][w]<9 && src[h][w]<=check_boundary(h, w)){
                dst[h][w]=0;
            }
        }
    }
}

int main(void){
    cin>>T;
    for(int test_case=1; test_case<=T; test_case++){
        cin>>H>>W;
        src = new int*[H];
        dst = new int*[H];
        for(int h=0; h<H; h++){
            src[h] = new int[W];
            dst[h] = new int[W];
            for(int w=0; w<W; w++){
                char c;
                cin>>c;
                if(c=='.') src[h][w] = 0;
                else src[h][w] = c-'0';
            }
        }
        // implement
        int cnt = -1;
        while(is_different()){
            big_wave();
            cnt++;
            int** tmp = src;
            src = dst;
            dst = tmp;
        }
        cout<<'#'<<test_case<<' '<<cnt<<'\n';
        // end
    }
}