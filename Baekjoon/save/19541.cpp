#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

vector<vector<int>> meeting;
int n,m;
bool final[100001];
bool first[100001];
bool test[100001];


bool check(vector<int> v, bool* arr, int t){
  for (int i=0; i<v.size(); i++)
    if (arr[v[i]] == t)
      return true;
  return false;
}

void fill(vector<int> v, bool* arr, int t){
  for (int i=0; i<v.size(); i++)
    arr[v[i]] = t;
}

void solve(){

  // 마지막 모임부터 역추적
  for (int i=m-1; i>=0; i--){
    // 비감염자가 1명이라도 있을경우
    if (check(meeting[i], test, 0)){
      // 초기감염자 x
      fill(meeting[i], test, 0);
    }
  }

  for (int i=0; i<n; i++)
    first[i] = test[i];

  // 재구성
  for (int i=0; i<m; i++){
    if (check(meeting[i], test, 1))
      fill (meeting[i], test, 1);
  }

  for (int i=0; i<n; i++)
    if (final[i] != test[i]){
      cout << "NO";
      return;
    }
  
  cout << "YES" << endl;
  for (int i=0; i<n; i++)
    cout << first[i] << " ";
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<m; i++){
    int t;
    cin >> t;

    vector<int> v(t);
    for (int j=0; j<t; j++){
      cin >> v[j];
      v[j]--;
    }
    meeting.push_back(v);
  }

  for (int i=0; i<n; i++){
    cin >> final[i];
    test[i] = final[i];
  }

  solve();
}