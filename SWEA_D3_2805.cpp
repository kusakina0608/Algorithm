//
// Created by Kina on 2020/02/08.
//
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin>>n;

        int** farm;
        farm=new int*[n];
        for(int i=0; i<n; i++)
            farm[i]=new int[n];

        char val;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>val;
                farm[i][j]=val-'0';
            }
        }
        /*for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<farm[i][j];
            }
            cout<<endl;
        }*/

        int center = n/2;
        int sum=0;
        for(int di=-center; di<=center; di++){
            for(int dj=-center; dj<=center; dj++){
                if(abs(di)+abs(dj)<=center){
                    sum+=farm[center+di][center+dj];
                }
            }
        }
        cout<<'#'<<test_case<<' '<<sum<<endl;

        for(int i=0; i<n; i++){
            delete[] farm[i];
        }
        delete[] farm;
    }
    return 0;
}