#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int cost[101];
int memorys[101];
int dp[101][10001];
int n,memory;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  // ifstream cin;
  // cin.open("test.txt");

  cin >> n >> memory;

  for (int i=1; i<=n; i++){
    cin >> memorys[i];
  }
  int total=0;
  for (int i=1; i<=n; i++){
    cin >> cost[i];
    total += cost[i];
  }
    
  for (int i=0; i<=n; i++)
    for (int j=0; j<=total; j++){
      if (i==0) dp[i][j] = 0;
      else{
        if (j-cost[i]>=0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]]+memorys[i]);
        else dp[i][j] = dp[i-1][j];
      }
    }
  
  int k=-1;
  for (int j=0; j<=total; j++){
    for (int i=0; i<=n; i++)
      if (dp[i][j] >= memory){
        cout << j << " ";
        k=j;
        break;
      }
    if (k!=-1) break;
  }
    

}