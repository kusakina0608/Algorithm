//
// Created by Kina on 2020/07/16.
//
#include <iostream>
#include <queue>

using namespace std;

char tmp_char;
int T, N_ROW, N_COL, cnt, result;
int** MAP;

int di[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dj[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool kangaroo(int i, int j){
    return 0<=i && i<N_ROW && 0<=j && j<N_COL;
}

int main(void){
    cin>>T;
    queue<pair<int, int>> sand;

    for(int tc=1; tc<=T; tc++){
        result = 0;
        cin>>N_ROW>>N_COL;
        MAP = new int*[N_ROW];
        for(int row=0; row<N_ROW; row++){
            MAP[row] = new int[N_COL];
            for(int col=0; col<N_COL; col++){
                cin>>tmp_char;
                if(tmp_char=='.'){
                    MAP[row][col] = 0;
                }else{
                    MAP[row][col] = tmp_char-'0';
                }
                if(0<=MAP[row][col] && MAP[row][col]<9){
                    sand.push(make_pair(row, col));
                }
            }
        }
        while(true){
            queue<pair<int, int>> alive;
            queue<pair<int, int>> remove;
            while(!sand.empty()) {
                pair<int, int> point = sand.front();
                int curi = point.first;
                int curj = point.second;
                sand.pop();
                cnt = 0;
                for (int i = 0; i < 8; i++) {
                    int newi = curi + di[i];
                    int newj = curj + dj[i];
                    if (kangaroo(newi, newj) && MAP[newi][newj] == 0) {
                        cnt++;
                    }
                }
                if(MAP[curi][curj]<=cnt){
                    remove.push(point);
                }else{
                    alive.push(point);
                }
            }
            sand = alive;
            if(remove.empty()) break;
            while(!remove.empty()){
                pair<int, int> point = remove.front();
                MAP[point.first][point.second] = 0;
                remove.pop();
            }
            result ++;
        }
        cout<<"#"<<tc<<' '<<result<<'\n';
    }
}