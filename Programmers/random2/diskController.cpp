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

int solution(vector<vector<int>> jobs) {
  sort(jobs.begin(), jobs.end());

  int i = 0;
  int time = 0;
  int totalTime = 0;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
  for (int j=0; j<jobs.size(); j++) {

    while (i < jobs.size() && jobs[i][0] <= time) {
      q.push({jobs[i][1], jobs[i][0]});
      i++;
    }

    if (!q.empty()) {
      time += q.top().first;
      totalTime += time - q.top().second;
      q.pop();
    } else {
      time = jobs[i][0];
      j--;
    }
  }

  return totalTime / jobs.size();
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution({{0, 3}, {1, 9}, {2, 6}, {30, 3}} );

}