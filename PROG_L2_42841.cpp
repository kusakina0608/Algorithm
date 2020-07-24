//
// Created by Kina on 2020/07/17.
//
#include <string>
#include <vector>

using namespace std;

bool INIT = false;
int total = 0;
int nums[] = {1,2,3,4,5,6,7,8,9};
vector<int> combi;

void dfs(int cur, int idx){
    if(cur>99){
        combi.push_back(cur);
        return;
    }
    dfs(cur*10+nums[idx], idx+1);
    dfs(cur, idx+1);
}

void init_combi(){
    if(INIT) return;
    dfs(0, 0);
    total = combi.size();
}

bool check_strike(string a, string b){

}

bool check_ball(string a, string b){

}

int solution(vector<vector<int>> baseball) {
    init_combi();
    int answer = 0;
    vector<vector<int>>::iterator iter;
    for(iter = baseball.begin(); iter!= baseball.end(); iter++){
        string num = to_string((*iter)[0]);
        int strike = (*iter)[1];
        int ball = (*iter)[2];
        int s = 0, b = 0;
        for(int i=0; i<total; i++){
            string str = to_string(combi[i]);
            if(check_strike(num, str) && check_ball(num, str))
        }
    }
    return answer;
}

