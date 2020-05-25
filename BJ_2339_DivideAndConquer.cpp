//
// Created by Kina on 2020/04/16.
//
#include <iostream>
#include <vector>

#define HORIZONTAL 1
#define VERTICAL 2

using namespace std;
int N;
int Board[32][32];

int go(int y1, int x1, int y2, int x2, int direction){
    vector<pair<int, int>> v;
    int cnt = 0;
    for(int i = y1; i < y2; i++){
        for(int j = x1; j < x2; j++){
            if(Board[i][j] == 1)
                v.push_back({i, j});
            else if(Board[i][j] == 2)
                cnt++;
        }
    }

    if(cnt == 0) return 0;
    if(cnt == 1) return v.size() == 0;
    if(v.size() == 0) return 0;

    int ret = 0;
    if(direction != HORIZONTAL){
        for(pair<int, int> Impurity : v){
            int _y = Impurity.first;
            int _x = Impurity.second;
            bool flag = 0;
            for(int j = x1; j < x2; j++)
                if(Board[_y][j] == 2)
                    flag = 1;
            if(!flag)
                ret += go(y1, x1, _y, x2, 1) * go(_y + 1, x1, y2, x2, 1);
        }
    }
    if(direction != VERTICAL){
        for(pair<int, int> Impurity : v){
            int _y = Impurity.first;
            int _x = Impurity.second;
            bool flag = 0;
            for(int j = y1; j < y2; j++)
                if(Board[j][_x] == 2)
                    flag = 1;
            if(!flag)
                ret += go(y1, x1, y2, _x, 2) * go(y1, _x + 1, y2, x2, 2);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i <N; i++)
        for(int j = 0; j < N; j++)
            cin >> Board[i][j];
    int ret = go(0, 0, N, N, 0);
    cout << (ret == 0 ? -1 : ret) << "\n";
    return 0;
}