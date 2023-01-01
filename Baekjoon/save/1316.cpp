#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#define endl '\n'
#define INF 2000000000

using namespace std;

int n;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  int ans = 0;
  string str;
  for (int i=0; i<n; i++) {
    cin >> str;

    // 0 미방문, 1 방문, 2 방문 완료
    int visited[26] = {0};
    int last = str[0];
    bool flag = true;

    for (auto s : str) {
      int now = s - 'a';
      if (visited[now] == 2) {
        flag = false;
        break;
      }

      if (!visited[now]) visited[now] = 1;
      // 연속이 끊김
      if (last != now) visited[last] = 2;
      last = now;
    }

    if (flag) ans++;
  }

  cout << ans;
}