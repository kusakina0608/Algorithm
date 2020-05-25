//
// Created by Kina on 2020/05/25.
//
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    int r;
    while(b != 0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(void){
    int count, num, tmp, i, j;
    long long sum;
    vector<int> v;
    cin >> count;

    while(count--){
        cin >> num;

        for(i=0; i<num; i++){
            cin >> tmp;
            v.push_back(tmp);
        }

        for(i=0; i<num-1; i++){
            for(j=i+1; j<num; j++){
                sum += gcd(v[i],v[j]);
            }
        }
        v.clear();
        cout << sum << endl;
        sum = 0;
    }

    return 0;
}