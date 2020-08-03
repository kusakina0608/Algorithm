//
// Created by Kina on 2020/02/13.
//
#include <iostream>
using namespace std;

int main(void){
    int set=0;
    int index;
    int num;
    scanf("%d", &num);
    char command[10];
    for(int i=0; i<num; i++){
        scanf("%s", command);
        switch(command[1]){
            case 'd':
                scanf("%d", &index);
                set = set|(1<<index);
                break;
            case 'e':
                scanf("%d", &index);
                set = set&~(1<<index);
                break;
            case 'h':
                scanf("%d", &index);
                printf("%d\n", (int)((set>>index)&1));
                break;
            case 'o':
                scanf("%d", &index);
                set=set^(1<<index);
                break;
            case 'l':
                set=-1;
                break;
            case 'm':
                set=0;
                break;
        }
    }
    return 0;
}