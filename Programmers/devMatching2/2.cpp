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

/* 
1. 더많은 코스 완주
2. 완주한 가장 어려운 코스, 5번이 가장 어려움
3. 1/12 금, 1/4 은, 1/2 동, 소수점 첫째 자리 올림, 메달수가 많을수록
4. 완주시간의 합이 더 적을수록
5. 이름이 사전순으로 빠른순
 */

struct total{
  int completedCourse;
  int hardestCourse;
  vector<int> prize;
  int totalTime;
  string name;
};

struct player {
  string name;
  vector<int> times;
  vector<int> prizes = {0,0,0};

  void getPlayer(string str) {
    int pos = str.find(':');
    string name = str.substr(0,pos);
    str = str.substr(pos+1);
    
    vector<int> times;
    while ((pos = str.find(',')) != string::npos) {
      if ((str.substr(0,pos)) != "0") times.push_back(stoi(str.substr(0,pos)));
      else times.push_back(INF);
      str = str.substr(pos+1);
    }
    if (str == "0") times.push_back(INF);
    else times.push_back(stoi(str));

    this->name = name;
    this->times = times;
  }
};

bool compare1(player p1, player p2) {
  return p1.times[0] < p2.times[0];
}

bool compare2(player p1, player p2) {
  return p1.times[1] < p2.times[1];
}

bool compare3(player p1, player p2) {
  return p1.times[2] < p2.times[2];
}

bool compare4(player p1, player p2) {
  return p1.times[3] < p2.times[3];
}

bool compare5(player p1, player p2) {
  return p1.times[4] < p2.times[4];
}

/* 
1. 더많은 코스 완주
2. 완주한 가장 어려운 코스, 5번이 가장 어려움
3. 1/12 금, 1/4 은, 1/2 동, 소수점 첫째 자리 올림, 메달수가 많을수록
4. 완주시간의 합이 더 적을수록
5. 이름이 사전순으로 빠른순
 */

vector<int> getPrizeLimit(int completed) {
  int a = ceil((double) completed / 12);
  int b = ceil((double) completed / 4);
  int c = ceil((double) completed / 2);
  
  return {a,b,c};
}

vector<player> players;
vector<total> totals;

void updatePrize(vector<int> prizeLimit) {
  for (int i=0; i<players.size(); i++) {
    if (i < prizeLimit[0]) players[i].prizes[0]++;
    else if (i < prizeLimit[1]) players[i].prizes[1]++;
    else if (i < prizeLimit[2]) players[i].prizes[2]++;
    else return;
  }
}

bool check(vector<int> v1, vector<int> v2) {
  if (v1[0] != v2[0]) return false;
  if (v1[1] != v2[1]) return false;
  if (v1[2] != v2[2]) return false;
  return true;
}

bool comparePrize(vector<int> v1, vector<int> v2) {
  if (v1[0] == v2[0]) {
    if (v1[1] == v2[1]) {
      return v1[2] > v2[2];
    }
    return v1[1] > v2[1];
  }
  return v1[0] > v2[0];
}

bool compare(total t1, total t2) {
  if (t1.completedCourse == t2.completedCourse) {
    if (t1.hardestCourse == t2.hardestCourse) {
      if (check(t1.prize, t2.prize)) {
        if (t1.totalTime == t2.totalTime) {
          return t1.name < t2.name;
        }
        return t1.totalTime < t2.totalTime;
      }
      return comparePrize(t1.prize, t2.prize);
    }
    return t1.hardestCourse > t2.hardestCourse;
  }
  return t1.completedCourse > t2.completedCourse;
}

vector<string> solution(vector<string> record) {

  vector<int> completedCount(5);

  for (auto r : record) {
    player p;
    p.getPlayer(r);
    players.push_back(p);
  }

  for (auto p : players) {
    for (int i=0; i<p.times.size(); i++) {
      if (p.times[i] != INF) {
        completedCount[i]++;
      }
    }
  }

  sort(players.begin(), players.end(), compare1);
  vector<int> prizeLimit = getPrizeLimit(completedCount[0]);
  updatePrize(prizeLimit);
  sort(players.begin(), players.end(), compare2);
  prizeLimit = getPrizeLimit(completedCount[1]);
  updatePrize(prizeLimit);
  sort(players.begin(), players.end(), compare3);
  prizeLimit = getPrizeLimit(completedCount[2]);
  updatePrize(prizeLimit);
  sort(players.begin(), players.end(), compare4);
  prizeLimit = getPrizeLimit(completedCount[3]);
  updatePrize(prizeLimit);
  sort(players.begin(), players.end(), compare5);
  prizeLimit = getPrizeLimit(completedCount[4]);
  updatePrize(prizeLimit);

  for (auto p : players) {
    int completedCourse = 0;
    int hardestCourse = 0;
    int totalTime = 0;
    for (int i=0; i<p.times.size(); i++) {
      if (p.times[i] != INF) {
        completedCourse++;
        hardestCourse = i;
        totalTime += p.times[i];
      }
    }
    total t;
    t.completedCourse = completedCourse;
    t.hardestCourse = hardestCourse;
    t.prize = p.prizes;
    t.totalTime = totalTime;
    t.name = p.name;
    totals.push_back(t);
  }
  
  sort(totals.begin(), totals.end(), compare);
  vector<string> ans;
  for (auto t : totals) {
    ans.push_back(t.name);
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({"jack:9,10,13,9,15","jerry:7,7,14,10,17","jean:0,0,11,20,0", "alex:21,2,7,11,4","kevin:8,4,5,0,0","brown:3,5,16,3,18", "ted:0,8,0,0,8","lala:0,12,0,7,9","hue:17,16,8,6,10","elsa:11,13,10,4,13"} );

}