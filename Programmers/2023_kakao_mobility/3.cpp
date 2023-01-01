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
1초   - 1
1분   - 60
1시간 - 60 * 60
1일   - 60 * 60 * 24
1월   - 60 * 60 * 24 * 30
1년   - 60 * 60 * 24 * 30 * 12

 */

long long YEAR = 60 * 60 * 24 * 30 * 12;
long long MONTH = 60 * 60 * 24 * 30;
long long DAY = 60 * 60 * 24;
long long HOUR = 60 * 60;
long long MINUTE = 60;
long long SECOND = 1;

long long getTimeFromYear(string s) {
  string a = s.substr(0,4);
  long long year = stoi(s.substr(0,4)) * YEAR;
  long long month = stoi(s.substr(5,2)) * MONTH;
  long long day = stoi(s.substr(8,2)) * DAY;
  long long hour = stoi(s.substr(11,2)) * HOUR;
  long long minute = stoi(s.substr(14,2)) * MINUTE;
  long long second = stoi(s.substr(17,2)) * SECOND;
  
  return year + month + day + hour + minute + second;
}

long long getTimeFromDay(string s) {
  long long day = stoi(s.substr(0,2)) * DAY;
  long long hour = stoi(s.substr(3,2)) * HOUR;
  long long minute = stoi(s.substr(6,2)) * MINUTE;
  long long second = stoi(s.substr(9,2)) * SECOND;
  
  return day + hour + minute + second;
}

bool isConsecutive(vector<int> days) {
  int before = days.front()-1;
  for (auto day : days) {
    if (day != before + 1) return false;
    before = day;
  }
  return true;
}

vector<int> solution(string s, vector<string> times) {
  vector<long long> seconds = {getTimeFromYear(s)};
  for (auto time : times)  {
    seconds.push_back(seconds.back()+getTimeFromDay(time));
  }

  set<int> tmp;
  for (auto second : seconds) {
    tmp.insert(second / DAY);
  }
  vector<int> days(tmp.begin(), tmp.end());
  
  return {isConsecutive(days), days.back() - days.front() + 1};
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<int> v= solution("2021:04:00:00:00:00",	{"00:12:00:00", "00:11:00:00", "01:00:00:00", "01:00:00:00"});

  for (auto a : v) {
    cout << a << endl;
  }

}