#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#define endl '\n'
#define INF 2000000000
typedef long long ll;

using namespace std;
/* 
1. 원하는 방을 입력했을 때 배정될 방을 출력하는 함수
*/
unordered_map<ll,ll> parent;

ll find(ll u) {
  if (parent[u] == 0) return parent[u] = u;
  return parent[u] = find(parent[u]);
}

ll getRoom(ll want) {
  ll ans = find(want);
  parent[ans] = ans+1;
  return ans;
}

vector<long long> solution(long long k, vector<long long> room_number) {

  vector<ll> ans;
  for (int i=0; i<room_number.size(); i++) {
    ans.push_back(getRoom(room_number[i]));
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution(10, {1, 3, 4, 1, 3, 1});

}