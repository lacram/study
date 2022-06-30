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
priority_queue<int,vector<int>,greater<int>> minheap;

int solve(){
  int ans = 0;
  while (1){
    int a = minheap.top();
    minheap.pop();
    int b = minheap.top();
    minheap.pop();
    
    ans += a+b;
    if (minheap.empty()) return ans;

    minheap.push(a+b);
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    int num;
    cin >> num;

    minheap.push(num);
  }

  if (n == 1) cout << 0;
  else cout << solve();
}