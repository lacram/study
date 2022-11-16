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

int solution(vector<int> priorities, int location) {
  int myDoc = priorities[location];

  deque<int> deq(priorities.begin(), priorities.end());
  sort(priorities.begin(), priorities.end(), greater<>());

  int ans = 1;
  int idx = 0;
  int pos = location;
  while (1){
    // 문서 인쇄
    if (deq.front() == priorities[idx]) {
      // 내 문서가 나온경우
      if (myDoc == deq.front() && pos == 0) return ans;
      
      ans++;
      idx++;
      deq.pop_front();
    } 
    // 우선순위가 낮아서 인쇄 밀림
    else {
      // 내 문서 차례지만 우선순위가 낮음, 맨 뒤로 보냄
      if (pos == 0) pos = deq.size();
      
      deq.push_back(deq.front());
      deq.pop_front();
    }
    pos--;
  }
  
  return -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  // solution();

}