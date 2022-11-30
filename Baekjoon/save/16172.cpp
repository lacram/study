#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

string str, target;
vector<char> updatedStr;

void deleteNum(){
  for (int i=0; i<str.length(); i++){
    if (str[i] - '0' >= 0 && str[i] - '0' <= 9) continue;
    updatedStr.push_back(str[i]);
  }
}

vector<int> getPi(){
  int len = target.length();
  vector<int> pi(len, 0);
  int j = 0;

  for (int i=1; i<len; i++){
    while (j > 0 && target[i] != target[j])
      j = pi[j-1];

    if (target[i] == target[j]){
      j++;
      pi[i] = j;
    }
  }
  return pi;
}

int solve(){
  int j = 0;
  vector<int> pi = getPi();

  for (int i=0; i<updatedStr.size(); i++){
    while (j > 0 && updatedStr[i] != target[j])
      j = pi[j-1];

    if (updatedStr[i] == target[j]){
      if (j == target.length()-1)
        return 1;

      else{
        j++;
      }
    }
  }
  return 0;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  getline(cin,str);
  getline(cin,target);

  deleteNum();

  cout << solve();
}