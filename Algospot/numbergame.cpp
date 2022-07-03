#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int board[50];
int memo[50][50];

int solve(int srt, int end){
  if (srt > end) return 0;

  int &ret = memo[srt][end];
  if(ret!=-1) return ret;

  int a = board[srt] - solve(srt+1,end);
  int b = board[end] - solve(srt,end-1);
  int c = -1000,d=-1000;
  if (end-srt >= 1){
    c = -solve(srt+2,end);
    d = -solve(srt,end-2);
  }
  
  ret = max(a,b);
  ret = max(ret,c);
  ret = max(ret,d);

  return ret;
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
      cin >> board[i];
    }
    memset(memo, -1, sizeof(memo));


    cout << solve(0,n-1) << endl;
    
  }
  
}