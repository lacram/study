#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int money,m;
int corp[20][301];
int dp[20][301];
int maxN[20][301];
int ans[20];

void reconstruct(int cp, int m){
  if (cp == -1) return;
  // cp기업에 투자한 금액
  ans[cp] = maxN[cp][m];
  reconstruct(cp-1, m-ans[cp]);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> money >> m;

  for (int i=1; i<=money; i++)
    for (int j=0; j<=m; j++){
      int a;
      cin >> a;
      if (j==0) continue;
      corp[j-1][i] = a;
    }

  for (int i=0; i<m; i++){
    for (int j=1; j<=money; j++){
      if (i == 0) {
        dp[i][j] = corp[i][j];
        maxN[i][j] = j;
      }
      else{
        int ret = 0;

        for (int k=0; k<=j; k++){
          if (ret < corp[i][k]+dp[i-1][j-k]){
            ret = corp[i][k]+dp[i-1][j-k];
            maxN[i][j] = k;
          }
        }
        dp[i][j] = ret;
      }
    }
  }
  
  cout << dp[m-1][money] << endl;

  reconstruct(m-1,money);

  for (int i=0; i<m; i++)
    cout << ans[i] << " ";
}