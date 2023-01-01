#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <stack>
#define endl '\n'

using namespace std;

int n;
string ans;
bool fin = false;

bool can(string str){
  int len = str.length();

  for (int j=1; j<=len/2; j++){
    if (str.substr(len-j*2,j) == str.substr(len-j)){
      return false;
    }
  }
  return true;
}

void solve(string str){
  if (fin) return;

  if (str.length() == n) {
    ans = str;
    fin = true;
    return;
  }

  for (char i='1'; i<='3'; i++){
    if (can(str+i)) 
      solve(str+i);
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n;

  string str = "1";

  solve(str);

  cout << ans;
}