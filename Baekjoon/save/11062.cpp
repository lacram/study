#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int cards[1000];
int memo[1000][1000][3];

int solve(int srt, int end, int player){
  if (srt > end) return 0;

  int &ret=memo[srt][end][player+1];
  if (ret!=-1) return ret;

  int a = solve(srt+1,end,-player)+cards[srt];
  int b = solve(srt,end-1,-player)+cards[end];
  ret = max(a,b);

  if (player == 1) return ret;
  return ret = min(solve(srt+1,end,-player), solve(srt,end-1,-player));
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  // ifstream cin;
  // cin.open("test.txt");

  int test, n;
  cin >> test;

  while (test--){
    cin >> n;

    for (int i=0; i<n; i++){
      cin >> cards[i];
    }

    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
        for (int k=0; k<3; k++)
          memo[i][j][k] = -1;

    cout << solve(0,n-1,1) << endl;
  }
  
} 