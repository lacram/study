#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
// #include<fstream>

using namespace std;

int n = 100;
int board[100][100];

int getRowSum(int idx) {
    int total = 0;
    for (int i=0; i<n; i++) {
        total += board[idx][i];
    }
    return total;
}

int getMaxRowSum() {
    int total = 0;
    for (int i=0; i<n; i++) {
        total = max(total, getRowSum(i));
    }
    return total;
}

int getColSum(int idx) {
    int total = 0;
    for (int i=0; i<n; i++) {
        total += board[i][idx];
    }
    return total;
}

int getMaxColSum() {
    int total = 0;
    for (int i=0; i<n; i++) {
        total = max(total, getColSum(i));
    }
    return total;
}

int getLeftDiagonalSum() {
    int total = 0;
    for (int i=0; i<n; i++) {
        total += board[i][i];
    }
    return total;
}

int getRightDiagonalSum() {
    int total = 0;
    for (int i=0; i<n; i++) {
        total += board[i][n-1-i];
    }
    return total;
}

int getMaxDiagonalSum() {
    return max(getLeftDiagonalSum(), getRightDiagonalSum());
}

int solution() {
    return max({getMaxColSum(), getMaxRowSum(), getMaxDiagonalSum()});
}

int main()
{
	// ifstream cin;
	// cin.open("input.txt");

    int t = 10;
	for (int k = 1; k <= t; k++) {
        int test;
        cin >> test;
        
        for (int i=0; i<100; i++) {
            for (int j=0; j<100; j++) {
                cin >> board[i][j];
            }
        }

		cout << "#" << k << " " << solution() << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

