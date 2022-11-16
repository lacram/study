#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#define endl '\n'
#define INF 2000000000

using namespace std;

int solution(vector<string> arr) {
  vector<int> nums;
  vector<string> ops;
  int maxDp[102][102];
  int minDp[102][102];

  for (int i=0; i<arr.size(); i+=2) {
    nums.push_back(stoi(arr[i]));
  }

  for (int i=1; i<arr.size(); i+=2) {
    ops.push_back(arr[i]);
  }

  int n = nums.size();
  
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) {
      maxDp[i][j] = -INF;
      minDp[i][j] = INF;
      if (i == j) {
        maxDp[i][j] = nums[i];
        minDp[i][j] = nums[i];
      }
    }

  // 구간의 크기
  for (int len=1; len<n; len++)
    // 시작점
    for (int i=0; i+len<n; i++) {
      // 도착점
      int j = i+len;
      for (int k=i; k<j; k++){
        if (ops[k] == "+") {
          maxDp[i][j] = max(maxDp[i][j], maxDp[i][k] + maxDp[k+1][j]);
          minDp[i][j] = min(minDp[i][j], minDp[i][k] + minDp[k+1][j]);
        } else { // -일 경우
          maxDp[i][j] = max(maxDp[i][j], maxDp[i][k] - minDp[k+1][j]);
          minDp[i][j] = min(minDp[i][j], minDp[i][k] - maxDp[k+1][j]);
        }
      }
    }

  return maxDp[0][n-1];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution({"5", "-", "3", "+", "1", "+", "2", "-", "4"});

}