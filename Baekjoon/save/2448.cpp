
#include <iostream>
#include <cstring>
using namespace std;

char arr[3100][6200];

void print(int x, int y){
  arr[x][y] = '*';
  arr[x+1][y-1] = arr[x+1][y+1]= '*';
  for (int i=0; i<5; i++){
    arr[x+2][y-2+i] = '*';
  }
}

void solve(int x, int y, int cnt){
  print(x,y);
  if (cnt == 0) return;

  solve(x,y,cnt/2);
  solve(x+3*cnt,y-3*cnt,cnt/2);
  solve(x+3*cnt,y+3*cnt,cnt/2);

}

int main(){
  int n;
  cin >> n;
  memset(arr, ' ' ,sizeof(arr));

  solve(0,n-1,n/3/2);
  for(int i=0; i<n; i++){
    for(int j=0; j<n*2-1; j++)
      cout << arr[i][j];
    cout << '\n';
  }
}