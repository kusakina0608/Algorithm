//
// Created by Kina on 2020/07/16.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    int len = numbers.size();
    int max_bit = pow(2, len);
    set<int> num_set;
    for(int bits=1; bits<max_bit; bits++){
        vector<int> num_vec;
        for(int i=0; i<len; i++){
            if((bits>>i)&1==1){ // Selected
                num_vec.push_back(numbers[i]-'0');
            }
        }
        int n_selected = num_vec.size();
        sort(num_vec.begin(), num_vec.end());
        do{
            int tmp = 0;
            for(int i=0; i<n_selected; i++){
                tmp += num_vec[i]*pow(10,i);
            }
            num_set.insert(tmp);
        }while(next_permutation(num_vec.begin(), num_vec.end()));
    }
    set<int>::iterator iter;
    for(iter = num_set.begin(); iter != num_set.end(); iter++){
        if(*iter<2) continue;
        int root = (int)sqrt(*iter);
        bool flag = true;
        for(int i=2; i<=root; i++){
            if((*iter)%i==0) {
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    }
    return answer;
}
int main(void){
    string s = "17";
    cout<<solution(s);
}