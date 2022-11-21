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

int getValue(long long idx, int n) {
  int i = idx / n;
  int j = idx % n;

  int value = max(i,j)+1;
  return value;
}

vector<int> solution(int n, long long left, long long right) {

  vector<int> ans;
  for (long long i=left; i<=right; i++) {
    ans.push_back(getValue(i,n));
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