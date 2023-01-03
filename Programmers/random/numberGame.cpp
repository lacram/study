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
#include <set>
#define endl '\n'
#define INF 2000000000

using namespace std;

/* 
7 5 3 1
8 6 2 2
둘다 내림차순을 정렬한 후 이길 수 있으면 ans++
 */

int solution(vector<int> A, vector<int> B) {
  sort(A.begin(), A.end(), greater<>());
  sort(B.begin(), B.end(), greater<>());
  
  int idx = 0;
  int ans = 0;
  for (auto a : A) {
    if (a < B[idx]) {
      ans++; idx++;
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