#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

string str;
string target;

vector<int> getPi(){
  int len = target.size();
  int j = 0;
  vector<int> pi(len, 0);
  
  for (int i=1; i<len; i++){
    // j번째가 일치하지 않을 경우 
    // j-1번째일때 pi[j-1]개가 일치함 -> pi[j-1]-1까지 일치
    // j-1번째일때 pi[j-1]째 글자가 i와 일치해야 j-1번째부터 다시 시작할 수 있음
    while (target[i] != target[j] && j > 0)
      j = pi[j-1];

    if (target[i] == target[j]){
      j++;
      pi[i] = j;
    }
  }

  return pi;
}

vector<int> solve(){

  vector<int> ans;
  vector<int> pi = getPi();
  int j = 0;

  for (int i=0; i<str.size(); i++){
    while (str[i] != target[j] && j > 0)
      j = pi[j-1];

    if (str[i] == target[j]){
      if (j == target.length()-1){
        ans.push_back(i-j);
        j = pi[j];
      }
      else{
        j++;
      }
    }
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  getline(cin, str);
  getline(cin, target);

  vector<int> ans = solve();

  cout << ans.size() << endl;
  for (auto a: ans)
    cout << a+1 << " ";
}