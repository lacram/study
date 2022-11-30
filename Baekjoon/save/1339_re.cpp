#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
string alpha[10];
vector<pair<char,int>> v;

bool compare(pair<char,int> p1, pair<char,int> p2){
  return p1.second >= p2.second;
}

int solve(){

  for (int i=0; i<n; i++)
    for (int j=0; j<alpha[i].length(); j++){
      bool check = false;
      int value = pow(10, alpha[i].length()-j-1);

      for (int k=0; k<v.size(); k++)
        if (v[k].first == alpha[i][j]){
          v[k].second += value;
          check = true;
        }

      if (!check)
        v.push_back({alpha[i][j],value});
    }
  
  int ans = 0;
  int num = 9;

  sort(v.begin(), v.end(), compare);

  for (auto a : v){
    ans += a.second*num;
    num--;
  }

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
    cin >> alpha[i];
  }

  cout << solve();
}