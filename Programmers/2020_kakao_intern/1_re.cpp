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
1. 147왼손 369 오른손
2. 2580은 가까운손, 같은 거리일시 주로 사용하는 손으로
3. 각 숫자에서 1씩 빼면 좌표화 쉬움
 */

pair<int,int> getPoint(int num) {
  return {num/3,num%3};
}

int getDistance(int a, int b) {
  auto [x1,y1] = getPoint(a);
  auto [x2,y2] = getPoint(b);

  return abs(x2-x1) + abs(y2-y1);
}

string solution(vector<int> numbers, string hand) {
  string ans = "";
  
  int lpos = 9;
  int rpos = 11;
  for (auto num : numbers) {
    if (num == 0) num = 11;
    num--;

    if (num == 0 || num == 3 || num == 6) {
      ans.push_back('L');
      lpos = num;
    }
    else if (num == 2 || num == 5 || num == 8) {
      ans.push_back('R');
      rpos = num;
    }
    else {
      if (getDistance(lpos,num) > getDistance(rpos,num)) {
        ans.push_back('R');
        rpos = num;
      }
      else if (getDistance(lpos,num) < getDistance(rpos,num)) {
        ans.push_back('L');
        lpos = num;
      }
      else {
        if (hand == "right") {
          ans.push_back('R');
          rpos = num;
        } 
        else {
          ans.push_back('L');
          lpos = num;
        }
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