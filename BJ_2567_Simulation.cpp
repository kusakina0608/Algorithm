//
// Created by Kina on 2020/02/08.
//
#include <iostream>
using namespace std;

class Paper{
private:
    bool paper[101][101];
public:
    Paper(){
        for(int i=0; i<101; i++) {
            for (int j=0; j<101; j++) {
                paper[i][j] = false;
            }
        }

    }
    void AddPaper(int bottom, int left){
        bottom++;
        left++;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                paper[100-bottom-i][left+j]=true;
            }
        }
    }
    void ShowPeper() const{
        for(int i=1; i<101; i++){
            for(int j=1; j<101; j++){
                cout<<paper[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    int Getlen(){
        int len=0;
        for(int i=0; i<101; i++){
            len+=paper[i][0] + paper[0][i] + paper[i][100] + paper[100][i];
        }
        for(int i=0; i<101; i++){

        }
        for(int i=0; i<100; i++){
            for(int j=0; j<101; j++) {
                if(paper[i][j] != paper[i+1][j]) len++;
            }
        }
        for(int i=0; i<101; i++){
            for(int j=0; j<100; j++) {
                if(paper[i][j] != paper[i][j+1]) len++;
            }
        }
        return len;
    }
};

int main(void){
    Paper paper;
    int i, j, n;
    cin>>n;
    for(int k=0; k<n; k++){
        cin>>j>>i;
        paper.AddPaper(i, j);
    }
    cout<<paper.Getlen();
    return 0;
}