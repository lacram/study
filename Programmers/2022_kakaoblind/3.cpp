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
#include <cmath>
#include <set>
#define endl '\n'
#define INF 2000000000

using namespace std;

/* 
1. records 공백 기준으로 분리 시간,차량번호,출입여부
2. map 두개로 출입시간 기록
3. 번호 작은 순으로 정렬
4. 요금 출력
 */

int getTime(string str) {
  int time = 0;
  time += stoi(str.substr(0,2)) * 60;
  time += stoi(str.substr(3,2));

  return time;
}

// fee 기본 시간(분)	기본 요금(원)	단위 시간(분)	단위 요금(원
vector<int> solution(vector<int> fees, vector<string> records) {
  multimap<string, int> in;
  multimap<string, int> out;
  set<string> tmp;

  for (auto record : records) {
    vector<string> v;
    int pos = 0;
    while ((pos = record.find(" ")) != string::npos) {
      v.push_back(record.substr(0,pos));
      record.erase(0,pos+1);
    }
    v.push_back(record);

    int time = getTime(v[0]);
    string car = v[1];
    string flag = v[2];

    if (flag == "IN") in.insert({car,time});
    else out.insert({car,time});

    tmp.insert(car);
  }

  vector<string> cars(tmp.begin(), tmp.end());
  sort(cars.begin(), cars.end());

  vector<int> ans;
  for (auto car : cars) {
    int cost = 0;
    int spendTime = 0;
    auto fr = in.lower_bound(car);
    auto to = out.lower_bound(car);

    for (; fr != in.upper_bound(car); fr++,to++) {
      if (to == out.upper_bound(car)) {
        spendTime += getTime("23:59")-fr->second;
        break;
      }
      else spendTime += to->second - fr->second;
    }

    // 기본시간 초과
    if (fees[0] < spendTime) {
      cost += fees[1] + ceil(double(spendTime-fees[0]) / fees[2]) * fees[3];
    }
    else cost += fees[1];

    ans.push_back(cost);
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({180, 5000, 10, 600} ,   {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"});

}