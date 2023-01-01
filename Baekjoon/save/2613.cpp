#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

int n,m;
vector<int> v;
vector<int> a;

bool decision(int limit){
  int cnt = 1;
  int total=0;
  for (int i=0; i<v.size(); i++){
    if (limit < v[i]) return false;
    if (total + v[i] <= limit) total += v[i];
    else {
      cnt++;
      total = v[i];
    }
  }
  
  return cnt <= m;
}

int optimize(){
  int left = 0;
  int right = 30001;

  for (int i=0; i<100; i++){
    int mid = (left+right)/2;

    if(decision(mid)) right = mid;
    else left = mid;
  }
  return right;
}

void reconstruct(int limit){
  int total = 0;
  int cnt = 0;
  for (int i=0; i<v.size(); i++){
    if (total + v[i] <= limit) {
      total += v[i];
      cnt++;
    }
    else {
      total = v[i];
      a.push_back(cnt);
      cnt=1;
    }
  }
  a.push_back(cnt);
}

void print(){
  int cnt = m-a.size();
  for (int i=0; i<a.size(); i++){
    while(cnt > 0 && a[i] > 1){
      cnt--;
      a[i]--;
      cout << 1 << " ";
    }
    cout << a[i] << " ";
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<n; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }
  int ans = optimize();
  cout << optimize() << endl;

  reconstruct(ans);
  print();
  
}