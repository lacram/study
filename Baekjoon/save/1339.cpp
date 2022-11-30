#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
vector<pair<char,int>> v;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    string str;
    cin >> str;

    for (int j=0; j<str.length(); j++){
      bool have = false;
    
      for (int k=0; k<v.size(); k++){
        if (v[k].first == str[j]){
          v[k].second += pow(10,str.length()-1-j);
          have = true;
        }
      }
      if (!have)
        v.push_back({str[j], pow(10,str.length()-1-j)});
    }
  }

  int ans = 0;
  int num = 9;

  for (int j=0; j<v.size(); j++){
    int maxAlpha = 0;
    int maxIdx = 0;

    for (int i=0; i<v.size(); i++){
      if (v[i].second > maxAlpha){
        maxAlpha = v[i].second;
        maxIdx = i;
      }
    }
    ans += v[maxIdx].second * num;
    num--;
    v[maxIdx].second = 0;
  }
  
  cout << ans;
}