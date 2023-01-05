#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int n;
vector<vector<int>> board(7, vector<int>(7,0));
vector<vector<string>> ans(7);

// (x,y) -> (y,n-1-x) 4,1 -> 1,1
void rotate() {
	vector<vector<int>> tmp = board;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[j][n-1-i] = tmp[i][j];
		}
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		for (auto a : ans[i]) {
            cout << a << " ";
        }

		cout << endl;
	}
}

void saveLine(int idx, vector<int> line) {
	string str = "";
	for (int i = 0; i < n; i++) {
		str.push_back(line[i] + '0');
	}
	ans[idx].push_back(str);
}

void saveResult() {
	for (int i = 0; i < n; i++) {
		saveLine(i,board[i]);
	}
}

void solution() {
	for (int i = 0; i < 3; i++) {
		rotate();
		saveResult();
	}
	print();
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	// ifstream cin;
	// cin.open("input.txt");

	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		ans.clear();
		ans.resize(7);

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		cout << "#" << k << endl;
		solution();
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

