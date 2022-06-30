#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int menu[20][20];
int n;
int money;

int memo[201];

int solve(){

  int ans=0;
  memo[0] = 0;
  for (int budget=1; budget<=money; budget++){
    int ret = 0;
    for (int i=0; i<n; i++){
      if (menu[i][0] <= budget)
        ret = max(ret, memo[(budget-menu[i][0])%201]+menu[i][1]);
    }
    memo[budget%201] = ret;
    ans = max(ans, ret);
  }
    
  return ans;
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
    cin >> n >> money;

    for (int i=0; i<n; i++){
      int  a;
      cin >> a >> menu[i][1];
      menu[i][0] = a/100;
    }
    money/=100;
    memset(memo, 0, sizeof(memo));
    cout << solve() << endl;
    
  }
  
}