#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#define endl '\n'

using namespace std;

int n;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> minheap;

int solve(){
  for (auto p : v){
    if (minheap.size() == p.first){
      if (minheap.top() < p.second){
        minheap.pop();
        minheap.push(p.second);
      }
    }
    else {
      minheap.push(p.second);
    }
  }
  int ans = 0;
  while (!minheap.empty()){
    ans += minheap.top();
    minheap.pop();
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;
  v.resize(n);

  for (int i=0; i<n; i++){
    int a,b;
    cin >> a >> b;

    v[i] = {a,b};
  }

  sort(v.begin(), v.end());

  cout << solve();
}