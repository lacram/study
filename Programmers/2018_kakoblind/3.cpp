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
#define endl '\n'
#define INF 2000000000

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
  vector<int> time;
  for (auto t : timetable){
    int num = 0;
    num += stoi(t.substr(0,2))*60 + stoi(t.substr(3,2));
    time.push_back(num);
  }
  sort(time.begin(), time.end());

  // 막차 직전 차까지 사람들 태워 보냄
  int start = 9*60;
  for (int i=0; i<n-1; i++){
    int now = start + t*i;
    int passenger = 0;
    while (time.size() != 0 && time[0] <= now && passenger < m){
      passenger++;
      time.erase(time.begin());
    }
  }
  
  int lastbus = start+t*(n-1);
  int lastman = time[m-1];
  int maxTime;
  // 막차가 마지막 사람보다 빠르거나 막차에 전부 탈 수 있을 때
  if (lastman > lastbus || time.size() < m) maxTime = lastbus;
  else maxTime = lastman-1;

  int hour = maxTime/60;
  int min = maxTime%60;
  string shour = hour < 10 ? "0" + to_string(hour) : to_string(hour);
  string smin = min < 10 ? "0" + to_string(min) : to_string(min);

  return shour + ":" + smin;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution(1, 1, 5, {"08:00", "08:01", "08:02", "08:03"});

}