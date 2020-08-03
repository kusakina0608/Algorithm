//
// Created by Kina on 2020/02/13.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> calc(vector<int>& a, int index, int cur, int plus, int minus, int mul, int div){
    int n=a.size();
    if(index==n){
        return make_pair(cur,cur);
    }
    vector<pair<int,int>> res;
    if(plus>0){
        res.push_back(calc(a, index+1, cur+a[index], plus-1, minus, mul, div));
    }
    if(minus>0){
        res.push_back(calc(a, index+1, cur-a[index], plus, minus-1, mul, div));
    }
    if(mul>0){
        res.push_back(calc(a, index+1, cur*a[index], plus, minus, mul-1, div));
    }
    if(div>0){
        res.push_back(calc(a, index+1, cur/a[index], plus, minus, mul, div-1));
    }
    auto ans = res[0];
    for(auto p : res){
        if(ans.first<p.first){
            ans.first=p.first;
        }
        if(ans.second>p.second){
            ans.second=p.second;
        }
    }
    return ans;
}

int main(void) {
    int num;
    cin >> num;
    vector<int> operand(num);
    for(int i=0; i<num; i++){
        cin>>operand[i];
    }
    int N_operator[4]={0, 0, 0, 0};
    for(int i=0; i<4; i++){
        cin >> N_operator[i];
    }
    auto p = calc(operand, 1, operand[0], N_operator[0], N_operator[1], N_operator[2], N_operator[3]);
    cout<<p.first<<endl<<p.second;
    return 0;
}