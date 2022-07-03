#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int test, n;
string wildcard;
string str;
int dp[100][100];

bool solve(int w, int s){
  if (w == wildcard.length()){
    return s == str.length();
  }

  int& ret = dp[w][s];
  if (ret != -1) return ret;
  ret = 0;

  if (wildcard[w] == str[s] || wildcard[w] == '?'){
    return ret = solve(w+1,s+1);
  }
  if (wildcard[w] == '*'){
    for (int i=s; i<=str.length(); i++)
      if (solve(w+1,i))
        return ret = 1;
  }

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> test;
  while(test--){
    cin >> wildcard;
    cin >> n;

    vector<string> v;

    for (int i=0; i<n; i++){

      cin >> str;
      
      memset(dp,-1,sizeof(dp));

      if (solve(0,0)) v.push_back(str);
    }

    sort(v.begin(), v.end());

    for (auto a: v)
      cout << a << endl;
  }
}