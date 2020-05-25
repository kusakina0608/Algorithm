//
// Created by Kina on 2020/02/08.
//
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main(void){
    stack<char> s;
    int size;
    char str[100001];
    bool bracket_flag=false;
    cin.getline(str,100001);
    size=strlen(str);
    for(int i=0; i<size; i++){
        if(!bracket_flag && str[i]==' '){
            while (!s.empty()) {
                cout << s.top();
                s.pop();
            }
        }
        if(!bracket_flag && str[i]=='<') {
            while (!s.empty()) {
                cout << s.top();
                s.pop();
            }
            bracket_flag = true;
        }
        if(bracket_flag || str[i]==' ')
            printf("%c",str[i]);
        else {
            s.push(str[i]);
        }
        if(str[i]=='>')
            bracket_flag=false;
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    return 0;
}