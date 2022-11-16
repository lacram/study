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

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  // 나가는 시간 무게
  vector<pair<int,int>> crossing;
  int totalWeight = 0;
  int time = 0;
  int idx = 0;

  while(1) {
    time++;

    // 하차
    if (!crossing.empty() && crossing[0].first == time) {
      totalWeight -= crossing[0].second;
      crossing.erase(crossing.begin());
    }
  
    if (crossing.empty() && idx == truck_weights.size()) return time;

    // 탑승
    if (idx < truck_weights.size() && totalWeight + truck_weights[idx] <= weight) {
      totalWeight += truck_weights[idx];
      crossing.push_back({time+bridge_length, truck_weights[idx]});
      idx++;
    }

  }
  return -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution(2,10,{7,4,5,6});

}