//
// Created by Kina on 20. 8. 31..
//
#include<iostream>
using namespace std;

struct Info {
    int rc, cc, sc;
    int space;
    Info* next;
};
Info Infobuf[11000];
int bufCnt;
Info *head;
int T, test_case, p, q;
int prc, pcc, psc;
int rc, cc, sc, cnt;
char buf[128];
int res[5000][3];
int top;
void addNode(int, int, int, int);

int main(int argc, char** argv) {
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        prc = 0; pcc = 0; psc = 0;
        rc = 0; cc = 0; sc = 0;
        top = -1;
        bufCnt = 0;
        head = NULL;
        cin >> p >> q;
        for (int i = 0; i < p; i++) {
            cin >> buf;
            bool start = true;
            cnt = 0;
            for (char *c = buf; *c != '\0'; c++) {
                if (*c != '.') {
                    start = false;
                }
                switch (*c) {
                    case '(': rc++; break;
                    case ')': rc--; break;
                    case '{': cc++; break;
                    case '}': cc--; break;
                    case '[': sc++; break;
                    case ']': sc--; break;
                }
                if (start && *c == '.') {
                    cnt++;
                }
            }
            if (prc != 0 || pcc != 0 || psc != 0) {
                addNode(prc, pcc, psc, cnt);
            }
            prc = rc;
            pcc = cc;
            psc = sc;
        }
        for (int a = 1; a <= 20; a++) {
            for (int b = 1; b <= 20; b++) {
                for (int c = 1; c <= 20; c++) {
                    bool flag = true;
                    for (Info *p = head; p != NULL; p = p->next) {
                        if ((((p->rc)*a) + ((p->cc)*b) + ((p->sc)*c)) != p->space) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        top++;
                        res[top][0] = a;
                        res[top][1] = b;
                        res[top][2] = c;
                    }
                }
            }
        }
        /*for (int i = 0; i <= top; i++) {
            cout << "가중치: (" << res[i][0] << ", " << res[i][1] << ", " << res[i][2] << ")\n";
        }*/
        prc = 0; pcc = 0; psc = 0;
        rc = 0; cc = 0; sc = 0;
        cout << '#' << test_case << ' ';
        for (int i = 0; i < q; i++) {
            cin >> buf;
            bool start = true;
            cnt = 0;
            for (char *c = buf; *c != '\0'; c++) {
                if (*c != '.') {
                    start = false;
                }
                switch (*c) {
                    case '(': rc++; break;
                    case ')': rc--; break;
                    case '{': cc++; break;
                    case '}': cc--; break;
                    case '[': sc++; break;
                    case ']': sc--; break;
                }
                if (start && *c == '.') {
                    cnt++;
                }
            }
            // 출력문 작성
            bool valid = true;
            int answer = res[top][0] * prc + res[top][1] * pcc + res[top][2] * psc;
            for (int idx = 0; idx < top; idx++) {
                int tmp = res[idx][0] * prc + res[idx][1] * pcc + res[idx][2] * psc;
                if (tmp != answer) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                answer = -1;
            }
            cout << answer<<' ';
            prc = rc;
            pcc = cc;
            psc = sc;
        }
        cout << '\n';
    }
    return 0;
}


void addNode(int a, int b, int c, int d) {
    Infobuf[bufCnt] = { a, b, c, d, NULL };
    Info *iptr, *prev;
    if (head == NULL) {
        head = &Infobuf[bufCnt++];
        return;
    }
    prev = NULL;
    for (iptr = head; iptr != NULL; iptr = iptr->next) {
        if (iptr->rc > a) { // rc, cc, sc;
            break;
        }
        else {
            if (iptr->rc == a) {
                if (iptr->cc > b) {
                    break;
                }
                else {
                    if (iptr->cc == b) {
                        if (iptr->sc > c) {
                            break;
                        }
                        else {
                            if (iptr->sc == c) {
                                return;
                            }
                        }
                    }
                }
            }
        }
        prev = iptr;
    }
    if (prev == NULL) {
        Infobuf[bufCnt].next = head;
        head = &Infobuf[bufCnt++];
    }
    else {
        Infobuf[bufCnt].next = iptr;
        prev->next = &Infobuf[bufCnt++];
    }
}