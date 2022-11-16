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

// 종류별로 갯수 + 1(선택안하는 경우도 포함), 각각 곱한후 모두 선택 안한 경우(1) 빼주면 됨
int solution(vector<vector<string>> clothes) {
  map<string,int> m;
  
  for (auto cloth : clothes) {
    m[cloth[1]]++;
  }

  int ans = 1;
  for (map<string,int>::iterator it = m.begin(); it != m.end(); it++) {
    ans *= it->second+1
  }
  return ans-1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

} 