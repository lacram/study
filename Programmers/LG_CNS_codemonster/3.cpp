#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#define endl '\n'
#define INF 2000000000

using namespace std;

int ans = 0;

map<string, bool> record;

bool canJump(int fr, int size, string reference, string track) {
  string toFind = track.substr(fr, size);
  if (record[toFind]) return record[toFind];
  return record[toFind] = reference.find(toFind) != string::npos;
}

void dfs(int fr, int res, string reference, string track) {
  int n = track.size();
  
  if (fr == n) {
    ans = max(ans, res);
  }

  for (int size=reference.size(); size>=1; size--) {
    if (fr + size > n) continue;
    if (size <= ans) break;
    if (canJump(fr, size, reference, track)) {
      dfs(fr+size, min(res,size), reference, track);
    }
  }
}

int solution(string reference, string track) {
  
  dfs(0,INF,reference,track);
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution("abc", "bcab");
  cout << solution("vxrvip", "xrviprvipvxrv");
  cout << solution("abcabcabcabcabcabcabcabcabc", "abcabcabcabcabcabcabcabcabc");

}