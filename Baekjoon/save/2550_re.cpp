#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

vector<int> arr;
int swit[10000];
int bulb[10000];
int dp[10001];
int n;
int choice[10001];

int solve(int srt){

  int &ret = dp[srt+1];
  if(ret!=-1) return ret;

  ret = 1;
  int bestNext=-1;
  for(int i=srt+1; i<n; i++){
    if (arr[srt] < arr[i] || srt == -1){
      int sol = solve(i)+1;
      if (sol > ret){
        ret = sol;
        bestNext=i;
      }
    }
  }
  choice[srt+1] = bestNext;
  return ret;
}

void reconstruct(int srt, vector<int>& seq){
  if(srt!=-1) seq.push_back(arr[srt]);
  int next = choice[srt+1];
  if(next!=-1) reconstruct(next,seq);
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

  cout << solve(-1)-1 << endl;

  vector<int> v;
  reconstruct(-1, v);

  vector<int> ans;

  for (auto a: v)
    ans.push_back(swit[a-1]);
  
  sort(ans.begin(), ans.end());

  for (auto a: ans)
    cout << a << " ";
}