#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#define endl '\n'

using namespace std;

int n,des,noil;
vector<pair<int,int>> v;
priority_queue<int> maxheap;

int solve(){
  int cnt = 0;

  for (int i=0; i<=n; i++){
    while (v[i].first > noil) {
      if (maxheap.empty()) return -1;

      noil += maxheap.top();
      maxheap.pop();
      cnt++;
    }

    maxheap.push(v[i].second);
  }
  return cnt;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    int a,b;
    cin >> a >> b;

    v.push_back({a,b});
  }

  cin >> v[n].first >> noil;

  sort(v.begin(), v.end());

  cout << solve();
}