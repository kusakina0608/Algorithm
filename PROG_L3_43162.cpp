//
// Created by Kina on 20. 9. 8..
//
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int find(int* p, int x){
    if(p[x]==x)
        return x;
    else{
        int y = find(p, p[x]);
        p[x] = y;
        return p[x];
    }
}

void my_union(int* p, int x, int y){
    x = find(p, x);
    y = find(p, y);
    p[y] = x;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    int* p = new int[n];
    for(int i=0; i<n; i++){
        p[i]=i;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j && computers[i][j]==1){
                my_union(p, i, j);
            }
        }
    }

    for(int i=0; i<n; i++){
        if(p[i] == i)
            answer++;
    }
    return answer;
}