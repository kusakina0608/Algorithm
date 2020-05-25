//
// Created by Kina on 2020/02/02.
//
#include<iostream>
using namespace std;

class Stack{
private:
    char* stack;
    int top;
public:
    Stack(int n)
            : top(-1) {
        stack = new char[n];
    }
    void push(const char &c){
        stack[++top]=c;
    }
    char pop(){
        return stack[top--];
    }
    ~Stack(){
        delete[] stack;
    }
};

bool CheckBracket(char l_bra, char r_bra){
    bool ret = false;
    switch(l_bra){
        case '(':
            if(r_bra==')') ret=true; break;
        case '[':
            if(r_bra==']') ret=true; break;
        case '{':
            if(r_bra=='}') ret=true; break;
        case '<':
            if(r_bra=='>') ret=true; break;
    }
    return ret;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    int len;
    char bracket;

    for(test_case = 1; test_case <= 10; ++test_case)
    {
        cin>>len;
        Stack stack(len);
        char c;

        bool valid = true;
        for(int i=0; i<len; i++){
            scanf(" %c", &bracket);
            if(valid) {
                switch (bracket) {
                    case '(':
                    case '[':
                    case '{':
                    case '<':
                        stack.push(bracket);
                        break;
                    case ')':
                    case ']':
                    case '}':
                    case '>':
                        c = stack.pop();
                        valid = CheckBracket(c, bracket);
                        break;
                }
            }//end if
        }//end for
        cout<<'#'<<test_case<<' '<<valid<<endl;
    }
    return 0;
}