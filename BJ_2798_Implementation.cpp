//
// Created by Kina on 2020/02/08.
//
#include <iostream>
using namespace std;

int main(void){
    int nCard, target;
    int* cardArr=NULL;

    cin>>nCard>>target;
    cardArr=new int[nCard];

    for(int i=0; i<nCard; i++) {
        cin>>cardArr[i];
    }

    int sum=0;
    int tmp=0;

    bool flag=true;
    for(int i=0; i<nCard-2; i++){
        for(int j=i+1; j<nCard-1; j++){
            for(int k=j+1; k<nCard; k++){
                tmp=cardArr[i]+cardArr[j]+cardArr[k];
                if(tmp<=target)
                    if(tmp>sum)
                        sum=tmp;
            }
        }
    }
    cout<<sum;
    delete[] cardArr;
    return 0;
}