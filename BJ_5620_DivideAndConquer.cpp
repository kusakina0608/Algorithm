//
// Created by Kina on 2020/04/15.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

vector<Point> points;
int N;

bool cmp_x(const Point &u, const Point &v) {
    return u.x < v.x;
}

bool cmp_y(const Point &u, const Point &v) {
    return u.y < v.y;
}

int squared_dist(Point &p1, Point &p2) {
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

int min_dist;
void ClosestPair(int left, int right){
    if(right-left+1 <= 4) {
        for(int i=left;i<right;++i) {
            for(int j=i+1;j<=right;++j) {
                int tmp = squared_dist(points[i], points[j]);
                if(min_dist > tmp) {
                    min_dist = tmp;
                }
            }
        }
        return;
    }
    int mid = (left+right)/2;
    ClosestPair(left, mid); //left
    ClosestPair(mid+1, right); //right

    vector<Point> sub;
    for(int i=left;i<=mid;++i) {
        int tmp = points[i].x-points[mid].x;
        if(tmp * tmp < min_dist) {
            sub.push_back(points[i]);
        }
    }
    for(int i=mid+1;i<=right;++i) {
        int tmp = points[i].x- points[mid].x;
        if(tmp * tmp >= min_dist) break;
        sub.push_back(points[i]);
    }
    sort(sub.begin(), sub.end(), cmp_y);

    int n = sub.size();
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int tmp = sub[j].y - sub[i].y;
            if(tmp * tmp >= min_dist) break;
            tmp = squared_dist(sub[i], sub[j]);
            if(tmp<min_dist){
                min_dist=tmp;
            }
        }
    }
    return;
}

int main(void){
    int x, y;
    scanf("%d",&N);
    for (int i=0; i<N; i++) {
        scanf("%d %d",&x,&y);
        points.push_back(Point{x, y});
    }
    sort(points.begin(), points.end(), cmp_x);
    min_dist = squared_dist(points[0], points[1]);
    ClosestPair( 0, N-1);

    printf("%d", min_dist);
    return 0;
}