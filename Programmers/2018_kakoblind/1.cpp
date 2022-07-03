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

int solution(vector<string> lines) {
  vector<pair<int,int>> times;
    
  for (auto line : lines){
    int endtime = 0;
    endtime += stoi(line.substr(11,2)) * 60 * 60 * 1000;
    endtime += stoi(line.substr(14,2)) * 60 * 1000;
    endtime += stoi(line.substr(17,2)) * 1000;
    endtime += stoi(line.substr(20,3));

    string splaytime = line.substr(24);
    // 1.05s 에서 s 제거
    splaytime.pop_back();

    int playtime = stod(splaytime)*1000;
    int starttime = endtime - playtime + 1;

    times.push_back({starttime,endtime});
  }

  int ans = 0;

  for (int i=0; i<times.size(); i++){
    vector<int> srt(2);
    srt[0]= times[i].first;
    srt[1] = times[i].second;
    
    vector<int> cnt(2,1);

    for (int j=0; j<times.size(); j++){
      if (i == j) continue;

      for (int k=0; k<2; k++){
        if (srt[k] <= times[j].second && times[j].first <= srt[k]+999) 
          cnt[k]++;
      }
    }

    for (int k=0; k<2; k++){
      ans = max(ans,cnt[k]); 
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

  cout << solution({"2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"});

}