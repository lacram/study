#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n, ans;
int* col;
vector<vector<int>> t;
vector<int> v;

bool check(int line){
  // col[line]이 가능한지 line 전 행 까지 검사
  // col[line]에서 line는 x좌표, col[line]은 y좌표
  for (int i=0; i<line; i++){
        // 세로 비교
    if (col[line] == col[i] || line-i == abs(col[line] - col[i]))
      return false;
  }
  return true;
}

void solve(int line){
  if (line == n){
    t.push_back(v);
    ans++;
  }
  else{
    for (int i=0; i<n; i++){
      col[line] = i; 
      if (check(line)){
        v.push_back(i);
        solve(line+1);
        v.pop_back();
      }
    }
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n;

  col = new int[n];
  
  solve(0);

  cout << ans << endl;
  for(auto a: t){
    for(auto b: a)
      cout << b+1 << " ";
    cout << endl;
  }
    
}