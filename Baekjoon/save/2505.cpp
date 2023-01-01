#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define endl '\n'

using namespace std;

int n;
vector<int> arr;
vector<int> arr2;
vector<int> ans;
vector<pair<int,int>> v = {{1,1},{1,1}};

bool solve(int cnt){
  if (arr == ans){
    return true;
  }
  if (cnt >= 2) return false;
  
  for (int i=1; i<=n; i++){
    if (arr[i] == i) continue;

    int j = i+1;

    // i의 위치를 찾음
    while (arr[j] != i) 
      j++;
    
    // i~j 뒤집기 i가 제자리로 돌아감
    reverse(arr.begin()+i, arr.begin()+j+1);
    v[cnt].first = i;
    v[cnt].second = j;
    return solve(cnt+1);
  }
  return false;
}

bool solve2(int cnt){
  if (arr2 == ans){
    return true;
  }
  if (cnt >= 2) return false;
  
  for (int i=n; i>=1; i--){
    if (arr2[i] == i) continue;

    int j = i-1;

    // i의 위치를 찾음
    while (arr2[j] != i) 
      j--;
    
    // i~j 뒤집기 i가 제자리로 돌아감
    reverse(arr2.begin()+j, arr2.begin()+i+1);
    v[cnt].first = j;
    v[cnt].second = i;
    return solve2(cnt+1);
  }
  return false;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;
  arr.resize(n+1);
  arr2.resize(n+1);
  ans.resize(n+1);

  for (int i=1; i<=n; i++){
    cin >> arr[i];
    arr2[i] = arr[i];
    ans[i] = i;
  }

  if (!solve(0))
    solve2(0);

  for (auto p : v)
    cout << p.first << " " << p.second << endl;
}