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

int n;
double ans;
int power[4];

vector<vector<int>> match = {
  {0,1},{0,2},{0,3},
  {1,2},{1,3},
  {2,3}
};

bool compare(int a, int b) {
  return a > b;
}

bool canWin(vector<int> score) {
  int s = score[0];
  sort(score.begin(), score.end(), compare);
  // 2등이상일경우
  if (score[1] <= s) return true;
  return false;
}

double win(int a, int b) {
  return (double)4*a / (5*a+5*b);
}

double draw(int a, int b) {
  return (double)(a+b) / (5*a+5*b);
}

double lose(int a, int b) {
  return (double)4*b / (5*a+5*b);
}

void dfs(int depth, vector<int> score, double percent) {
  if (depth == 6) {
    if (canWin(score)) ans += percent;
    return;
  }

  int playerA = match[depth][0];
  int playerB = match[depth][1];
  // 승
  score[playerA] += 3;
  dfs(depth+1, score, percent*win(power[playerA],power[playerB]));
  score[playerA] -= 3;
  // 무승부
  score[playerA] += 1;
  score[playerB] += 1;
  dfs(depth+1, score, percent*draw(power[playerA],power[playerB]));
  score[playerA] -= 1;
  score[playerB] -= 1;
  // 패
  score[playerB] += 3;
  dfs(depth+1, score, percent*lose(power[playerA],power[playerB]));
  score[playerB] -= 3;
}

double solution() {
  dfs(0,{0,0,0,0},100);
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");
  cout << fixed;
  cout.precision(3);

  for (int i=0; i<4; i++){
    cin >> power[i];
  }

  cout << solution();
}