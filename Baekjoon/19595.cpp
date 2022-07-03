#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int a,k,test;
// 이번턴에 x인 사람이 이기면 1
int dp[100001];
int notprime[100001];
int psum[100001];
vector<int> prime;

void eratos(){
  for (int i=2; i<=sqrt(100000); i++){
    if (notprime[i]) continue;
    for (int j=i*i; j<=100000; j+=i){
      notprime[j] = 1;
    }
  }
  
  for (int i=2; i<=100000; i++)
    if (!notprime[i]) 
      prime.push_back(i);
}

int setDp(int x){

  int &ret = dp[x];
  if (ret != -1) return ret;
  
  ret = 0;

  int idx = lower_bound(prime.begin(), prime.end(),x)-prime.begin();
  if (prime[idx] > x) idx--;

  for (int i=idx; i>=0; i--){
    if (setDp(x-prime[i]) == 0) return ret = 1;
  }
  return ret;
}

void setPsum(){
  for (int i=2; i<=100000; i++)
    dp[i] = !dp[i];

  psum[2] = dp[2];
  for (int i=3; i<=100000; i++){
    psum[i] = psum[i-1]+dp[i];
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  eratos();
  memset(dp,-1,sizeof(dp));
  dp[0] = 0;
  dp[1] = 0;
  for (int i=2; i<=100000; i++){
    setDp(i);
  }
    
  setPsum();

  cin >> test;

  while (test--){

    cin >> a >> k;

    int ans = 0, minx = 100000;
    for (int i=2; i<=a+1-k; i++){
      int ret = psum[i+k-1]-psum[i-1];
      if (ans < ret){
        ans = ret;
        minx = i;
      }
    }

    cout << ans << " " << minx << endl;
  }
}