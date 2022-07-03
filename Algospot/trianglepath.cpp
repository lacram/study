#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;
int triangle[100][100];

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

    for (int i=0; i<n; i++)
      for (int j=0; j<i+1; j++)
        cin >> triangle[i][j];
    
    for (int i=1; i<n; i++)
      for (int j=0; j<i+1; j++){
        if (j==0) triangle[i][j] += triangle[i-1][j];
        else if (j==i) triangle[i][j] += triangle[i-1][j-1];
        else triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1]);
      }
      
    int maxnum = 0;
    for (int j=0; j<n; j++)
      maxnum = max(triangle[n-1][j], maxnum);
    
    cout << maxnum << endl;
  }
  
}