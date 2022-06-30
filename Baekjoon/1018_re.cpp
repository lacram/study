#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#define endl '\n'

using namespace std;

string wb[8]= {
  {"WBWBWBWB"},
  {"BWBWBWBW"},
  {"WBWBWBWB"},
  {"BWBWBWBW"},
  {"WBWBWBWB"},
  {"BWBWBWBW"},
  {"WBWBWBWB"},
  {"BWBWBWBW"}
};
string bw[8]= {
  {"BWBWBWBW"},
  {"WBWBWBWB"},
  {"BWBWBWBW"},
  {"WBWBWBWB"},
  {"BWBWBWBW"},
  {"WBWBWBWB"},
  {"BWBWBWBW"},
  {"WBWBWBWB"}
};
int w,h;
char board[50][50];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> h >> w;

  for (int i=0; i<h; i++)
    for (int j=0; j<w; j++)
      cin >> board[i][j];

  int ret=2500, ans=2500;
  
  for (int i=0; i<=h-8; i++)
    for (int j=0; j<=w-8; j++){
      int a=0,b=0;
      for (int x=i; x<i+8; x++)
        for (int y=j; y<j+8; y++){
          if (board[x][y] != bw[x-i][y-j]) a++;
          if (board[x][y] != wb[x-i][y-j]) b++;
        }
      ret = min(a,b);
      ans = min(ans,ret);
    }
  
  cout << ans;
      

    

}