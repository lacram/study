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

char leftBracket[3] = {'{', '[', '(' };
char rightBracket[3] = {'}', ']', ')'};

bool isRightBracketString(string str) {
  int arr[3] = {0,0,0};
  int idx = 0;

  for (int i=0; i<str.size(); i++) {
    char c = str[i];
    for (int j=0; j<3; j++) {
      if (c == leftBracket[j]) {
        arr[j]++;
        idx = i;
      }
      if (c == rightBracket[j]) {
        if (str[idx] == leftBracket[j] && arr[j] > 0) {
          arr[j]--;
          idx--;
        }
        else return false;
      }
    }
  }
  for (int i=0; i<3; i++) {
    if (arr[i] != 0) return false;
  }
  return true;
}

// int solution(string s) {
//   int ans = 0;
//   for (int i=0; i<s.size(); i++) {
//     if (isRightBracketString(s.substr(i)+s.substr(0,i))) {
//       ans++;
//     }
//   }
//   return ans;
// }

int solution(string s) {
  int ans = 0;
  if (isRightBracketString(s)) {
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

  cout << solution("{[][]}");

}