#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define endl '\n'
#define INF 2000000000

using namespace std;

int solution(int cacheSize, vector<string> cities) {
  if (cacheSize == 0) return cities.size() * 5;

  set<int> s;
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
  int updated[100001];
  map<string, int> m;

  int ans = 0;
  int idx = 1;
  int cnt = 1;
  int size = 0;

  for (auto city: cities){
    // 소문자로 변환
    for (int i=0; i<city.size(); i++)
      city[i] = tolower(city[i]);
      
    if (!m[city]) m[city] = idx++;

    // cache에 존재
    int cityNum = m[city];
    if (s.find(cityNum) != s.end()){
      updated[cityNum]++;
      ans += 1;
    }
    // cache에 존재 x
    else {
      // 캐시에 여유공간 x
      if (size >= cacheSize){
        while (updated[pq.top().second]){
          updated[pq.top().second]--;
          pq.pop();
        }
        s.erase(pq.top().second);
        pq.pop();
      }
      else {
        size++;
      }

      s.insert(cityNum);
      ans += 5;
    }
    pq.push({cityNum + (long long) 100000*cnt, cityNum});
    cnt++;
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution(0,{"Jeju", "Pangyo", "Seoul", "NewYork", "LA"});

}