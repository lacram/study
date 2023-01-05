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
int fr,to;
vector<pair<int,int>> v;

int dist[12][12];
int ans;
int visited[17];

int getDistance(pair<int,int> a, pair<int,int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void setDistance() {
    for (int i=0; i<v.size(); i++) {
        for (int j=0; j<v.size(); j++) {
            dist[i][j] = getDistance(v[i],v[j]);
        }
    }
}

void dfs(int depth, int now, int cost) {
    if (depth == n) {
        ans = min(ans, cost + dist[now][to]);
        return;
    }

    visited[now] = 1;
    for (int next=1; next<=n; next++) {
        if (visited[next]) continue;

        dfs(depth+1, next, cost + dist[now][next]);
    }
    visited[now] = 0;
}

int solution() {
    // 각각 거리 구하기
    setDistance();

    dfs(0,fr,0);

    return ans;
}

int main()
{
	// ifstream cin;
	// cin.open("input.txt");

    int t;
    cin >> t;
	for (int k = 1; k <= t; k++) {
        v.clear();
        ans = 100000000;

        cin >> n;

        pair<int,int> start;
        pair<int,int> dest;
        cin >> start.first >> start.second;
        cin >> dest.first >> dest.second;

        v.push_back(start);
        for (int i=0; i<n; i++) {
            int x,y;
            cin >> x >> y;
            v.push_back({x,y});
        }
        v.push_back(dest);

        fr = 0;
        to = n+1;
        
		cout << "#" << k << " " << solution() << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

