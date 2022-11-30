#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

string str;

bool solve(){
  int cnt = 0;

  for (int i=0; i<str.length(); i++){
    if (str[i] == 'P'){
      cnt++;
    }
    if (str[i] == 'A'){
      if (i == str.length()-1) return false;
      if (str[i+1] == 'A') return false;

      if (str[i+1] == 'P'){
        if (cnt < 2) return false;
        else cnt -= 2;
      }
    }
  }
  return cnt == 1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> str;

  if (solve()) cout << "PPAP";
  else cout << "NP";
}