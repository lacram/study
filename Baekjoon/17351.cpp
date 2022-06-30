#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int n; 
  cin >> n;
	int dp[505][505][5];

	memset(dp, -1, sizeof(dp));

	char map[505][505], mola[] = { ' ', 'M','O','L','A' };

	FOR(i, 1, n) FOR(j, 1, n) cin >> map[i][j];

	function <int(int, int, int)> get_dp = [&](int r, int c, int cnt) {
		char ch = map[r][c];
		if (ch == 'M') cnt = 1;
		else if (ch == 'O' && cnt == 1) cnt = 2;
		else if (ch == 'L' && cnt == 2) cnt = 3;
		else if (ch == 'A' && cnt == 3) cnt = 4;
		else cnt = 0;

		if (ch != mola[cnt]) cnt = 0;
		if (r == n && c == n) return (cnt == 4) * 1;

		int& ret = dp[r][c][cnt];
    
		if (ret != -1) return ret;
		if (r < n) ret = max(ret, get_dp(r + 1, c, cnt));
		if (c < n) ret = max(ret, get_dp(r, c + 1, cnt));
		return ret += (cnt == 4);
	};

	cout << get_dp(1, 1, 0) << '\n';

	return 0;
}