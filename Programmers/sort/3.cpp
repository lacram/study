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

int solution(vector<int> citations) {
  sort(citations.begin(), citations.end(), greater<>());

  int ans = 0;
  for (int i=0; i<citations.size(); i++) {
    int tmp = min(citations[i], i+1);
    ans = max(ans, tmp);
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