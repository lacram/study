#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
// #include<fstream>
#include <queue>

using namespace std;

int n,m;
string tmp[16];
int board[16][16];
int visited[16][16];
pair<int,int> start;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int bfs() {
    queue<pair<int,int>> q;
    q.push({start});
    visited[start.first][start.second] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (board[x][y] == 3) return 1;

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 16 || ny >= 16) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] == 1) continue;
            
            visited[nx][ny] = 1;
            q.push({nx,ny});
        }
    }

    return 0;
}

int solution() {
    return bfs();
}

int main()
{
	// ifstream cin;
	// cin.open("input.txt");

	for (int k = 1; k <= 10; k++) {
        memset(visited, 0, sizeof(visited));

        int test;
        cin >> test;

        for (int i=0; i<16; i++) {
            cin >> tmp[i];
        }
        
        for (int i=0; i<16; i++) {
            for (int j=0; j<16; j++) {
                board[i][j] = tmp[i][j]-'0';
                if (board[i][j] == 2) {
                    start.first = i;
                    start.second = j;
                }
            }
        }
        
		cout << "#" << k << " " << solution() << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

