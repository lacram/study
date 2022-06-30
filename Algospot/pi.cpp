#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;
string str;
int dp[10000];

int solve(int srt, int end){
  int cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt5=0;
  int n = end-srt+1;
  for (int i=srt; i<=end; i++){
    if (str[i] == str[srt]) cnt1++;
  }
  for (int i=srt; i<=end-1; i++){
    if (str[i] == str[i+1]+1) cnt2++;
    if (str[i]+1 == str[i+1]) cnt3++;
    if (str[i] - str[i+1] == str[srt] - str[srt+1]) cnt5++;
  }
  for (int i=srt; i<=end; i++){
    if (i%2 == srt%2 && str[i] == str[srt])  cnt4++;
    if (i%2 == (srt+1)%2 && str[i] == str[srt+1])  cnt4++;
  }

  if (cnt1 == n) return 1;
  if (cnt2 == n-1 || cnt3 == n-1) return 2;
  if (cnt4 == n) return 4;
  if (cnt5 == n-1) return 5;
  return 10;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  // ifstream cin;
  // cin.open("test.txt");

  int test;
  cin >> test;

  while (test--){
    cin >> str;

    dp[2] = solve(0,2);
    dp[3] = solve(0,3);
    dp[4] = solve(0,4);
    dp[5] = dp[2] + solve(3,5);
    dp[6] = min(dp[2]+solve(3,6), dp[3]+solve(4,6));
    
    for (int i=7; i<str.length(); i++){
      int ret = min(dp[i-5]+solve(i-4,i), dp[i-4]+solve(i-3,i));
      dp[i] = min(ret, dp[i-3]+solve(i-2,i));
    }

    cout << dp[str.length()-1] << '\n';
  }
  
}