//
// Created by Kina on 2020/04/15.
//
#include <iostream>
#define x first
#define y second
using namespace std;

pair<int, int> input[5050];
int height[5050];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n;
    for(int i=0; i<n; i++) cin >> input[i].x >> input[i].y;
    cin >> m;
    for(int i=0; i<m; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        int idx;
        for(int j=0; j<n; j++) if(input[j].x == a && input[j].y == b){
                idx = j; break;
            }

        //left
        int now = b;
        for(int j=idx-2; j>=0; j-=2){
            now = min(now, input[j].y);
            height[j] = max(now, height[j]);
        }
        now = b;

        //right
        for(int j=idx+2; j<n; j+=2){
            now = min(now, input[j].y);
            height[j] = max(now, height[j]);
        }
        height[idx] = b;
    }

    int ans = 0;
    for(int i=1; i<n; i+=2){
        int dx = input[i+1].x - input[i].x;
        int dy = input[i].y - height[i];
        ans += dx * dy;
    }
    cout << ans;
}