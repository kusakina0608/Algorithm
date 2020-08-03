//
// Created by Kina on 2020/02/12.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> lotto(6);

void MakeLotto(vector<int> nums, int index, int count){
    if(count==6){
        for(int i=0; i<6; i++){
            cout<<lotto[i]<<' ';
        }
        cout<<endl;
        return;
    }
    if(index>=nums.size()) return;
    lotto[count]=nums[index];
    MakeLotto(nums, index+1, count+1);
    MakeLotto(nums, index+1, count);
}

int main(void){
    int n;
    cin>>n;
    while(n){
        vector<int> nums(n);
        for(int i=0; i<n; i++){
            cin>>nums[i];
        }
        MakeLotto(nums, 0, 0);
        cout<<endl;
        cin>>n;
    }
}
