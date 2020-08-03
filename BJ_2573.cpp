#include <iostream>
using namespace std;

int N, M, top;
int arr2d[300][300];
bool visited[300][300];
int stack_y[10000];
int stack_x[10000];

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

bool k_on_bound(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < M;
}

int k_decrese_amount(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (k_on_bound(ny, nx) && arr2d[ny][nx] == 0 && !visited[ny][nx]) {
			cnt++;
		}
	}
	if (arr2d[y][x] < cnt) {
		cnt = arr2d[y][x];
	}
	return cnt;
}

void k_read_data() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr2d[i][j];
		}
	}
}

void k_reset_visited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}
}

void dfs_melt(int y, int x) {
	top = 0;
	stack_y[top] = y;
	stack_x[top] = x;
	while (-1 != top) {
		int cy = stack_y[top];
		int cx = stack_x[top];
		top--;
		if (!visited[cy][cx]) {
			visited[cy][cx] = true;
			arr2d[cy][cx] -= k_decrese_amount(cy, cx);
			for (int i = 0; i < 4; i++) {
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				if (k_on_bound(ny, nx) && arr2d[ny][nx] != 0 && !visited[ny][nx]) {
					++top;
					stack_y[top] = ny;
					stack_x[top] = nx;
				}
			}
		}
	}
}

void dfs_count(int y, int x) {
    top = 0;
    stack_y[top] = y;
    stack_x[top] = x;
    while (-1 != top) {
        int cy = stack_y[top];
        int cx = stack_x[top];
        top--;
        if (!visited[cy][cx]) {
            visited[cy][cx] = true;
            for (int i = 0; i < 4; i++) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if (k_on_bound(ny, nx) && arr2d[ny][nx] != 0 && !visited[ny][nx]) {
                    ++top;
                    stack_y[top] = ny;
                    stack_x[top] = nx;
                }
            }
        }
    }
}

int search_glacier() {
	int n_cluster = 0;
    k_reset_visited();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr2d[i][j] != 0 && !visited[i][j]) {
				dfs_melt(i, j);
			}
		}
	}
    k_reset_visited();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr2d[i][j] != 0 && !visited[i][j]) {
                dfs_count(i, j);
                n_cluster++;
            }
        }
    }
	return n_cluster;
}

void k_show_glacier() {
	cout << '\n' << "Glacier" << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr2d[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	k_read_data();
	int year = 0;
	int n; 
	while(true){
        n = search_glacier();
        //k_show_glacier();
        year++;
        if(n != 1){
            break;
        }
	}

	if (n < 2) {
		cout << 0;
	}
	else {
		cout << year;
	}
	return 0;
}