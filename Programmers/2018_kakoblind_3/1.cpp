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

// A# C# D# F# G#
string solution(string m, vector<string> musicinfos) {
  vector<string> v = {"A#","C#","D#","F#","G#"};
  map<string,string> mapping = {
    {"A#", "1"},
    {"C#", "2"},
    {"D#", "3"},
    {"F#", "4"},
    {"G#", "5"}
  };
  // play시간, 입력된 순서, 곡 제목
  vector<pair<pair<int,int>, string>> ans;
  
  for (auto a: v){
    while (m.find(a) != string::npos){
      m.replace(m.find(a), 2, mapping[a]);
    }
  }
  
  int seq = musicinfos.size();
  for (auto musicinfo : musicinfos){
    vector<string> words;

    int pos = 0;
    while ((pos = musicinfo.find(",")) != string::npos)
    {
      words.push_back(musicinfo.substr(0, pos));
      musicinfo.erase(0, pos + 1);
    }

    string stime = words[0];
    string etime = words[1];
    string name = words[2];
    string song = musicinfo;

    for (auto a: v){
    while (song.find(a) != string::npos){
      song.replace(song.find(a), 2, mapping[a]);
    }
  }
    
    int start = stoi(words[0].substr(0,2)) * 60 + stoi(words[0].substr(3,2));
    int end = stoi(words[1].substr(0,2)) * 60 + stoi(words[1].substr(3,2));
    int play = end-start;

    string melody = "";
    for (int i=0; i<=play / song.size(); i++) 
      melody += song;
    
    melody = melody.substr(0,play);

    if (melody.find(m) != string::npos)
      ans.push_back({{play, seq},name});

    seq--;
  }
  
  if (ans.empty()) return "(None)";

  sort(ans.begin(), ans.end(), greater<>());
  return ans[0].second;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");
  cout << solution("CC#BCC#BCC#BCC#B",	{"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"});

}