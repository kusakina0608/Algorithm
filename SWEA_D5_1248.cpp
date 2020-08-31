//
// Created by Kina on 20. 8. 31..
//
#include<iostream>
using namespace std;

int V, E, t1, t2, v1, v2, res, child_cnt;

struct Node {
    int num;
    Node *parent;
    Node *lc, *rc;
};

Node edge_list[10001];
// root node: edge_list[1];
bool check[10001];

void link(int v1, int v2) {
    edge_list[v2].parent = &edge_list[v1];
    if (edge_list[v1].lc == NULL) {
        edge_list[v1].lc = &edge_list[v2];
    }
    else {
        edge_list[v1].rc = &edge_list[v2];
    }
}

void init_globals(int E) {
    for (int i = 1; i <= E; i++) {
        edge_list[i] = { i, NULL, NULL, NULL };
        check[i] = false;
    }
}

int counting_child(Node* p) {
    if (p->lc == NULL && p->rc == NULL) {
        return 1;
    }
    else {
        int cnt = 0;
        if (p->rc != NULL) {
            cnt += counting_child(p->rc);
        }
        cnt += counting_child(p->lc);
        return cnt + 1;
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> V >> E >> t1 >> t2;
        init_globals(E);
        for (int i = 0; i < E; i++) {
            cin >> v1 >> v2;
            link(v1, v2); // parent, child
        }
        for (Node* p = &edge_list[t1]; p != NULL; p = p->parent) {
            check[p->num] = true;
        }
        for (Node* p = &edge_list[t2]; p != NULL; p = p->parent) {
            if (check[p->num] == true) {
                res = p->num;
                break;
            }
        }
        child_cnt = counting_child(&edge_list[res]);
        cout << '#' << test_case << ' ' << res << ' ' << child_cnt << '\n';
    }
    return 0;
}