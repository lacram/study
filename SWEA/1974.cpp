#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int n;
int board[9][9];

bool checkVisited(vector<int> visited) {
	for (int i = 1; i<=9; i++) {
		if (visited[i] == 0) return false;
	}
	return true;
}

bool checkRow(int row) {
	vector<int> visited(10, 0);

	for (int i = 0; i < 9; i++) {
		visited[board[row][i]] = 1;
	}

	return checkVisited(visited);
}

bool checkCol(int col) {
	vector<int> visited(9, 0);

	for (int i = 0; i < 9; i++) {
		visited[board[i][col]] = 1;
	}

	return checkVisited(visited);
}

bool checkBox(int x, int y) {
	vector<int> visited(9, 0);
	
	for (int i = x; i < x+3; i++) {
		for (int j = y; j < y+3; j++) {
			visited[board[i][j]] = 1;
		}
	}

	return checkVisited(visited);
}

int solution() {
	int ans = 1;
	// 행
	for (int i = 0; i < 9; i++) {
		ans &= checkRow(i);
	}
	// 열
	for (int i = 0; i < 9; i++) {
		ans &= checkCol(i);
	}
	// 박스
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ans &= checkBox(i * 3, j * 3);
		}
	}
	return ans;
}

int main(int argc, char** argv)
{
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> board[i][j];
			}
		}
		cout << "#" << k << " " << solution() << endl;
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}