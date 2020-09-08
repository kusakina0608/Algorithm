//
// Created by Kina on 2020/08/07.
//
#include<iostream>
using namespace std;

int T, test_case, N, top;
int matrix[100][100];
bool visit[100][100];
int k_stack[100][2];

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

void k_init_globals();
void k_get_input();
bool k_can_go(int, int);
bool k_left_top(int, int);
void k_brute_force();
void k_swap_stack_element(int, int);
void k_sort_stack();
void k_print_result();

int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        k_init_globals();
        k_get_input();
        k_brute_force();
        k_sort_stack();
        k_print_result();
    }
    return 0;
}

void k_init_globals(){
    top = -1;
}

void k_get_input(){
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>matrix[i][j];
        }
    }
}

bool k_can_go(int i, int j){
    return 0<=i && i<N && 0<=j && j<N;
}

bool k_left_top(int i, int j){
    int ni = i+di[0];
    int nj = j+dj[0];
    if(k_can_go(ni, nj) && matrix[ni][nj]!=0){
        return false;
    }
    ni = i+di[3];
    nj = j+dj[3];
    if(k_can_go(ni, nj) && matrix[ni][nj]!=0){
        return false;
    }
    return true;
}

void k_brute_force(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(matrix[i][j] != 0){
                if(!visit[i][j]){
                    if(k_left_top(i, j)){
                        int nrow=0;
                        int ncol=0;
                        int diff = 0;
                        while(i+diff<N && matrix[i+diff][j]!=0){
                            diff++;
                            nrow++;
                        }
                        diff = 0;
                        while(j+diff<N && matrix[i][j+diff]!=0){
                            diff++;
                            ncol++;
                        }
                        top++;
                        k_stack[top][0] = nrow;
                        k_stack[top][1] = ncol;
                    }
                }
            }
        }
    }
}

void k_swap_stack_element(int i, int j){
    k_stack[i][0] = k_stack[i][0]^k_stack[j][0];
    k_stack[j][0] = k_stack[i][0]^k_stack[j][0];
    k_stack[i][0] = k_stack[i][0]^k_stack[j][0];
    k_stack[i][1] = k_stack[i][1]^k_stack[j][1];
    k_stack[j][1] = k_stack[i][1]^k_stack[j][1];
    k_stack[i][1] = k_stack[i][1]^k_stack[j][1];
}

void k_sort_stack(){
    for(int i=top; i>0; i--){
        for(int j=0; j<i; j++){
            if(k_stack[j][0]*k_stack[j][1] > k_stack[j+1][0]*k_stack[j+1][1]) {
                k_swap_stack_element(j, j + 1);
            }
            else if(k_stack[j][0]*k_stack[j][1] == k_stack[j+1][0]*k_stack[j+1][1]){
                if(k_stack[j][0]>k_stack[j+1][0]){
                    k_swap_stack_element(j, j+1);
                }
            }
        }
    }
}

void k_print_result(){
    printf("#%d %d", test_case, top+1);
    for(int i=0; i<=top; i++){
        printf(" %d %d", k_stack[i][0], k_stack[i][1]);
    }
    printf("\n");
}