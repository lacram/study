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

int dp[1001][1001];
pair<int,int> record[1001][1001];
vector<string> arr;

string getAns() {
  int i = arr[0].size()-1;
  int j = arr[1].size()-1;
  string ans = "";
  while (i && j) {
    if (arr[0][i] == arr[1][j]) ans.push_back(arr[1][j]);
    pair<int,int> p = record[i][j];
    i = p.first;
    j = p.second;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

void solution() {
  int n = arr[0].size();
  int m = arr[1].size();

  for (int i=1; i<n; i++)
    for (int j=1; j<m; j++) {
      if (arr[0][i] == arr[1][j]) {
        dp[i][j] = dp[i-1][j-1] + 1;
        record[i][j] = {i-1,j-1};
      }
      else {
        if (dp[i-1][j] > dp[i][j-1]) {
          dp[i][j] = dp[i-1][j];
          record[i][j] = {i-1,j};
        } else {
          dp[i][j] = dp[i][j-1];
          record[i][j] = {i,j-1};
        }
      }
    }

  cout << dp[n-1][m-1] << endl << getAns();
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  string str1,str2;
  cin >> str1 >> str2;
  str1.insert(0,"1");
  str2.insert(0,"1");
  arr.push_back(str1);
  arr.push_back(str2);

  solution();
}