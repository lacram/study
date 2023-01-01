#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m;
int first[10];
int final[10];
int used[10];

// 모임 전체인원이 감염자인지 여부 파악
bool check(vector<int> v){

  for (int i=0; i<v.size(); i++){
    if (final[v[i]] != 1)
      return false;
  }
  return true;
}

void put(vector<int> v){
  bool check = false;

  for (int i=0; i<v.size(); i++){
    used[v[i]] = 1;
    if (first[v[i]] == 0) {
      check = true;
      break;
    }
    first[v[i]] = 1;
  }
  if (check)
    for (int i=0; i<v.size(); i++){
      first[v[i]] = 0;
    }
}

void remove(vector<int> v){
  for (int i=0; i<v.size(); i++){
    first[v[i]] = 0;
    used[v[i]] = 1;
  }
}

// 애초에 감염자가 0명이었을 경우 NO가 출력되는것을 방지
bool ans(){
  for (int i=0; i<n; i++)
    if (first[i] == 1)
      return true;

  return false;
}

bool ans2(){
  for (int i=0; i<n; i++)
    if (final[i] == 1 && used[i] == 1)
      return false;
  return true;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n >> m;
  vector<int> meeting[m];

  for (int i=0; i<m; i++){
    int t;
    cin >> t;

    for (int j=0; j<t; j++){
      int a;
      cin >> a;
      meeting[i].push_back(a-1);
    }
  }

  for (int i=0; i<n; i++){
    int a;
    cin >> a;
    final[i] = a;
  }

  memset(first, -1, sizeof(first));

  // 마지막 모임부터 역추적
  for (int i=m-1; i>=0; i--){
    // 모임 전체 인원이 감염자
    if (check(meeting[i])) {
      // 초기 감염자에 넣음
      put(meeting[i]);
    } 
    // 모임 일부가 감염자가 아님 -> 해당 모임중 감염자 없음
    // 초기 감염자에서 제거
    else remove(meeting[i]);
  }

  if (ans()){
    cout << "YES" << endl;
    for (int i=0; i<n; i++){
      if (first[i] == -1) cout << 0 << " ";
      else cout << first[i] << " ";
    }
  }
  else{
    if (ans2()){
      cout << "YES" << endl;
      for (int i=0; i<n; i++)
        cout << final[i] << " ";
    }
    else
      cout << "NO";
  }
}