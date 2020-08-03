//
// Created by Kina on 2020/02/13.
//
#include <iostream>
using namespace std;

void ShowData(bool* Narr, int* Marr, const int& N, const int& M, int count){
    if(count==M){
        for(int i=0; i<M; i++){
            printf("%d ", Marr[i]);
        }
        putchar('\n');
        return;
    }
    for(int i=1; i<=N; i++){
        if(!Narr[i]) {
            Narr[i] = true;
            Marr[count] = i;
            ShowData(Narr, Marr, N, M, count + 1);
            Narr[i] = false;
        }
    }

}

int main(void){
    int N, M;
    bool Narr[9]={false, false, false, false, false, false, false, false, false};
    int Marr[8]={0, };
    scanf("%d %d", &N, &M);
    ShowData(Narr, Marr, N, M, 0);
    return 0;
}