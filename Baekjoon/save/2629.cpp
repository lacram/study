#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <set>
#define endl '\n'

using namespace std;

int n,m,maxN;
int chu[30];
int marble[7];

set<int> s = {0};

void solve(int idx){
  if (idx == n) return;
  
  set<int> tmp;
  for (auto a : s){
    tmp.insert(a+chu[idx]);
    tmp.insert(a-chu[idx]);
  }
  for (auto a: tmp)
    s.insert(a);

  solve(idx+1);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> chu[i];
  }

  cin >> m;

  for (int i=0; i<m; i++){
    cin >> marble[i];
    maxN = max(maxN,marble[i]);
  }

  solve(0);

  for (int i=0; i<m; i++){
    if (s.find(marble[i]) != s.end())
      cout << "Y ";
    else cout << "N ";
  }
}