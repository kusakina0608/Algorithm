//
// Created by Kina on 2020/05/25.
//
#include <stdio.h>
#include <string.h>

int main(void)
{
    int test_case;
    int T;
    int arr[100];
    int len1=0, len2=0;
    char str1[20], str2[20];
    for(int i=0; i<100; i++)
        arr[i]=0;
    arr[(int)'C']=1;
    arr[(int)'E']=1;
    arr[(int)'F']=1;
    arr[(int)'G']=1;
    arr[(int)'H']=1;
    arr[(int)'I']=1;
    arr[(int)'J']=1;
    arr[(int)'K']=1;
    arr[(int)'L']=1;
    arr[(int)'M']=1;
    arr[(int)'N']=1;
    arr[(int)'S']=1;
    arr[(int)'T']=1;
    arr[(int)'U']=1;
    arr[(int)'V']=1;
    arr[(int)'W']=1;
    arr[(int)'X']=1;
    arr[(int)'Y']=1;
    arr[(int)'Z']=1;
    arr[(int)'A']=2;
    arr[(int)'D']=2;
    arr[(int)'O']=2;
    arr[(int)'P']=2;
    arr[(int)'Q']=2;
    arr[(int)'R']=2;
    arr[(int)'B']=3;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%s %s", str1, str2);
        len1=strlen(str1);
        len2=strlen(str2);
        int flag=1;
        if(len1!=len2) flag=0;
        for(int i=0; i<len1 && flag; i++){
            if(arr[(int)str1[i]]!=arr[(int)str2[i]])
                flag=0;
        }
        if(flag){
            printf("#%d SAME\n", test_case);
        }else{
            printf("#%d DIFF\n", test_case);
        }
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}