#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#define endl '\n'

using namespace std;

double n,x;
priority_queue<double, vector<double>, greater<double>> leftheap;
priority_queue<double, vector<double>, greater<double>> rightheap;
vector<double> v;
vector<int> memo;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> x;

  int ans = 0;

  for (int i=0; i<n; i++){
    long long a;
    cin >> a;
    if (a >= x) {
      ans++;
      continue;
    }
    if (a >= x/2) rightheap.push(a);
    else{
      v.push_back(a);
    } 
  }

  sort(v.begin(), v.end());
  int lo = 0;
  int hi = v.size()-1;

  while (lo < hi){
    if (v[lo]+v[hi] > x/2) hi--;
    else if (v[lo]+v[hi] < x/2) lo++;
    else {
      ans++;
      memo.push_back(lo);
      memo.push_back(hi);
      hi--;
      lo++;
    }
  }
  sort(memo.begin(), memo.end());
  int idx = 0;
  
  for (int i=0; i<v.size(); i++){
    if (!memo.empty() && i == memo[idx]){
      idx++;
      continue;
    }
    leftheap.push(v[i]);
  }

  while (leftheap.size() >= 2){
    double a = leftheap.top();
    leftheap.pop();

    if (!rightheap.empty() && a+rightheap.top() >= x/2){
      rightheap.pop();
      ans++;
      continue;
    }

    double b = leftheap.top();
    leftheap.pop();
    double c = a+b+x/2;

    if (c >= x) {
      ans++;
      continue;
    }
    rightheap.push(c);
  }

  if (leftheap.size() == 1 && rightheap.size() % 2 == 1){
    ans += rightheap.size()/2+1;
  }
  else{
    ans += rightheap.size()/2;
  }

  cout << ans;
}