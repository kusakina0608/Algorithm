//
// Created by Kina on 2020/07/19.
//
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve){
    int answer = n;
    int* stu = new int[n];
    memset(stu, 0, sizeof(int)*n);
    for(int i=0; i<lost.size(); i++){
        stu[lost[i]-1]--;
    }
    for(int i=0; i<reserve.size(); i++){
        stu[reserve[i]-1]++;
    }
    for(int i=0; i<n; i++){
        if(stu[i]<0){
            if(i!=0 && stu[i-1]>0){
                stu[i-1]--;
                stu[i]++;
            }else if(i!=n-1 && stu[i+1]>0){
                stu[i+1]--;
                stu[i]++;
            }
            else{
                answer--;
            }
        }
    }
    return answer;
}