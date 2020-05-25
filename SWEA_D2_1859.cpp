//
// Created by Kina on 2020/01/29.
//
#include<iostream>
using namespace std;

class StuffManager{
private:
    int* price;
    int numOfPriceInfo;
public:
    StuffManager(int n)
            : numOfPriceInfo(n) {
        price = new int[numOfPriceInfo];
    }
    void ReadPriceInfo(){
        for(int i=0; i<numOfPriceInfo; i++){
            scanf("%d", price+i);
        }
    }
    void ShowStatus() const{
        cout<<"Price: ";
        for(int i=0; i<numOfPriceInfo; i++){
            cout<<price[i]<<" ";
        }
        cout<<endl;
    }
    long long GetMaximumMargin() const{
        long long maxMargin=0;
        int maxidx=numOfPriceInfo-1;
        for(int i=numOfPriceInfo-1; i>=0; i--){
            if(price[maxidx]>price[i])
                maxMargin+=price[maxidx]-price[i];
            else
                maxidx=i;
        }
        return maxMargin;
    }
    ~StuffManager(){
        delete[] price;
    }
};

int main(int argc, char** argv)
{
    int test_case;
    int T, N;

    //cin>>T;
    scanf("%d", &T);
    for(test_case = 1; test_case <= T; ++test_case)
    {
        //cin>>N;
        scanf("%d", &N);
        StuffManager sm = StuffManager(N);
        sm.ReadPriceInfo();
        //sm.ShowStatus();
        //cout<<"#"<<test_case<<' '<<sm.GetMaximumMargin()<<endl;
        printf("#%d %lld\n", test_case, sm.GetMaximumMargin());
    }
    return 0;
}