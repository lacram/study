#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
// #include<fstream>

using namespace std;

int n,m;
int v,e,a,b;
vector<vector<int>> tree;
int parent[10001];
int value[10001];
int root;

/* 
공통조상, 공통조상을 루트로하는 서브트리의 크기
 */

// 부모, 서브트리의 크기를 기록
int dfs(int now) {
    int total = 1;

    for (auto next : tree[now]) {
        total += dfs(next);
        parent[next] = now;
    }

    return value[now] = total;
}

int getCommonAncestor() {
    int visited[10001] = {};

    while (a) {
        visited[a] = 1;
        a = parent[a];
    }

    while (b) {
        if (visited[b]) return b;
        b = parent[b];
    }

    return -1;
}

void solution() {
    dfs(root);
    
    int commonAncestor = getCommonAncestor();
    cout << commonAncestor << " " << value[commonAncestor] << endl;
}

int main()
{
	// ifstream cin;
	// cin.open("input.txt");

	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
        cin >> v >> e;
        cin >> a >> b;

        tree.clear();
        tree.resize(v+1);

        int visited[10001] = {};

        for (int i=0; i<e; i++) {
            int fr,to;
            cin >> fr >> to;
            tree[fr].push_back(to);

            visited[to]++;
        }

        for (int i=1; i<=v; i++) {
            if (!visited[i]) root = i;
        }
        
		cout << "#" << k << " ";
        solution();
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

