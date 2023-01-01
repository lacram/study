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

string str;
int dp[5001];
// 0이 포함될시 앞으로 2자리 숫자가 만들어져야함
int solution() {
  for (int i=1; i<str.size(); i++) {
    if (str[i] == '0') {
      if (!('1' <= str[i-1] && str[i-1] <= '2')) 
        return 0;
    }
  }

  dp[0] = 1;
  dp[1] = 1;
  for (int i=2; i<str.size(); i++) {
    if (str[i] != '0') dp[i] = dp[i-1];
    int num = stoi(str.substr(i-1,2));
    
    if (10 <= num && num <= 26) dp[i] += dp[i-2];

    dp[i] %= 1000000;
  }

  return dp[str.size()-1];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> str;
  str.insert(0,"a");

  cout << solution();
}