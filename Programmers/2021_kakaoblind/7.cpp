#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#define endl '\n'
#define INF 987654321

using namespace std;

int sales[300001];
vector<int> tree[300001];
int dp[300001][2];

/*
dp[1][0] : 1이 루트인 서브트리에서 1을 선택하지 않았을때 최소 매출액
dp[1][1] : 1이 루트인 서브트리에서 1을 선택했을때 최소 매출액 
*/

int dfs(int now, int sel) {

  int &ret = dp[now][sel];
  if (ret) return ret;

  bool flag = false;
  int minDiff = INF;

  for (auto next : tree[now]) {
    
    ret += min(dfs(next, 0), dfs(next,1));
    // 자식중에 선택되는 것이 이득인 경우가 있을 때 해당하는 dp[next][1]를 더하면 됨
    if (dp[next][1] < dp[next][0]) {
      flag = true;
    }

    minDiff = min(minDiff, dp[next][1]-dp[next][0]);
  
  }
  // 자식중에 선택되는 것이 이득인 경우가 없을 때 손해를 최소로 보는 것을 더해줌
  if (sel) ret += sales[now];
  else {
    if (tree[now].empty()) return dp[now][sel] = 0;

    if (!flag) {
      ret += minDiff;
    }
  }

  return ret;
}

int solution(vector<int> s, vector<vector<int>> links) {
    int answer = 0;
    for(int i=0;i<s.size();i++)
   		sales[i+1] = s[i];

    for(int i=0;i<links.size();i++)
        tree[links[i][0]].push_back(links[i][1]);

    answer = min(dfs(1,0),dfs(1,1));
    
    return answer;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution({14, 17, 15, 18, 19, 14, 13, 16, 28, 17}   ,     {{10, 8}, {1, 9}, {9, 7}, {5, 4}, {1, 5}, {5, 10}, {10, 6}, {1, 3}, {10, 2}});

}