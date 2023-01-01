#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <set>
#define endl '\n'

using namespace std;

int n,m;
set<string> s;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  string str;
  int ans = 0;

  for (int i=0; i<n; i++){
    cin >> str;
    s.insert(str);
  }

  for (int i=0; i<m; i++){
    cin >> str;
    if (s.find(str) != s.end()) ans++;
  }

  cout << ans;
}