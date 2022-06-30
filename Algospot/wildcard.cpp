#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

string wild;
string str;


bool solve(int spos, int wpos){
  if (wpos == wild.length() && spos == str.length())
    return true;

  if (wild[wpos] == '?' || str[spos] == wild[wpos]){
    return solve(spos+1, wpos+1);
  }
  if (wild[wpos] == '*'){
    if (solve(spos, wpos+1) || (spos < str.length() && solve(spos+1,wpos)))
      return true;
  }
  
  return false;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  // ifstream cin;
  // cin.open("test.txt");

  int test,n;
  cin >> test;

  while(test--){
    cin >> wild;
    cin >> n;
    vector<string> answer;
    for (int i=0; i<n; i++){
      cin >> str;
      if (solve(0,0)) answer.push_back(str);
    }
    sort(answer.begin(), answer.end());
    for (int i=0; i<answer.size(); i++){
    cout << answer[i] << '\n';
  }
  }

  
  
}