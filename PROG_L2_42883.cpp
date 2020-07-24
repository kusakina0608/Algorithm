//
// Created by Kina on 2020/07/19.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    answer = number.substr(k);
    for(int i=k-1;i>=0;i--){
        int j=0;
        do{
            if(number[i] >= answer[j]){
                char temp = answer[j];
                answer[j] = number[i];
                number[i] = temp;
                j++;
            }else{
                break;
            }
        }while(1);
    }
    return answer;
}
//string solution(string number, int k) {
//    for(int j=0; j<k; j++) {
//        auto iter = number.begin();
//        for(; iter!=number.end(); iter++){
//            if (*iter<*(iter+1)) {
//                number.erase(iter);
//                break;
//            }
//            if(iter + 1 == number.end()){
//                number.erase(iter);
//                break;
//            }
//        }
//
//    }
//    return number;
//}
int main(void){
    cout<<solution("9876541", 3);

    return 0;
}
