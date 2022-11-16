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

int ans;
vector<int> numbers;
int target;

void dfs(int depth, int res) {
  if (depth == numbers.size()) {
    if (res == target) ans++;
    return;
  }
  
  dfs(depth+1, res+numbers[depth]);
  dfs(depth+1, res-numbers[depth]);
}

int solution(vector<int> n, int t) {
  numbers = n;
  target = t;

  dfs(0,0);

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