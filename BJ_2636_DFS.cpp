//#include <iostream>
//using namespace std;
//
//int N, M, stage = -1;
//int arr2d[102][102];
//bool visited[102][102];
//
//int stack_y[5000];
//int stack_x[5000];
//int top = -1;
//
//int dy[] = { 0, 0, 1, -1 };
//int dx[] = { 1, -1, 0, 0 };
//
//bool k_on_bound(int y, int x) {
//	return 0 <= y && y <= N && 0 <= x && x <= M;
//}
//
//bool k_can_move(int y, int x) {
//	return stage < arr2d[y][x] && arr2d[y][x] < 1;
//}
//
//bool k_check() {
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			if (arr2d[i][j] > 0) return false;
//		}
//	}
//	return true;
//}
//
//void dfs() {
//	while (top > -1) {
//		int cy = stack_y[top];
//		int cx = stack_x[top];
//		top--;
//		visited[cy][cx] = true;
//		for (int i = 0; i < 4; i++) {
//			int ny = cy + dy[i];
//			int nx = cx + dx[i];
//			if (k_on_bound(ny, nx)) {
//				if (k_can_move(ny, nx)) {
//					if (!visited[ny][nx]) {
//						++top;
//						stack_y[top] = ny;
//						stack_x[top] = nx;
//					}
//				}
//				else {
//					arr2d[ny][nx] = stage;
//				}
//			}
//		}
//	}
//}
//
//void k_clear_visited() {
//	for (int i = 0; i <= N; i++) {
//		for (int j = 0; j <= M; j++) {
//			visited[i][j] = false;
//		}
//	}
//}
//
//void k_show_arr() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			printf("%3d ", arr2d[i][j]);
//			//cout << arr2d[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//}
//
//int main(void) {
//	//ios::sync_with_stdio(false);
//	//cin.tie(NULL);
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			cin >> arr2d[i][j];
//		}
//	}
//	while (!k_check()) {
//		++top;
//		stack_y[top] = 0;
//		stack_x[top] = 0;
//		dfs();
//		stage--;
//		k_clear_visited();
//	}
//	cout << -stage-1 << '\n';
//	int cnt = 0;
//	for (int i = 1; i < N; i++) {
//		for (int j = 1; j < M; j++) {
//			if (arr2d[i][j] == stage+1) cnt++;
//		}
//	}
//	cout << cnt;
//	//k_show_arr();
//	return 0;
//}