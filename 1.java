import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.StringTokenizer;

// 알고리즘 : BFS
class Solution {

    private static final int[] rx = {1, -1, 0, 0};
    private static final int[] ry = {0, 0, 1, -1};

    private static class Point {
        int y, x;

        public Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());

            int[][] map = new int[N + 1][M + 1];
            for (int i = 1; i <= N; i++) {
                String line = br.readLine();
                for (int j = 1; j <= M; j++) {
                    map[i][j] = line.charAt(j - 1) == '.' ? 0 : 1;
                }
            }

            int[][][] dist = new int[K + 1][N + 1][M + 1];

            int x = 0, y = 0;

            for (int k = 0; k < K; k++) {
                for (int i = 1; i <= N; i++) {
                    Arrays.fill(dist[k][i], -1);
                }
                st = new StringTokenizer(br.readLine());
                y = Integer.parseInt(st.nextToken());
                x = Integer.parseInt(st.nextToken());
                ArrayDeque<Point> queue = new ArrayDeque<>();
                queue.add(new Point(y, x));
                dist[k][y][x] = 0;
                while (!queue.isEmpty()) {
                    Point now = queue.poll();

                    for (int i = 0; i < 4; i++) {
                        int ny = now.y + ry[i];
                        int nx = now.x + rx[i];

                        if (ny < 1 || nx < 1 || ny > N || nx > M)
                            continue;

                        if (map[ny][nx] == 1)
                            continue;

                        if (dist[k][ny][nx] == -1) {
                            dist[k][ny][nx] = dist[k][now.y][now.x] + 1;
                            queue.add(new Point(ny, nx));
                        }
                    }
                }
            }

            int answer = 0;

            for (int i = 0; i < K; i++) {
                if (dist[i][y][x] == -1) {
                    answer = -1;
                    break;
                }
            }

            if (answer != -1 && K > 1) {
                answer = Integer.MAX_VALUE;
                for (y = 1; y <= N; y++) {
                    for (x = 1; x <= M; x++) {
                        if (map[y][x] == 1)
                            continue;

                        int max = 0;
                        for (int k = 0; k <= K; k++) {
                            max = Math.max(max, dist[k][y][x]);
                        }
                        if (max > 0)
                            answer = Math.min(answer, max);
                    }
                }
            }

            System.out.println("#" + tc + " " + answer);
        }
    }
}