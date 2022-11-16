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

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> times;

  for (int i=0; i<speeds.size(); i++) {
    times.push_back(ceil(double(100 - progresses[i])/speeds[i]));
  }

  int last = times[0];
  vector<int> ans;
  int cnt = 1;
  for (int i=1; i<times.size(); i++){
    if (times[i] > last) {
      ans.push_back(cnt);
      cnt = 1;
      last = times[i];
    } else {
      cnt++;
    }
  }
  ans.push_back(cnt);

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