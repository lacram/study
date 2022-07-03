#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int ans=0;
int board[20][20];

// 회전
void rotate(int (*arr)[20]){
  int tmp[20][20];

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) 
      tmp[j][n-1-i] = arr[i][j];

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) 
      arr[i][j] = tmp[i][j];
}

// 왼쪽으로 밀기
void push(int (*arr)[20]){
  
  for (int i=0; i<n; i++){
    int idx = 0;

    for (int j=0; j<n; j++){
      while (arr[i][idx] == 0) idx++;
      if (arr[i][j] == 0) continue;
      if (idx == j) continue;
      
      // 합치기
      if (arr[i][j] == arr[i][idx]){
        arr[i][idx] *= 2;
        arr[i][j] = 0;
        idx++;
      }
      else idx++;
    }
    // 밀기
    idx = 0;
    for (int j=0; j<n; j++){
      if (arr[i][j] == 0) continue;

      if (idx == j) idx++;
      else{
        arr[i][idx] = arr[i][j];
        arr[i][j] = 0;
        idx++;
      }
    }
  }
}

int getMax(int (*arr)[20]){
  int ret = 0;
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      ret = max(ret, arr[i][j]);
  return ret;
}

void solve(int depth, int (*arr)[20]){
  int tmp[20][20];

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      tmp[i][j] = arr[i][j];

  if (depth != 0) push(tmp);

  if (depth == 5){
    ans = max(ans, getMax(tmp));
    return;
  }

  solve(depth+1, tmp);

  for (int i=0; i<3; i++){
    rotate(tmp);
    solve(depth+1, tmp);
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      cin >> board[i][j];

  solve(0,board);

  cout << ans;
}