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
priority_queue<int> maxheap;
priority_queue<int,vector<int>,greater<int>> minheap;
int arr[100000];

void solve(){
  for (int i=0; i<n; i++){
    if (maxheap.size() == minheap.size()) maxheap.push(arr[i]);
    else minheap.push(arr[i]);

    while (!maxheap.empty() && !minheap.empty() && maxheap.top() > minheap.top()){
      int a = maxheap.top();
      int b = minheap.top();
      maxheap.pop();
      minheap.pop();
      maxheap.push(b);
      minheap.push(a);
    }

    cout << maxheap.top() << endl;
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
    cin >> arr[i];
  }

  solve();
}