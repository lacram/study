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

bool compare(pair<int,int> p1, pair<int,int> p2) {
  return p1.second > p2.second;
}

bool compare2(vector<int> v1, vector<int> v2) {
  if (v1[0] == v2[0]) return v1[1] < v2[1];
  return v1[0] > v2[0]; 
}

vector<int> solution(vector<string> genres, vector<int> plays) {
  // 장르 idx별
  // {곡 재생수, idx}
  // map을 사용할 때 0번 idx는 사용하지 않는 편이 좋음.
  vector<vector<vector<int>>> arr(100);
  arr[0] = {{0,0}};
  // 장르별 총 재생수 저장
  map<int,int> totalCnt;
  // 장르 -> idx
  map<string,int> mapping;

  int idx = 1;
  for (int i=0; i<genres.size(); i++){
    string genre = genres[i];
    int play = plays[i];

    // 해당 장르가 처음 나옴
    if (mapping[genre] == 0) {
      mapping[genre] = idx++;
    }

    totalCnt[mapping[genre]] += play;
    arr[mapping[genre]].push_back({play, i});
  }

  vector<pair<int,int>> vtotalCnt(totalCnt.begin(), totalCnt.end());

  sort(vtotalCnt.begin(), vtotalCnt.end(), compare);

  vector<int> ans;
  for (auto v : vtotalCnt) {
    int genreIdx = v.first;
    sort(arr[genreIdx].begin(), arr[genreIdx].end(), compare2);
    // 장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
    for (int i=0; i<2 && i < arr[genreIdx].size(); i++) {
      ans.push_back(arr[genreIdx][i][1]);
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

  solution({"classic", "pop", "classic", "classic", "pop"}, {500, 600, 150, 800, 2500});

}