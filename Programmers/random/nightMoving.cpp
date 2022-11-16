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

/* 
x = scope % (근무+휴식) 
1<= x <= 근무 --> 잡힘
else 안잡힘
 */
int solution(int distance, vector<vector<int>> scope, vector<vector<int>> times) {
  int ans = distance;

  for (int i=0; i<scope.size(); i++) {
    int work = times[i][0];
    int rest = times[i][1];

    for (int dist=min(scope[i][0],scope[i][1]); dist<=max(scope[i][0],scope[i][1]); dist++) {
      int x = dist % (work+rest);
      if (1 <= x && x <= work) {
        ans = min(ans, dist);
      }
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