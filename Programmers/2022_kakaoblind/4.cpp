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
#define endl '\n'
#define INF 2000000000

using namespace std;

/* 
1. 모든 조합을 다 계산 
2. 가장 큰 점수 차이일 경우를 문자열로 배열에 저장
3. 문자열을 뒤집어 가장 큰 숫자가 정답
 */


vector<string> combi;

// 남은 숫자 n중에 0~n선택해 추가
void getCombi(int n, string str) {
  if (str.size() > 11) return;

  if (n == 0) {
    while (str.size() < 11) 
      str.push_back('0');
    
    combi.push_back(str);
    return;
  }

  for (int i=0; i<=n; i++) {
    str.push_back(i+'0');
    getCombi(n-i, str);
    str.pop_back();
  }
}

vector<int> solution(int n, vector<int> info) {

  getCombi(n,"");

  vector<string> maxCombi;
  int maxDiff = 0;
  for (auto com : combi) {
    int scoreA = 0;
    int scoreB = 0;

    for (int i=0; i<11; i++) {
      int cntA = info[i];
      int cntB = com[i]-'0';
      
      // 둘다 해당 점수를 맞춘경우
      if (cntA && cntB) {
        if (cntB > cntA) scoreB += (10-i);
        else scoreA += (10-i);
      } 
      else{
        if (cntA) scoreA += (10-i);
        if (cntB) scoreB += (10-i);
      }
    }
    int diff = scoreB - scoreA;
    
    if (maxDiff < diff) {
      maxDiff = diff;
      maxCombi.clear();
      maxCombi.push_back(com);
    }
    else if (maxDiff == diff) {
      maxCombi.push_back(com);
    }
  }

  if (maxDiff == 0) return {-1};

  long long maxNum = 0;
  string maxStr;
  for (auto com : maxCombi) {
    reverse(com.begin(), com.end());
    if (maxNum < stoll(com)) {
      maxNum = stoll(com);
      maxStr = com;
    }
  }

  vector<int> answer;
  for (auto a : maxStr) 
    answer.insert(answer.begin(), a-'0');

  return answer;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<int> v = solution(10	, {0,0,0,0,0,0,0,0,3,4,3});

  for (auto a : v) cout << a;

}