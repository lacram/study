#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

vector<int> arr;
int swit[10000];
int bulb[10000];
int dp[10000];
int n;
vector<int> ans;

int solve(int srt){

  int& ret = dp[srt];
  if (ret!=-1) return ret;
  ret = 1;

  for (int i=srt; i<n; i++){
    if (arr[srt] < arr[i])
      ret = max(ret, solve(i)+1);
  }
  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  memset(dp, -1, sizeof(dp));
  for (int i=0; i<n; i++)
    cin >> swit[i];
  for (int i=0; i<n; i++)
    cin >> bulb[i];

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      if (bulb[i] == swit[j])
        arr.push_back(j+1);

  int maxLis=0,maxLisIndex;
  for (int i=0; i<n; i++){
    int sol = solve(i);
    if (sol > maxLis){
      maxLis = sol;
      maxLisIndex = i;
    }
  }

  int index=maxLisIndex,lis=maxLis;
  while (lis>0){
    if (dp[index] == lis) {
      ans.push_back(index);
      lis--;
    }
    index++;
  }

  vector<int> ret;
  for (auto a : ans)
    ret.push_back(bulb[a]);

  sort(ret.begin(), ret.end());

  cout << maxLis << endl;
  for (auto a : ret)
    cout << a << " ";
  
}