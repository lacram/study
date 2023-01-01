#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

string str;

struct Comparator {
  const vector<int>& group;
  int t;
  Comparator(const vector<int>& _group, int _t) : group(_group), t(_t) {}

  bool operator() (int a, int b) {
    //첫 t글자가 다르면 이들을 이용해 비교한다.
    if (group[a] != group[b]) return group[a] < group[b];
    //아니라면 S[a+t..]와 S[b+t..]의 첫 t글자를 비교한다.
    return group[a + t] < group[b + t];

  }
};
 
vector<int> getSuffixArray(const string& s) {
 
  int n = s.size();

  int t = 1;
  vector<int> group(n + 1);
  for (int i = 0; i < n; i++) 
    group[i] = s[i];
  group[n] = -1;

  vector<int> perm(n);

  for (int i = 0; i < n; i++) 
    perm[i] = i;

  while (t < n) {

    Comparator compareUsing2T(group, t);
    sort(perm.begin(), perm.end(), compareUsing2T);
    //2t글자가 n을 넘는다면 이제 접미사 배열 완성!
    t *= 2;
    if (t >= n)
      break;
    //2t글자를 기준으로 한 그룹 정보를 만든다.
    vector<int> newGroup(n + 1);
    newGroup[n] = -1;
    newGroup[perm[0]] = 0;
    for (int i = 1; i < n; i++)
      if (compareUsing2T(perm[i - 1], perm[i]))
        newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
      else
        newGroup[perm[i]] = newGroup[perm[i - 1]];

    group = newGroup;
  }
  return perm;
}

int commonPrefix(string s, int i, int j){
  int k = 0;
  while(i < s.size() && j < s.size() && s[i] == s[j]){
    i++;
    j++;
    k++;
  }
  return k;
}

int solve(int k, string s){
  vector<int> a = getSuffixArray(s);
  int ret = 0;

  for (int i=0; i+k <= s.size(); i++){
    ret = max(ret, commonPrefix(s, a[i], a[i+k-1]));
  }

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> str;

  cout << solve(2, str);
}