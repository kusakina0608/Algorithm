//
// Created by Kina on 2020/02/07.
//
#include <iostream>
using namespace std;

int main(void){
    char str[200];
    cin>>str;
    int count=0;
    int i=0;
    while(str[i]!='\0'){
        switch(str[i]){
            case 'c':
                if(str[i+1]=='=' || str[i+1]=='-'){
                    i+=2;
                    count++;
                }else{
                    i++;
                    count++;
                }
                break;
            case 'd':
                if(str[i+1]=='z' && str[i+2]=='='){
                    i+=3;
                    count++;
                }else if(str[i+1]=='-'){
                    i+=2;
                    count++;
                }else{
                    i++;
                    count++;
                }
                break;
            case 'l':
                if(str[i+1]=='j'){
                    i+=2;
                    count++;
                }else{
                    i++;
                    count++;
                }
                break;
            case 'n':
                if(str[i+1]=='j'){
                    i+=2;
                    count++;
                }else{
                    i++;
                    count++;
                }
                break;
            case 's':
                if(str[i+1]=='='){
                    i+=2;
                    count++;
                }else{
                    i++;
                    count++;
                }
                break;
            case 'z':
                if(str[i+1]=='='){
                    i+=2;
                    count++;
                }else{
                    i++;
                    count++;
                }
                break;
            default:
                i++;
                count++;
        }
    }
    printf("%d", count);
}