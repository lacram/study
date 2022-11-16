#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#define endl '\n'
#define INF 2000000000

using namespace std;

int solution(vector<vector<int>> sizes) {
  int row = 0;
  int col = 0;

  for (auto size : sizes) {
    row = max(row, max(size[0],size[1]));
    col = max(col, min(size[0],size[1]));
  }
  
  return row*col;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}