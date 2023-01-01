#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#define endl '\n'

using namespace std;

int n,m;
priority_queue <long long, vector<long long>, greater<long long>> heap;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<n; i++){
    int t;
    cin >> t;
    heap.push(t);
  }

  for (int i=0; i<m; i++){
    long long a = heap.top();
    heap.pop();
    long long b = heap.top();
    heap.pop();

    heap.push(a+b);
    heap.push(a+b);
  }
  long long ans = 0;

  while (!heap.empty()){
    ans += heap.top();
    heap.pop();
  }

  cout << ans;
}