#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int ans[11][10];

// 어피치보다 1점 높거나 0점만 가능
int dfs(vector<int> info, int idx, int arrow){
  if (idx > 10 || arrow == 0) return 0;
  int ret = 0;
  int sol = 0;

  // 어피치가 쏜 과녁
  if (info[idx]){
    // 1점 더 높게 쏘기
    int cnt = info[idx]+1;
    if (arrow - cnt >= 0){
      sol = dfs(info,idx+1,arrow-cnt)+(10-idx)*2;
      if (ret <= sol){
        ret = sol;
        ans[idx][arrow] = cnt;
      }
    }
  }
  
  // 어피치가 안쏜 과녁
  else{
    // 1점 더 높게 쏘기
    int cnt = info[idx]+1;
    if (arrow - cnt >= 0){
      sol = dfs(info,idx+1,arrow-cnt)+(10-idx);
      if (ret <= sol){
        ret = sol;
        ans[idx][arrow] = cnt;
      }
    }
  }
  
  // 0점 쏘기
  sol = dfs(info,idx+1,arrow);
  if (ret <= sol){
    ret = sol;
    ans[idx][arrow] = 0;
  }

  return ret;
}

vector<int> solution(int n, vector<int> info){
  int arrow = n;
  int idx = 0;
  vector<int> v;
  int apeach = 0;
  
  for (int i=0; i<info.size(); i++)
    if (info[i])
      apeach += (10-i);
  
  if (dfs(info,0,arrow) <= apeach){
    v.push_back(-1);
    return v;
  }

  v.resize(11);

  while (arrow > 0 && idx < 11){
    v[idx] = ans[idx][arrow];
    arrow -= ans[idx++][arrow];
  }

  if (arrow > 0){
    idx = 10;
    while (arrow > 0){
      v[idx]++;
      arrow--;
    }
  }
  return v;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  n = 10;
  
  vector<int> ans = solution(n,{0,0,0,0,0,0,0,0,5,5,0});

  for (auto a: ans)
    cout << a << " ";
}