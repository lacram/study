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

vector<int> com;

bool check(vector<int> tmp) {
  for (int i=0; i<tmp.size(); i++) {
    if (tmp[i] != com[i]) {
      return false;
    }
  }
  return true;
}

int solution(string skill, vector<string> skill_trees) {
  int ans = 0;
  for (int i=0; i<26; i++) {
    com.push_back(i);
  }

  for (auto skill_tree : skill_trees) {
    vector<int> tmp;
    for (int i=0; i<skill_tree.size(); i++) {
      for (int j=0; j<skill.size(); j++)
        if (skill_tree[i] == skill[j]) {
          tmp.push_back(j);
        }
    }
    if (check(tmp)) {
      ans++;
    }
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