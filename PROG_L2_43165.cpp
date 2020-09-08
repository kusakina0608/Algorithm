//
// Created by Kina on 20. 9. 8..
//
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int calc(vector<int> numbers, int target, int idx, int sum){
    if(idx==numbers.size()){
        if(sum==target)
            return 1;
        else
            return 0;
    }
    int count = 0;
    count += calc(numbers, target, idx+1, sum+numbers[idx]);
    count += calc(numbers, target, idx+1, sum-numbers[idx]);
    return count;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer += calc(numbers, target, 1, numbers[0]);
    answer += calc(numbers, target, 1, -numbers[0]);
    return answer;
}