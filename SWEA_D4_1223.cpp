//
// Created by Kina on 2020/02/02.
//
#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    for(test_case = 1; test_case <= 10; ++test_case)
    {
        int len=0, result=0;
        char *infix=NULL, *postfix=NULL;
        stack<char> char_stack;

        cin>>len;
        infix=new char[len+1];
        postfix=new char[len+1];
        cin>>infix;

        int index=0;
        for(int i=0; i<len; i++){
            switch(infix[i]){
                case '+':
                    while(!char_stack.empty()) {
                        postfix[index++] = char_stack.top();
                        char_stack.pop();
                    }
                    char_stack.push(infix[i]);
                    break;
                case '*':
                    while(!char_stack.empty() && char_stack.top()=='*') {
                        postfix[index++] = char_stack.top();
                        char_stack.pop();
                    }
                    char_stack.push(infix[i]);
                    break;
                default:
                    postfix[index++]=infix[i];
            }
        }
        while(!char_stack.empty()) {
            postfix[index++] = char_stack.top();
            char_stack.pop();
        }

        stack<int> int_stack;
        for(int i=0; i<len; i++){
            if(isdigit(postfix[i])){
                int_stack.push(postfix[i]-'0');
            }
            else{
                int a=int_stack.top();
                int_stack.pop();
                int b=int_stack.top();
                int_stack.pop();
                switch(postfix[i]){
                    case '+':
                        int_stack.push(a+b);
                        break;
                    case '*':
                        int_stack.push(a*b);
                        break;
                }
            }
        }
        result=int_stack.top();
        cout<<'#'<<test_case<<' '<<result<<endl;
        delete[] infix;
        delete[] postfix;
    }
    return 0;
}
