#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <map>
#define endl '\n'
#define INF 2000000000

using namespace std;

int arr[360000];

int getTime(int srt, string time) {
  int cnt = 0;
  cnt += stoi(time.substr(srt,2)) * 3600;
  cnt += stoi(time.substr(srt+3,2)) * 60;
  cnt += stoi(time.substr(srt+6,2));

  return cnt;
}

string getRealTime(int time) {
  string ans = "";
  int tmp;

  for (auto i : {3600,60,1}) {
    tmp = time / i;
    if (0 <= tmp && tmp <= 9) ans.push_back('0');
    ans += to_string(tmp);
    if (i != 1) ans += ":";
    time %= i;
  }

  return ans;
}

string solution(string play_time, string adv_time, vector<string> logs) {
  // 배열의 크기
  int n = getTime(0,play_time);

  // 구간합의 길이
  int len = getTime(0,adv_time);

  for (auto log : logs) {
    int fr = getTime(0,log)+1;
    int to = getTime(9,log);

    //for (int i=fr; i<=to; i++) arr[i]++;
    arr[fr]++;
    arr[to+1]--;
  }

  for (int i=0; i<n; i++)
    arr[i+1] += arr[i];

  // 최대 구간합 구하기
  long long maxPlayTime = 0;
  long long playTime = 0;
  int minStartTime = 0;

  for (int i=0; i<=len; i++) {
    playTime += arr[i];
  }

  maxPlayTime = playTime;

  for (int i=1; i+len<=n; i++) {
    playTime = playTime-arr[i]+arr[i+len];

    if (maxPlayTime < playTime) {
      maxPlayTime = playTime;
      minStartTime = i;
    }
  }

  return getRealTime(minStartTime);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}