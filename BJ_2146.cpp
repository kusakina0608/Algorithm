//
// Created by Kina on 2020/08/06.
//
#include <iostream>

using namespace std;

int N, color, answer;

int map[100][100];
bool visited[100][100];
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};


// boundary check
bool k_can_go(int i, int j);

// 0: ocean, -1: land
void k_get_input();

//
void k_clustering();
void k_make_cluster_recur(int, int);

void init_visit();

void k_breadth_first(int, int, int);
void solution();

void k_show_map(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
}

int main(void){
    k_get_input();
    k_clustering();
    //k_show_map();
    solution();
    cout<<answer;
    return 0;
}

bool k_can_go(int i, int j){
    return 0<=i && i<N && 0<=j && j<N;
}

void k_get_input(){
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
            if(map[i][j] == 1) map[i][j] = -1;
        }
    }
}

void k_clustering(){
    color = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] == -1) {
                k_make_cluster_recur(i, j);
                color++;
            }
        }
    }
}

void k_make_cluster_recur(int i, int j){
    map[i][j] = color;
    for(int k=0; k<4; k++){
        int ni = i+di[k];
        int nj = j+dj[k];
        if(k_can_go(ni, nj) && map[ni][nj]==-1){
            k_make_cluster_recur(ni, nj);
        }
    }
}

// k_queue[n][0]: row index of nth position
// k_queue[n][1]: column index of nth position
// k_queue[n][2]: length of bridge
int k_queue[10000][3];
int k_front, k_rear;

void init_visit(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            visited[i][j] = false;
        }
    }
}

void k_breadth_first(int i, int j, int cur_color){
    init_visit();
    k_front = 0;
    k_rear = 0;
    for(int k=0; k<4; k++){
        int ni = i + di[k];
        int nj = j + dj[k];
        if(k_can_go(ni, nj) && map[ni][nj] == 0){
            k_rear++;
            k_queue[k_rear][0] = ni;
            k_queue[k_rear][1] = nj;
            k_queue[k_rear][2] = 0;
        }
    }
    while(k_front!=k_rear){
        k_front++;
        k_front %= 10000;
        int ci = k_queue[k_front][0]; // current row index
        int cj = k_queue[k_front][1]; // current column index
        int cl = k_queue[k_front][2]; // current length
        if(!visited[ci][cj]){
            visited[ci][cj] = true;
            //cout<<"("<<ci<<", "<<cj<<") - length: "<<cl<<"\n";
            for(int k=0; k<4; k++){
                int ni = ci + di[k];
                int nj = cj + dj[k];
                int nl = cl + 1;
                if(nl<answer) {
                    if (k_can_go(ni, nj)) {
                        if (!visited[ni][nj]) {
                            if (map[ni][nj] == 0) {
                                k_rear++;
                                k_rear %= 10000;
                                k_queue[k_rear][0] = ni;
                                k_queue[k_rear][1] = nj;
                                k_queue[k_rear][2] = nl;
                                //cout<<"    ("<<ni<<", "<<nj<<") Added to queue. length: "<<nl<<"\n";
                            } else if (map[ni][nj] != cur_color) { // 탐색 성공
                                answer = nl;
                                //cout<<"탐색 성공("<<ni<<", "<<nj<<"): "<<nl<<'\n';
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
}

void solution(){
    answer = 2147483647;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int cur_color = map[i][j];
            if(cur_color > 0) {
                bool is_boundary = false;
                for (int k=0; k<4; k++) {
                    int ni=i+di[k];
                    int nj=j+dj[k];
                    if (k_can_go(ni, nj) && map[ni][nj] == 0){
                        is_boundary = true;
                    }
                }
                if(is_boundary) {
                    k_breadth_first(i, j, cur_color);
                }
            }
        }
    }
}