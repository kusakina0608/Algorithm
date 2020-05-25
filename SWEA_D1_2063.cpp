#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;

    int n; // number of score
    int value;
    int target_index, index;
    int score[200];

    cin>>n;

    for(int i=0; i<n; ++i)
    {
        scanf("%d", score+i);
    }

    target_index = n/2;
    for(int i=0; i<n-1; i++){
        value = 2147483647;
        for(int j=i; j<n; j++){
            if(value>score[j]){
                value = score[j];
                index = j;
            }
        }
        score[i] = score[i] ^ score[index];
        score[index] = score[i] ^ score[index];
        score[i] = score[i] ^ score[index];
    }
    printf("%d", score[target_index]);
    return 0;
}