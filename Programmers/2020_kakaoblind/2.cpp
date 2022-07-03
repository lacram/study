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

bool isBalanced(string str) {
  int cnt = 0;
  for (auto s : str) {
    if (s == '(') cnt++;
    if (s == ')') cnt--;
  }
  return !cnt;
}

bool isRight(string str) {
  int cnt = 0;
  for (auto s : str) {
    if (s == '(') cnt++;
    if (s == ')') cnt--;

    if (cnt < 0) return false;
  }
  return !cnt;
}

// 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
// 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
// 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
//   3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
// 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
//   4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
//   4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
//   4-3. ')'를 다시 붙입니다. 
//   4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
//   4-5. 생성된 문자열을 반환합니다.
string solution(string p) {
  if (p == "" || isRight(p)) return p;

  for (int i=2; i<=p.size(); i++) {
    // 2
    if (isBalanced(p.substr(0,i))) {
      string u = p.substr(0,i);
      string v = p.substr(i);

      // 3
      if (isRight(u)) {
        return u + solution(v);
      }
      // 4
      else {
        string ans = "(" + solution(v) + ")";
        string tmp = u.substr(1,u.size()-2);
        for (int j=0; j<tmp.size(); j++) {
          if (tmp[j] == '(') tmp[j] = ')';
          else tmp[j] = '(';
        }
        return ans + tmp;
      }
    }
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution(")(");

}