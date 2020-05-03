//
// Created by Kina on 2020/02/12.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char vowel[] = {'a', 'e', 'i' ,'o', 'u'};

int main(void){
    int cipherLen, nDigit;

    cin>>cipherLen>>nDigit;

    vector<char> char_vec(nDigit);
    vector<int> selector(nDigit);

    for(int i=0; i<nDigit; i++){
        cin>>char_vec[i];
        if(i<cipherLen)
            selector[i]=0;
        else
            selector[i]=1;
    }
    sort(char_vec.begin(), char_vec.end());
    do{
        int nVowel=0;
        int nConsonant=0;
        for(int i=0; i<nDigit; i++){
            if(selector[i]==0){
                if(char_vec[i]==vowel[0]
                   || char_vec[i]==vowel[1]
                   || char_vec[i]==vowel[2]
                   || char_vec[i]==vowel[3]
                   || char_vec[i]==vowel[4]){
                    nVowel++;
                }else{//consonant
                    nConsonant++;
                }
            }
        }
        if(nVowel>=1 && nConsonant>=2){
            for(int i=0; i<nDigit; i++){
                if(selector[i]==0){
                    cout<<char_vec[i];
                }
            }
            cout<<endl;
        }

    }while(next_permutation(selector.begin(), selector.end()));
    return 0;
}