#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <map>
using namespace std;

map<int,vector<int>> arr;
double ret[50];

void solve(int visit, int day, double pro){
  if (day == 0) {
    ret[visit] += pro;
    return;
  }

  for (int i=0; i<arr[visit].size(); i++){
    solve(arr[visit][i], day-1, pro/arr[visit].size());
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cout.precision(8);

  // ifstream cin;
  // cin.open("test.txt");

  int test, n, day ,srt, hn;
  cin >> test;

  while (test--){
    cin >> n >> day >> srt;
    vector<int> home;
    memset(ret, 0, sizeof(ret));
    int a;
    for (int i=0; i<n; i++){
      vector<int> v;
      for (int j=0; j<n; j++){
        cin >> a;
        if (a==1) v.push_back(j);
      }
      arr[i] = v;
    } 
    
    cin >> hn;
    int b;
    for (int i=0; i<hn; i++){
      cin >> b;
      home.push_back(b);
    }

    solve(srt,day,1);
    
    for (int i=0; i<hn; i++){
      cout << ret[home[i]] << " ";
    }
    cout << '\n';
  }
  
}