//
// Created by Kina on 2020/02/02.
//
#include <stdio.h>
#include <stdlib.h>

void calcMinGate(char* gateInfo){

}

int main(void)
{
    int test_case;
    int T;
    int nCity;
    int moveDistLim;
    char* gateInfo;

    setbuf(stdout, NULL);
    scanf("%d", &T);


    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d %d", &nCity, &moveDistLim);
        gateInfo = (char*)malloc(sizeof(char)*(nCity));
        int val;
        for(int i=0; i<nCity; i++){
            scanf("%d", &val);
            gateInfo[i] = (char)val;
        }
        int nGate=0;
        int count=0;
        for(int i=0; i<nCity; i++){
            if(gateInfo[i]==0){
                count++;
            }else{
                count=0;
            }
            if(count==moveDistLim) {
                nGate++;
                count=0;
            }
        }
        printf("#%d %d\n", test_case, nGate);
    }
    return 0;
}