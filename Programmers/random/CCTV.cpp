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

bool compare(vector<int> v1, vector<int> v2) {
  if (v1[1] == v2[1]) {
    return v1[0] < v2[0];
  }
  return v1[1] < v2[1];
}

int solution(vector<vector<int>> routes) {
  sort(routes.begin(), routes.end(), compare);

  int ans = 0;
  int now = -INF;
  for (auto route : routes) {
    int fr = route[0];
    int to = route[1];

    if (fr > now) {
      now = to;
      ans++;
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