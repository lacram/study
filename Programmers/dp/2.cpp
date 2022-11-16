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

int solution(vector<vector<int>> triangle) {
  int n = triangle.size();

  for (int i=1; i<triangle.size(); i++) 
    for (int j=0; j<triangle[i].size(); j++) {
      if (j == 0) triangle[i][j] += triangle[i-1][j];
      else if (j == triangle[i].size()-1) triangle[i][j] += triangle[i-1][j-1];
      else triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
    }
  
  return *max_element(triangle[n-1].begin(), triangle[n-1].end());
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}