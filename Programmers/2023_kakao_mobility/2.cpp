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
#include <sstream>
#define endl '\n'
#define INF 2000000000

using namespace std;

map<string,int> purchaseCount;

set<string> getClient(string str) {
  set<string> client;
  stringstream ss(str);
  string s;

  while (ss >> s) {
    client.insert(s);
  }

  return client;
}

void addPurchaseCount(string str) {
  set<string> client = getClient(str);

  for (auto c : client) {
    purchaseCount[c]++;
  }
}

int solution(vector<string> id_list, int k) {
  for (auto id : id_list) {
    addPurchaseCount(id);
  }

  int ans = 0;
  for (auto it=purchaseCount.begin(); it!=purchaseCount.end(); it++) {
    int count = it->second;
    if (count > k) ans += k;
    else ans += count;
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  int start = clock();			// 현재 시간 반환
    
  string s = "a b c d e f g h i ";
  for (int i=0; i<9; i++) s += s;
  cout << s.size() << endl;
  s.pop_back();
  vector<string> v;
  for (int i=0; i<1000; i++) v.push_back(s);

  cout << solution(v, 800) << endl;

}