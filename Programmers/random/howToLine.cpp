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
k = a*(n-1)! + b*(n-2)! ... z*(1)!
 */

long long getFactorial(int n) {
  if (n == 1) return 1;
  return n * getFactorial(n-1);
}

vector<long long> getAns(int n, long long k) {
  vector<long long> ans;
  for (int i=n-1; i>=1; i--) {
    if (k == 0) ans.push_back(i);
    else ans.push_back((k-1)/getFactorial(i));
    k %= getFactorial(i);
  }
  return ans;
}

vector<int> solution(int n, long long k) {
  vector<long long> ans = getAns(n,k);
  vector<int> tmp;
  for (int i=1; i<=n; i++) {
    tmp.push_back(i);
  }
  vector<int> res;
  for (auto a: ans) {
    res.push_back(tmp[a]);
    tmp.erase(tmp.begin()+a);
  }
  res.push_back(tmp[0]);
  return res;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<int> ans =  solution(4,6);
  for (auto a: ans) {
    cout << a << " ";
  }

}