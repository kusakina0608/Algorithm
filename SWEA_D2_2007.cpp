//
// Created by Kina on 2020/05/25.
//
#include <iostream>
using namespace std;

class PatternChecker{
private:
    char str[31];
    int start;
    int end;
public:
    PatternChecker()
            : start(0), end(0) {
        cin>>str;
    }
    int checkPattern(){
        int count=0;
        int index = 1;
        for(int ptn_len=1; ptn_len<=15; ptn_len++){
            bool flag = true;
            for(int n_ptn=0; n_ptn<30/ptn_len; n_ptn++){
                if(str[n_ptn]!=str[n_ptn+ptn_len]){
                    flag=false;
                    break;
                }
            }
            if(flag) {
                count=ptn_len;
                break;
            }
        }
        return count;
    }
};

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cout<<'#'<<test_case<<' '<<PatternChecker().checkPattern()<<endl;
    }
    return 0;
}