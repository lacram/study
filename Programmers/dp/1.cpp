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

/* 
dp[1]
5
dp[2]
5+5
5-5
5x5
5/5
55
dp[3] = dp[2] ㅁ dp[1]
dp[4] = dp[1] ㅁ dp[3], dp[2] dp[2], dp[3] dp[1]
 */

vector<set<int>> dp(10);

int solution(int N, int number) {
  
  for (int i=1; i<=8; i++) {
    int num = stoi(string(i, N+'0'));
    if (num == number) return i;
    dp[i].insert(num);
  }

  for (int i=2; i<=8; i++) {
    for (int j=1; j<i; j++) {
      set<int> tmp;
      for (auto s1 : dp[j]) {
        for (auto s2 : dp[i-j]) {
          tmp.insert(s1 + s2); 
          tmp.insert(s1 - s2); 
          tmp.insert(s1 * s2); 
          if (s2) tmp.insert(s1 / s2); 
        }
      }
      for (auto t : tmp) {
        if (t == number) return i;
        dp[i].insert(t);
      }
    }
  }
  return -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution(8,	53	);

}