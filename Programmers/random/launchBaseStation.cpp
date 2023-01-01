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
빈 공간을 모두 찾고 길이 / 범위 이후 반올림
 */

int solution(int n, vector<int> stations, int w)
{
  int fr;
  int to = 1;
  vector<double> blanks;
  for (auto station : stations) {
    fr = station - w - 1;
    blanks.push_back(fr - to + 1);
    to = station + w + 1;
  }
  blanks.push_back(n - (stations.back()+w));

  int ans = 0;
  for (auto blank : blanks) {
    ans += ceil(blank / (w*2+1));
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