//
// Created by Kina on 20. 8. 31..
//
#include<iostream>
#define UULMAX 0xffffffffffffffff
typedef unsigned long long ull;
using namespace std;

struct Point {
    int x;
    int y;
};

struct Node {
    Point pos;
    ull dist;
};

int T, test_case, N, selected, min_idx;
ull answer;
double E;
Node dist[1000];

ull get_dist(Node* n1, Node* n2) {
    ull res_x = (n1->pos.x) - (n2->pos.x);
    ull res_y = (n1->pos.y) - (n2->pos.y);
    ull result = res_x * res_x + res_y * res_y;
    return result;
}

void swap_value(int n1, int n2) {
    Node tmp = dist[n1];
    dist[n1] = dist[n2];
    dist[n2] = tmp;
}

// 프림
// 1. 정점 선택
// 2. 모든 섬에 대해 거리 계산하여 dist 갱신
// 3. 최소 거리 섬을 선택(swap)
int main(int argc, char** argv) {
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N;
        answer = 0;
        for (int i = 0; i < N; i++) {
            cin >> dist[i].pos.x;
        }
        for (int i = 0; i < N; i++) {
            cin >> dist[i].pos.y;
            dist[i].dist = UULMAX;
        }
        cin >> E;
        dist[0].dist = 0;
        for (int i = 0; i < N-1; i++) {
            min_idx = i + 1;
            for (int j = i+1; j < N; j++) {
                ull tmp_dist = get_dist(&(dist[i]), &(dist[j]));
                if (tmp_dist < dist[j].dist) {
                    dist[j].dist = tmp_dist;
                }
                if (dist[j].dist < dist[min_idx].dist) {
                    min_idx = j;
                }
            }
            swap_value(i + 1, min_idx);
            answer += dist[i + 1].dist;
        }
        answer = (ull)((double)answer*E + 0.5);
        cout << '#' << test_case << ' ' << answer<<'\n';
    }
    return 0;
}