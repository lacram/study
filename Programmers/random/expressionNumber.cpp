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
#define INF 2000000000

using namespace std;

// lo hi
int solution(int n) {
  int lo = 0;
  int hi = 1;
  int cnt = lo + hi;
  int ans = 0;

  while (lo <= n) {
    if (cnt < n) {
      cnt += ++hi;
    } else if (cnt > n) {
      cnt -= lo++;
    } else {
      ans++;
      cnt += ++hi;
    }
  }
  
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}