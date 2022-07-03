#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int matrix[5][5];
int n;
vector mul(int &a, int &b){
  int c[5][5];
  memset(c, 0, sizeof(c));
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      for(int k=0; k<n; k++)
        c[i][j] += a[i][k]*b[k][j];
  return c;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  ifstream cin;
  cin.open("input.txt");

  int cnt;
  cin >> n >> cnt;

  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> matrix[i][j];

}