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

long long getAns(priority_queue<int> pq) {
  long long ans = 0;
  while (!pq.empty()) {
    ans += pow(pq.top(),2);
    pq.pop();
  }
  return ans;
}

long long solution(int n, vector<int> works) {
  
  priority_queue<int> pq;
  for (auto work: works) {
    pq.push(work);
  }

  while (!pq.empty() && n--) {
    int num = pq.top();
    pq.pop();
    if (num) pq.push(num-1);
  }

  return getAns(pq);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution(4,{4,3,3});

}