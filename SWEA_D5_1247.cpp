//
// Created by Kina on 20. 8. 31..
//
#include<iostream>
using namespace std;
int N, min_dist, test_case, T;

struct Point {
    int x;
    int y;
    bool visit;
};

int Manhattan_dist(Point p1, Point p2) {
    int h_dist = p1.x - p2.x;
    int v_dist = p1.y - p2.y;
    if (h_dist < 0) h_dist = -h_dist;
    if (v_dist < 0) v_dist = -v_dist;
    return h_dist + v_dist;
}

Point Office;
Point Home;
Point Customer[10];

int greedy() {
    Point current = Office;
    int visit_cnt = N;
    int res = 0;
    while (visit_cnt) {
        int idx = 0;
        int local_min = 10000;
        for (int i = 0; i < N; i++) {
            if (Customer[i].visit == true) continue;
            int dist = Manhattan_dist(current, Customer[i]);
            if (dist < local_min) {
                local_min = dist;
                idx = i;
            }
        }
        current = Customer[idx];
        Customer[idx].visit = true;
        res += local_min;
        visit_cnt--;
    }
    res += Manhattan_dist(current, Home);
    return res;
}

void init_visit() {
    for (int i = 0; i < N; i++) {
        Customer[i].visit = false;
    }
}

void find(Point current, int n, int dist) {
    if (n == 0) {
        int tmp = Manhattan_dist(current, Home);
        if (dist + tmp < min_dist) {
            min_dist = dist + tmp;
            return;
        }
    }
    for (int i = 0; i < N; i++) {
        if (Customer[i].visit == true) continue;
        int tmp = Manhattan_dist(current, Customer[i]);
        if (dist + tmp < min_dist) {
            Customer[i].visit = true;
            find(Customer[i], n - 1, dist + tmp);
            Customer[i].visit = false;
        }
    }
}

int main(int argc, char** argv)
{
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        cin >> Office.x >> Office.y >> Home.x >> Home.y;
        for (int i = 0; i < N; i++) {
            cin >> Customer[i].x >> Customer[i].y;
            Customer[i].visit = false;
        }
        min_dist = greedy();
        init_visit();
        find(Office, N, 0);
        cout << '#' << test_case << ' ' << min_dist << '\n';
    }
    return 0;
}