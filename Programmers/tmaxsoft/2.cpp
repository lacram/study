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

stack<pair<int,int>> st[101];
int banned[101];

/* 
// 사람, 재화 
pair<int,int>로 stack 보관
 */

void doTransaction(vector<int> transaction) {
  int fr = transaction[0];
  int to = transaction[1];
  int cost = transaction[2];
  // 마지막 재화보다 클 경우
  while (st[fr].top().second <= cost) {
    st[to].push(st[fr].top());
    cost -= st[fr].top().second;
    st[fr].pop();
    if (cost == 0) return;
  }
  
  // 마지막 재화보다 작을 경우
  int user = st[fr].top().first;
  int money = st[fr].top().second;
  st[fr].pop();
  st[fr].push({user,money-cost});
  st[to].push({user,cost});
}

int getTotal(int user) {
  int total = 0;
  while (!st[user].empty()) {
    int u = st[user].top().first;
    int money = st[user].top().second;

    if (!banned[u]) total += money;
    st[user].pop();
  }
  return total;
}

vector<int> solution(vector<int> balance, vector<vector<int>> transaction, vector<int> abnormal) {
  // 초기 자금
  for (int i=0; i<balance.size(); i++) {
    st[i+1].push({i+1, balance[i]});                                          
  }

  for (auto user : abnormal) {
    banned[user] = 1;
  }

  for (auto trans : transaction) {
    doTransaction(trans);
  }
  
  vector<int> ans;
  for (int i=1; i<=balance.size(); i++) {
    ans.push_back(getTotal(i));
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<int> a =  solution({30, 30, 30, 30},{{1, 2, 10} ,{2, 3, 20}, {3, 4, 5}, {3, 4, 30}},{1});

  for (auto b : a) {
    cout << b << endl;
  }
}