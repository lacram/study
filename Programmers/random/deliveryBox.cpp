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
원하는 차례가 아닐경우 보조 컨테이너(stack)에 담기
 */
int solution(vector<int> order) {
  stack<int> subcontainer;

  int givenBox = 1;
  int ans = 0;
  for (auto wantBox : order) {

    if (wantBox == givenBox) {
      givenBox++;
    } else if (!subcontainer.empty() && subcontainer.top() == wantBox) {
      subcontainer.pop();
    } else { 
      // 일치하지 않는 경우 보조 컨테이너에 담기
      while (givenBox != wantBox) {
        if (givenBox > order.size()) {
          return ans;
        }
        subcontainer.push(givenBox);
        givenBox++;
      }
      givenBox++;
    }
    ans++;
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({2, 1, 6, 7, 5, 8, 4, 9, 3, 10});

}