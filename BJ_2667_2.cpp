//#include <iostream>
//using namespace std;
//
//int N, cnt = 0, top;
//char** map;
//
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//typedef struct {
//	int y, x;
//}point;
//
//point stack[1024];
//point p;
//int stack_res[512];
//
//bool can_go(point next) {
//	return 0 <= next.y && next.y < N && 0 <= next.x && next.x < N;
//}
//
//int dfs() {
//	int num = 0;
//	while (top != -1) {
//		point cur = stack[top--];
//		if (map[cur.y][cur.x] == '1') {
//			map[cur.y][cur.x] = 'a';
//			num++;
//			for (int i = 0; i < 4; i++) {
//				point next;
//				next.y = cur.y + dy[i];
//				next.x = cur.x + dx[i];
//				if (can_go(next)) {
//					if (map[next.y][next.x] == '1') {
//						stack[++top] = next;
//					}
//				}
//			}
//		}
//	}
//	return num;
//}
//
//void kina_swap(int* a, int* b) {
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N;
//	top = -1;
//	map = new char*[N];
//	for (int i = 0; i < N; i++) {
//		map[i] = new char[N];
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (map[i][j] == '1') {
//				p.y = i;
//				p.x = j;
//				stack[++top] = p;
//				stack_res[cnt] = dfs();
//				cnt++;
//			}
//		}
//	}
//	cout << cnt << '\n';
//
//	// Selection sort
//	for (int i = 0; i < cnt-1; i++) {
//		int min_idx = i;
//		for (int j = i+1; j < cnt; j++) {
//			if (stack_res[j] < stack_res[min_idx])
//				min_idx = j;
//		}
//		kina_swap(stack_res + min_idx, stack_res + i);
//	}
//	for(int i=0; i<cnt; i++)
//		cout << stack_res[i] << '\n';
//	for (int i = 0; i < N; i++) {
//		delete[] map[i];
//	}
//	delete[] map;
//	return 0;
//}