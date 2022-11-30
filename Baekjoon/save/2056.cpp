#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int spendTime[10000];
int finTime[10000];
vector<vector<int>> parent;

int solve(){

  for (int i=0; i<n; i++){
    int fin = spendTime[i];
    for (int j=0; j<parent[i].size(); j++){
      fin = max(fin, finTime[parent[i][j]]+spendTime[i]);
    }
    finTime[i] = fin;
  }
  int ans = 0;
  for (int i=0; i<n; i++)
    ans = max(ans, finTime[i]);

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> spendTime[i];
    int t,p;
    vector<int> v;
    cin >> t;
    for (int j=0; j<t; j++){
      cin >> p;
      v.push_back(p-1);
    }
    parent.push_back(v);
  }

  cout << solve();
}