//
// Created by Kina on 2020/02/09.
//
#include <iostream>
using namespace std;

int main(void){
    char str[1000001];
    cin.getline(str,1000001);
    int count=0;
    bool flag=false;
    if(str[0]==' '){
        flag=false;
        count=0;
    }else{
        flag=true;
    }
    for(int i=1; str[i]!='\0'; i++){
        if(flag==true && str[i]==' '){
            flag=false;
            count++;
        }else{
            flag=true;
        }
    }
    if(flag==true)
        count++;
    cout<<count;
}