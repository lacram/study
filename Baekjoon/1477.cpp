#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int n,m,l;
vector<int> v;

bool decision(int gap){
  int cnt=0, pos=0;

  for (int i=0; i<v.size(); i++)
    cnt += ((v[i]-1) / gap);
  
  return cnt <= m;
}

int optimize(){
  int left = 0;
  int right = 1000;

  for (int i=0; i<100; i++){
    int mid = (left+right)/2;

    if(decision(mid)) right = mid;
    else left = mid;
  }
  return right;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m >> l;

  vector<int> tmp = {0,l};

  for (int i=0; i<n; i++){
    int a;
    cin >> a;
    tmp.push_back(a);
  }
  
  sort(tmp.begin(), tmp.end());

  for (int i=1; i<tmp.size(); i++)
    v.push_back(tmp[i]-tmp[i-1]);
  
  cout << optimize();
}