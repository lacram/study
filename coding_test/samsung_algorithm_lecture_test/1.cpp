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

int n;
vector<int> numbers;
int dp[2002];

/* 
모든 경우 순열 만들어 제곱수의 개수 확인
 */

bool isSquareNumber(int number) {
  if (dp[number]) return true;
  return dp[number] = (sqrt(number) == (int) sqrt(number));
}

int solution() {
  sort(numbers.begin(), numbers.end());
  int res = 0;

  do {
    int tmp = 0;
    for (int i=0; i<numbers.size(); i++) {
      if (isSquareNumber(numbers[i] + numbers[(i+1)%numbers.size()])) {
        tmp++;
      }
    }
    res = max(res, tmp);

  } while(next_permutation(numbers.begin()+1, numbers.end()));

  return res;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int test;
  cin >> test;

  for (int j=1; j<=test; j++) {
    cin >> n;
    numbers.clear();

    for (int i=0; i<n; i++) {
      int a;
      cin >> a;
      numbers.push_back(a);
    }

    cout << "#" << j << " " << solution() << endl;
  }
}