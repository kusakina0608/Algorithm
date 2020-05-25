//
// Created by Kina on 2020/02/12.
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
        int** field=NULL;
        int fieldSize;
        int swatterSize;
        cin>>fieldSize>>swatterSize;
        field=new int*[fieldSize];
        for(int i=0; i<fieldSize; i++){
            field[i]=new int[fieldSize];
            for(int j=0; j<fieldSize; j++){
                cin>>field[i][j];
            }
        }

        int max=0;
        for(int i=0; i<=fieldSize-swatterSize; i++){
            for(int j=0; j<=fieldSize-swatterSize; j++){
                int sum=0;
                for(int k=0; k<swatterSize; k++){
                    for(int l=0; l<swatterSize; l++){
                        sum+=field[i+k][j+l];
                    }
                }
                if(max<sum){
                    max=sum;
                }
            }
        }
        cout<<'#'<<test_case<<' '<<max<<endl;

        for(int i=0; i<fieldSize; i++){
            delete[] field[i];
        }
        delete[] field;
    }
    return 0;
}