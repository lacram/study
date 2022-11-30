#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n, k, ans=0;
string str[50];
int num[50];
int total;
vector<int> v;

int getTotal(){

  int acnti = 0;
  acnti |= 1 << ('a'-'a');
  acnti |= 1 << ('c'-'a');
  acnti |= 1 << ('n'-'a');
  acnti |= 1 << ('t'-'a');
  acnti |= 1 << ('i'-'a');

  for (int i=0; i<n; i++){
    int tmp = 0;
    for (int j=0; j<str[i].length(); j++)
      tmp |= 1 << (str[i][j]-'a');

    tmp -= acnti;
    // num[i]에 acnti를 제외한 알파벳이 2진수로 기록
    num[i] = tmp;
  }
  
  int t = 0;
  for (int i=0; i<n; i++){
    t |= num[i];
  }

  return t;
}

void solve(int depth, int selected, int srt){

  if (depth == k-5){
    int ret = 0;
    for (int i=0; i<n; i++)
      // selected가 num[i]를 포함해야함
      if ((selected & num[i]) == num[i])
        ret++;
    ans = max(ans, ret);

    return;
  }

  for (int i=srt; i<v.size(); i++)
    solve(depth+1, selected + (1 << v[i]), i+1);
    
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> k;

  for (int i=0; i<n; i++){
    cin >> str[i];
  }

  total = getTotal();

  int t = 25;
  while (total){
    if (total - (1<<t) >= 0){
      total -= (1<<t);
      v.push_back(t);
    }
    t -= 1; 
  }
  if (k >= v.size()+5) cout << n;
  else {
    if (k >= 5) solve(0,0,0);

    cout << ans;
  }
}