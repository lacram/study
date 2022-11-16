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
1. 12345
2. 21232425
3. 3311224455
 */

int first[5] = {1,2,3,4,5};
int second[8] = {2,1,2,3,2,4,2,5};
int third[10] = {3,3,1,1,2,2,4,4,5,5};

bool compare(pair<int,int> p1, pair<int,int> p2) {
  return p1.second > p2.second;
}

vector<int> solution(vector<int> answers) {
  vector<int> scores(3);
  
  for (int i=0; i<answers.size(); i++) {
    // 1번
    if (answers[i] == first[i%5]) scores[0]++;
    // 2번
    if (answers[i] == second[i%8]) scores[1]++;
    // 3번
    if (answers[i] == third[i%10]) scores[2]++;
  }
  
  vector<pair<int,int>> v;
  int idx = 1;
  int maxScore = 0;
  for (auto score : scores) {
    v.push_back({idx++, score});
    maxScore = max(maxScore, score);
  }

  sort(v.begin(), v.end(), compare);

  vector<int> ans;
  for (auto a : v) {
    if (a.second == maxScore) ans.push_back(a.first);
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