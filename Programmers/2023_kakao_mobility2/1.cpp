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
#define INF 1000000

using namespace std;

/* 
자동차 - only 자동차만, 0
자전거 - 자전거 or 도보, 1
대중교통 - 대중교통 or 도보, 대중교통 불가지역은 도보, 2
도보 - 연속해서 이동가능 시간 m, 3
 */

vector<int> carTime;
vector<int> bikeTime;
vector<int> publicTime;
vector<int> walkTime;

int car = 0;
int bike = INF;
int pub = INF;
int walk = 0;
int n;

// void getBikeTime(int now, int time, int restWalkTime) {
//   if (now == n) {
//     bike = min(bike, time);
//     return;
//   }

//   // 자전거
//   getBikeTime(now+1, time+bikeTime[now], restWalkTime);
//   // 걷기
//   if (restWalkTime >= walkTime[now]) {
//     getBikeTime(now+1, time+walkTime[now], restWalkTime-walkTime[now]);
//   }
// }

int getBikeTime(int now, int time, int restWalkTime) {
  // 시간, 구간번호, 남은 걷기시간
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
  q.push({0,-1,restWalkTime});

  while (!q.empty()) {
    int now = q.top()[1];
    int time = q.top()[0];
    int restTime = q.top()[2];
    q.pop();

    if (now == n-1) {
      return time;
    }

    int next = now+1;
    // 자전거
    q.push({time+bikeTime[next],next,restWalkTime});
    // 걷기
    if (restWalkTime >= walkTime[next]) {
      q.push({time+walkTime[next],next,restWalkTime-walkTime[next]});
    }
  }
  return INF;
}

// void getPublicTime(int now, int time, int restWalkTime) {
//   if (now == n) {
//     pub = min(pub, time);
//     return;
//   }

//   // 대중교통
//   if (publicTime[now] != -1) {
//     getPublicTime(now+1, time+publicTime[now], restWalkTime);
//   }
//   // 걷기
//   if (restWalkTime >= walkTime[now]) {
//     getPublicTime(now+1, time+walkTime[now], restWalkTime-walkTime[now]);
//   }
// }

int getPublicTime(int now, int time, int restWalkTime) {
  // 시간, 구간번호, 남은 걷기시간
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
  q.push({0,-1,restWalkTime});

  while (!q.empty()) {
    int now = q.top()[1];
    int time = q.top()[0];
    int restTime = q.top()[2];
    q.pop();

    if (now == n-1) {
      return time;
    }

    int next = now+1;
    // 대중교통
    if (publicTime[next] != -1) {
      q.push({time+publicTime[next],next,restWalkTime});
    }
    // 걷기
    if (restWalkTime >= walkTime[next]) {
      q.push({time+walkTime[next],next,restWalkTime-walkTime[next]});
    }
  }
  return INF;
}

int solution(vector<vector<int>> infos, int m) {
  n = infos.size();

  for (auto info : infos) {
    carTime.push_back(info[0]);
    bikeTime.push_back(info[1]);
    publicTime.push_back(info[2]);
    walkTime.push_back(info[3]);
  }

  // 자동차
  for (auto c : carTime) {
    car += c;
  }
  // 자전거
  bike = getBikeTime(-1,0,m);
  // 대중교통
  pub = getPublicTime(-1,0,m);

  for (auto w : walkTime) {
    if (m < w) {
      walk = INF;
      break;
    }
    walk += w;
    m -= w;
  }
  vector<int> ans = {car, bike, pub, walk};
  return *min_element(ans.begin(), ans.end());
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<int> v = {100,100,100,10};
  vector<vector<int>> a;
  for (int i=0; i<20000; i++) {
    a.push_back(v);
  }

  cout << solution(a, 1000);

  // cout << solution({{100,80,10,20}, {100,60,-1,40}}, 30);
}