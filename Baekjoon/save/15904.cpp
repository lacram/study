#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

string str;
string ucpc = "UCPC";

bool solve(int srt, int t){
  if (t == 3) return true;

  bool ret = false;
  for (int next=srt; next<str.size(); next++){
    if (str[next] == ucpc[t+1])
      ret |= solve(next,t+1);
  }

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  getline(cin, str);
  
  if (solve(0,-1)) cout << "I love UCPC";
  else cout << "I hate UCPC";
}