//
// Created by Kina on 2020/04/24.
//
#include <iostream>
#include <string.h>
#define MAX_UNIT 200000

using namespace std;

void showTable(int* coin, int** changes, int N, int max_change){
    printf("    ");
    for(int j=1; j<=max_change; j++)
        printf("%2d ", j);
    printf("\n");
    for(int i=0; i<N; i++){
        printf("%2d: ", coin[i]);
        for(int j=1; j<=max_change; j++){
            printf("%2d ", changes[i][j]);
        }
        printf("\n");
    }
}


int main(void){
    int N, max_change = 0;
    cin>>N;

    int* arr = new int[N];
    for(int i=N-1; i>=0; i--){
        cin>>arr[i];
    }
    max_change = 2*arr[0];

    //int** changes = new int*[N];
    int* change = new int[max_change+1];
    memset(change, 0, sizeof(change));
//    for(int i=0; i<N; i++){
//        changes[i] = new int[max_change+1];
//        memset(changes[i], 0, sizeof(changes[i]));
//    }
    for(int j=1; j<max_change+1; j++){
        //changes[N-1][j]=j;
        change[j] = j;
    }

    for(int i=N-2; i>=0; i--) {
        for (int j=1; j<=max_change; j++) {
            if(arr[i]<=j) {
                int totalCoins1 = change[j];
                int totalCoins2 = 1;
                int tmp = change[j - arr[i]];
                totalCoins2 += tmp;
                if(i<N-1 && totalCoins1>totalCoins2){
                    change[j] = totalCoins2;
                }
            }
        }
    }
    bool flag = false;
    for (int j=1; j<=max_change; j++){
        int tmp = j;
        int n_coin = 0;
        for(int i=0; i<N; i++){
            if(arr[i]<=tmp){
                n_coin += tmp/arr[i];
                tmp %= arr[i];
            }
        }
        //printf("i: %2d, j: %2d, 실제 잔돈: %2d, 그리디: %2d\n", i, j, changes[i][j], n_coin);
        if(n_coin != change[j]){
            flag = true;
            break;
        }
    }

    //showTable(arr, changes, N, max_change);

    if(flag) cout<<"No";
    else cout<<"Yes";
    return 0;
}
