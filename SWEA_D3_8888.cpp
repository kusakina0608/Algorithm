//
// Created by Kina on 2020/02/12.
//
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;

    scanf("%d",&T);
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N, N_Prob, target;
        cin>>N>>N_Prob>>target;
        //scanf("%d %d %d", &N, &N_Prob, &target);
        int** TestResult=new int*[N+1];
        int* NScore=new int[N+1];
        int* NSuccess=new int[N+1];
        int* ProbScore=new int[N_Prob];
        for(int i=0; i<N_Prob; i++){
            ProbScore[i]=0;
        }
        int val = '7'-7;
        for(int i=1; i<=N; i++){
            NSuccess[i]=0;
            NScore[i]=0;
            TestResult[i]=new int[N_Prob];
            for(int j=0; j<N_Prob; j++){
                getchar();
                TestResult[i][j]=getchar()-val;
                if(TestResult[i][j]==0){
                    ProbScore[j]++;
                }else{
                    NSuccess[i]++;
                }
            }
        }
        for(int i=1; i<=N; i++){
            for(int j=0; j<N_Prob; j++){
                NScore[i]+=TestResult[i][j]*ProbScore[j];
            }
        }
        int rank=0;
        for(int i=1; i<=N; i++){
            if(NScore[i]>NScore[target]){
                rank++;
            }else if(NScore[i]==NScore[target]){
                if(NSuccess[i]>NSuccess[target]){
                    rank++;
                }else if(NSuccess[i]==NSuccess[target]){
                    if(i<=target){
                        rank++;
                    }
                }
            }
        }
        cout<<'#'<<test_case<<' '<<NScore[target]<<' '<<rank<<endl;
        delete[] ProbScore;
        delete[] NSuccess;
        delete[] NScore;
        for(int i=1; i<=N; i++){
            delete[] TestResult[i];
        }
        delete[] TestResult;
    }
    return 0;
}