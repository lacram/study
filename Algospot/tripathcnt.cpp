#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;
int triangle[100][100];
int memo[100][100];
int cache[100][100];
int n;

int getCount(int x, int y){
  if(x == n-1) return 1;
  int& ret = cache[x][y];
  if (ret != -1) return ret;
  ret=0;
  if (memo[x+1][y] >= memo[x+1][y+1]) ret += getCount(x+1,y);
  if (memo[x+1][y] <= memo[x+1][y+1]) ret += getCount(x+1,y+1);
  return ret;
}

int solve(int x, int y){
  int &ret = memo[x][y];
  if (x == n-1) return ret = triangle[x][y];
  if (ret==1) return ret;
  
  return ret = max(solve(x+1,y), solve(x+1,y+1)) + triangle[x][y];
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
    cin >> n;

    memset(cache, -1, sizeof(cache));
    for (int i=0; i<n; i++)
      for (int j=0; j<i+1; j++)
        cin >> triangle[i][j];
    
    solve(0,0);
    
    cout << getCount(0,0) << endl; 
      
  }
  
}