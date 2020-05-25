#include<iostream>

using namespace std;

class Jingi{
private:
    int boongUh;
    int time;
public:
    Jingi(int boong, int t){
        boongUh = boong;
        time = t;
    }
    int calcNBoong(int current_time){
        return ((current_time-(current_time%time))/time)* boongUh;
    }
    int getTime(){
        return time;
    }

};

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int numOfSonNom, time, boongUh;
        int* SonNom;
        cin >> numOfSonNom >> time >> boongUh;
        Jingi jingi(boongUh, time);
        SonNom = new int[numOfSonNom];
        for(int i=0; i<numOfSonNom; i++){
            scanf("%d", SonNom+i);
        }
        for(int i=0; i<numOfSonNom-1; i++){
            for(int j=0; j<numOfSonNom-i-1; j++){
                if(SonNom[j]>SonNom[j+1]){
                    SonNom[j] = SonNom[j] ^ SonNom[j+1];
                    SonNom[j+1] = SonNom[j] ^ SonNom[j+1];
                    SonNom[j] = SonNom[j] ^ SonNom[j+1];
                }
            }
        }
        int result = 0, i;
        bool flag = true;
        printf("#%d ", test_case);
        for(i=0; i<numOfSonNom; i++){
            result = jingi.calcNBoong(SonNom[i]);
            if(i+1>result){
                printf("Impossible\n");
                flag = false;
                break;
            }
        }
        if(flag){
            printf("Possible\n");
        }
    }
    return 0;
}