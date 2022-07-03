#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;
double memo[2002][1001];

double solve(int len, int day){
  if (len <= 0 && day >= 0) return 1;
  if (len > 0 && day <= 0) return 0;

  double &ret = memo[len][day];
  if (ret != -1) return ret;
  
  return ret =  solve(len-1, day-1)*0.25 + solve(len-2, day-1)*0.75;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cout.precision(10);

  // ifstream cin;
  // cin.open("test.txt");

  int test, len, day;
  cin >> test;

  while (test--){
    cin >> len >> day;
    
    for (int i=0; i<=len*2; i++)
      for (int j=0; j<day+1; j++)
        memo[i][j] = -1;

      
    cout << solve(len,day) << endl;
  }
  
}