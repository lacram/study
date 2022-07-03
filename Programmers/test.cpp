#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
int MAP[25][25][5];  // 진행중인 방향
bool visited[25][25];
int dy[4] = {-1, 1, 0, 0};  // 상하좌우
int dx[4] = {0, 0, -1, 1};
//직선 도로 하나를 만들 때는 100원이 소요되며, 코너를 하나 만들 때는 500
int solution(vector<vector<int>> board) {
    int answer = INF;
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                MAP[i][j][k] = INF;
            }
        }
    }
    for (int k = 0; k < 4; k++) {
        MAP[0][0][k] = 0;
    }
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dir = q.front().second;
        q.pop();
        visited[y][x] = true;
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            int ndir = k;
            if (0 > ny || ny > n - 1 || 0 > nx || nx > n - 1) continue;
            if (board[ny][nx] == 1) continue;  // 벽은 진행 불가          
            if (dir == ndir) {  // 그대로 전진
                if (MAP[ny][nx][ndir] > MAP[y][x][dir] + 100) {
                    MAP[ny][nx][ndir] = MAP[y][x][dir] + 100;
                    q.push({{ny, nx}, ndir});
                }                
            } else {  // 방향이 바뀜
                if (MAP[ny][nx][ndir] > MAP[y][x][dir] + 600) {
                    MAP[ny][nx][ndir] = MAP[y][x][dir] + 600;
                    q.push({{ny, nx}, ndir});
                } 
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        answer = min(answer, MAP[n - 1][n - 1][i]);
    }
    return answer-500;
}
