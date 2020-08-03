//#include <iostream>
//using namespace std;
//
//int N, top, res, res_max, max_height;
//int** map;
//int** land;
//
//typedef struct {
//	int y, x;
//}point;
//
//int dy[] = { 0, 0, 1, -1 };
//int dx[] = { 1, -1, 0, 0 };
//
//bool kina_can_go(point pos) {
//	return 0 <= pos.y && pos.y < N && 0 <= pos.x && pos.x < N;
//}
//
//point p;
//point stack[20000];
//
//void dfs() {
//	while (top > -1) {
//		point p2 = stack[top--];
//		if (land[p2.y][p2.x] == -1) {
//			land[p2.y][p2.x] = 1;
//			for (int i = 0; i < 4; i++) {
//				point next;
//				next.y = p2.y + dy[i];
//				next.x = p2.x + dx[i];
//				if (kina_can_go(next)) {
//					if (land[next.y][next.x] == -1) {
//						stack[++top] = next;
//					}
//				}
//			}
//		}
//	}
//}
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N;
//	map = new int*[N];
//	land = new int*[N];
//	for (int i = 0; i < N; i++) {
//		map[i] = new int[N];
//		land[i] = new int[N];
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//			if (map[i][j] > max_height)
//				max_height = map[i][j];
//		}
//	}
//	res_max = 0;
//	for (int h = 0; h < max_height; h++) {
//		res = 0;
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				if (map[i][j] > h) {
//					land[i][j] = -1;
//				}
//				else {
//					land[i][j] = 0;
//				}
//			}
//		}
//		//
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				if (land[i][j] == -1) {
//					top = -1;
//					p.y = i;
//					p.x = j;
//					stack[++top] = p;
//					dfs();
//					res++;
//				}
//			}
//		}
//		//cout << "height: " << h << ", res: " << res << endl;
//		if (res > res_max) res_max = res;
//	}
//	cout << res_max;
//	for (int i = 0; i < N; i++) {
//		delete[] map[i];
//		delete[] land[i];
//	}
//	delete[] map;
//	delete[] land;
//	return 0;
//}