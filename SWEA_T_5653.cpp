//
// Created by Kina on 20. 9. 8..
//
#include <iostream>
#define HEAP_SIZE 55000
using namespace std;

struct Node {
    int i;
    int j;
    int x; // 생명력
    int t; // 활성화까지 남은 시간
};

typedef Node element;

element active_heap[HEAP_SIZE];
element inactive_heap[HEAP_SIZE];
int act_idx;
int inact_idx;
int T, test_case, N, M, K;
int map[1024][1024]; // 4byte x 1024 x 1024 = 4Mbyte
int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };
bool visit[1024][1024]; // 방문 인덱스 체크
int BaseI, BaseJ; // 시작 기준 인덱스 N, M 기준으로 계산

// return true if e1 has higher priority than e2
bool myCompare(element e1, element e2) {
    if (e1.t < e2.t) { // 시간이 적게 남은게 우선순위 높음
        return true;
    }
    else if (e1.t == e2.t) { // 시간이 같을 경우
        if (e1.x > e2.x) { // 활성시간이 긴 쪽이 우선순위 높음
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

void mySwap(element *e1, element *e2) {
    element tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
}

void pushActHeap(int i, int j, int x, int t) {
    act_idx++;
    int idx = act_idx;
    active_heap[idx] = {i, j, x, t};
    while (idx > 1) {
        int p_idx = idx / 2;
        if (myCompare(active_heap[idx], active_heap[p_idx])) {
            mySwap(&active_heap[idx], &active_heap[p_idx]);
            idx = p_idx;
        }
        else {
            break;
        }
    }
}

element popActHeap() {
    element rtn = active_heap[1];
    mySwap(&active_heap[act_idx--], &active_heap[1]);
    int idx = 1;
    while (idx <= act_idx) {
        int l_idx = idx * 2;
        int r_idx = l_idx + 1;
        int swap_idx = -1;
        if (r_idx <= act_idx) {
            swap_idx = myCompare(active_heap[l_idx], active_heap[r_idx])?l_idx:r_idx;
        }
        else if (l_idx <= act_idx) {
            swap_idx = l_idx;
        }
        if (swap_idx>0 && myCompare(active_heap[swap_idx], active_heap[idx])) {
            mySwap(&active_heap[idx], &active_heap[swap_idx]);
            idx = swap_idx;
        }
        else {
            break;
        }
    }
    return rtn;
}

void pushInactHeap(int i, int j, int x, int t) {
    inact_idx++;
    int idx = inact_idx;
    inactive_heap[idx] = { i, j, x, t };
    while (idx > 1) {
        int p_idx = idx / 2;
        if (myCompare(inactive_heap[idx], inactive_heap[p_idx])) {
            mySwap(&inactive_heap[idx], &inactive_heap[p_idx]);
            idx = p_idx;
        }
        else {
            break;
        }
    }
}

element popInactHeap() {
    element rtn = inactive_heap[1];
    mySwap(&inactive_heap[inact_idx--], &inactive_heap[1]);
    int idx = 1;
    while (idx <= inact_idx) {
        int l_idx = idx * 2;
        int r_idx = l_idx + 1;
        int swap_idx = -1;
        if (r_idx <= inact_idx) {
            swap_idx = myCompare(inactive_heap[l_idx], inactive_heap[r_idx]) ? l_idx : r_idx;
        }
        else if (l_idx <= inact_idx) {
            swap_idx = l_idx;
        }
        if (swap_idx > 0 && myCompare(inactive_heap[swap_idx], inactive_heap[idx])) {
            mySwap(&inactive_heap[idx], &inactive_heap[swap_idx]);
            idx = swap_idx;
        }
        else {
            break;
        }
    }
    return rtn;
}

void initialize() {
    BaseI = 512 - (N / 2);
    BaseJ = 512 - (M / 2);
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 1024; j++) {
            visit[i][j] = false;
        }
    }
    act_idx = 0;
    inact_idx = 0;
}

void oneHourLater() {
    for (int i = 1; i <= act_idx; i++) {
        active_heap[i].t--;
    }
    for (int i = 1; i <= inact_idx; i++) {
        inactive_heap[i].t--;
    }
    while (act_idx > 0 && active_heap[1].t == 0) {
        element el = popActHeap();
        for (int k = 0; k < 4; k++) {
            int ni = el.i + di[k];
            int nj = el.j + dj[k];
            if (!visit[ni][nj]) {
                visit[ni][nj] = true;
                map[ni][nj] = el.x;
                pushActHeap(ni, nj, el.x, el.x + 1);
            }
        }
        pushInactHeap(el.i, el.j, el.x, el.x - 1);
    }
    while (inact_idx > 0 && inactive_heap[1].t == 0) {
        popInactHeap();
    }
}

void print_map() {
    cout << "=====================================\n";
    for (int i = BaseI - 10; i < BaseI + N + 10; i++) {
        for (int j = BaseJ - 10; j < BaseJ + M + 10; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "=====================================\n";
}

int main(void) {
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N >> M >> K;
        initialize();
        for (int i = BaseI; i < BaseI + N; i++) {
            for (int j = BaseJ; j < BaseJ + M; j++) {
                cin >> map[i][j];
                if (map[i][j] != 0) {
                    visit[i][j] = true;
                    pushActHeap(i, j, map[i][j], map[i][j]+1);
                }
            }
        }
        for (int k = 0; k < K; k++) {
            oneHourLater();
            //print_map();
        }
        int cellCnt = 0;

        cout << '#' << test_case << ' ' << act_idx + inact_idx << '\n';
    }
    return 0;
}