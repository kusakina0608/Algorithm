// TODO change java -> C++
// Created by Kina on 2020/05/25.
//
/*
import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

class rect{
    int y;
    int x;
public rect(int y, int x) {
        super();
        this.y = y;
        this.x = x;
    }

}

class Main {
    static int M, N, K;
    static int[][] map;
    static boolean[][] visited;
    static int[] counting;
    static int[] dy = { 1, -1, 0, 0 };
    static int[] dx = { 0, 0, 1, -1 };

public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        M = sc.nextInt();// 5
        N = sc.nextInt();// 7
        K = sc.nextInt();
        map = new int[M][N];
        visited = new boolean[M][N];
        counting = new int[M * N];
        for (int k = 0; k < K; k++) {
            int lbj = sc.nextInt(); // 0
            int lbi = M - sc.nextInt(); // 2 =>3
            int rtj = sc.nextInt(); // 4
            int rti = M - sc.nextInt(); // 4 =>1
            for (int i = rti; i < lbi; i++) {
                for (int j = lbj; j < rtj; j++) {
                    map[i][j] = 1;
                }
            }
        } // end Input

        int cnt = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 0 && !visited[i][j]) {
                    bfs(i, j, cnt);
                    cnt++;
                }
            }
        }
        System.out.println(cnt);
        Arrays.sort(counting);
        for(int i=0;i<counting.length;i++) {
            if(counting[i]!=0) {
                System.out.print(counting[i]+" ");
            }
        }

    }

private static void bfs(int y, int x, int cnt) {
        Queue<rect> que = new LinkedList<rect>();
        que.offer(new rect ( y, x ));
        while (!que.isEmpty()) {
            rect r = que.poll();
            int cy = r.y;
            int cx = r.x;
            visited[cy][cx] = true;
            map[cy][cx] = cnt;
            counting[cnt]++;
            for (int d = 0; d < 4; d++) {
                int ny = cy + dy[d];
                int nx = cx + dx[d];
                if (!canGo(ny, nx))
                    continue;
                if (!visited[ny][nx] && map[ny][nx] == 0) {
                    visited[ny][nx] = true;
                    map[ny][nx] = cnt;
                    que.offer(new rect ( ny, nx ));
                }
            }
        }

    }

private static boolean canGo(int ny, int nx) {
        if (0 <= ny && ny < M && 0 <= nx && nx < N)
            return true;
        return false;
    }
}
*/