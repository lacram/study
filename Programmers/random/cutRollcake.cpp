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

int leftCount[10001];
int rightCount[10001];
int leftTopping;
int rightTopping;

// 오른쪽으로 하나씩 이동하면서 모든 조각을 내어 n회 비교해봄
int solution(vector<int> topping) {

  // 왼쪽

  // 오른쪽
  for (int i=0; i<topping.size(); i++) {
    if (rightCount[topping[i]] == 0) {
      rightTopping++;
    }
    rightCount[topping[i]]++;
  }

  int ans = 0;
  for (int i=0; i<topping.size(); i++) {
    if (leftTopping == rightTopping) {
      ans++;
    }
    // 왼쪽
    if (leftCount[topping[i]] == 0) {
      leftTopping++;
    }
    leftCount[topping[i]]++;
    // 오른쪽
    rightCount[topping[i]]--;
    if (rightCount[topping[i]] == 0) {
      rightTopping--;
    }
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}