//
// Created by Kina on 2020/02/08.
//
#include <iostream>
using namespace std;

class Calculator{
private:
    int x, y;
public:
    Calculator(int x, int y) : x(x), y(y) { }
    void ShowResult(){
        cout<<x+y<<endl;
        cout<<x-y<<endl;
        cout<<x*y<<endl;
        cout<<x/y<<endl;
        cout<<x%y<<endl;
    }
};

int main(void){
    int a, b;
    cin>>a>>b;
    Calculator(a,b).ShowResult();
    return 0;
}