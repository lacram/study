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
그룹별로 모으기
그룹수가 가장 큰 두 그룹 곱하기
 */

vector<int> groupCnt;
int visited[101];
vector<int> cards;

int solution(vector<int> c) {
  cards = c;
  // idx와 맞춰주기 위함
  for (int i=0; i<cards.size(); i++) {
    cards[i]--;
  }

  for (int i=0; i<cards.size(); i++) {
    int val = i;
    int cnt = 0;
    while (!visited[val]) {
      visited[val] = 1;
      val = cards[val];
      cnt++;
    }
    groupCnt.push_back(cnt);
  }

  sort(groupCnt.begin(), groupCnt.end(), greater<>());
  return groupCnt[0] * groupCnt[1];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}