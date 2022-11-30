#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int n, c;
char str[15];
int used[15]={0};
vector<char> ans;

bool isVowel(char t){
  if(t == 'a' || t=='e' || t=='o' || t=='u' ||t=='i')
    return true;
  return false;
}

void solve(int srt, int m, int j){
  if (ans.size() == n){
    if (m >= 1 && j >= 2){
      for(auto a: ans)
        cout << a;
      cout << endl;
    }
    return;
  }

  for (int i=srt; i<c; i++){
    if (!used[i]){
      ans.push_back(str[i]);
      if (isVowel(str[i])) solve(i+1, m+1, j);
      else solve(i+1, m, j+1);
      ans.pop_back();
    }
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> c;

  for (int i=0; i<c; i++){
    cin >> str[i];
  }

  sort(str, str+c);

  solve(0,0,0);
}