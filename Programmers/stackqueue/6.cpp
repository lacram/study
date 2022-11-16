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

// value 기준 오름차순 ({value, idx})스택을 만들기
vector<int> solution(vector<int> prices) {
  stack<pair<int,int>> idxs;
  vector<int> ans;
  ans.resize(prices.size());

  for (int i=0; i<prices.size(); i++) {
    
    // 가격이 떨어짐
    while (!idxs.empty() && idxs.top().first > prices[i]) {
      int idx = idxs.top().second;
      ans[idx] = i - idx;
      idxs.pop();
    }

    idxs.push({prices[i],i});
  }

  while(!idxs.empty()) {
    int idx = idxs.top().second;
    ans[idx] = prices.size()-1 - idx;
    idxs.pop();
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