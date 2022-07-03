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

// 1. 전체 소문자화
// 2. 영어 단어단위로 끊어 벡터에 저장, https 만날시 " " 전체 저장
// 3. 링크 수 = href 개수
// 4. 기본점수 = target 개수
// 5. 매칭점수 = 기본점수 +

int solution(string word, vector<string> pages) {
  vector<string> links[20];
  vector<string> words[20];
  vector<int> basicScore(20);
  vector<double> linkScore(20);
  vector<double> matchScore(20);
  map<string,int> mapping;

  transform(word.begin(), word.end(), word.begin(), ::tolower);

  int idx = 0;
  for (auto page : pages) {
    transform(page.begin(), page.end(), page.begin(), ::tolower);

    int pos;
    for (int i=0; i<page.size(); i = pos){
      string str = "";
      pos = i;
      while ('a' <= page[pos] && page[pos] <= 'z') {
        str.push_back(page[pos]);
        pos++;
        
        if (str == "https") {
          int pos2 = pos;
          string str2 = str;
          while (page[pos2] != '"') {
            str2.push_back(page[pos2]);
            pos2++;
          }
          links[idx].push_back(str2);
        }
      }
      // 영어 아닐시
      if (pos == i) pos++;

      if (str != "") words[idx].push_back(str);
    }
    idx++;
  }

  for (int i=0; i<pages.size(); i++) {
    int cnt = 0;
    for (auto w : words[i]){
      if (w == word) cnt++;
    }
    basicScore[i] = cnt;

    linkScore[i] = (double) basicScore[i] / (links[i].size()-1);
    // 첫 string이 해당 페이지 링크
    mapping[links[i][0]] = i+1;
  }
  
  
  for (int i=0; i<pages.size(); i++){
    int cnt = 0;
    for (int j=1; j<links[i].size(); j++){
      int mappingIdx = mapping[links[i][j]];
      if (mappingIdx == 0) continue;
      matchScore[mapping[links[i][j]]-1] += linkScore[i];
    }
    matchScore[i] += basicScore[i];
  }

  double maxScore = 0;
  int maxIdx = 0;
  for (int i=0; i<matchScore.size(); i++) {
    if (maxScore < matchScore[i]) {
      maxScore = matchScore[i];
      maxIdx = i;
    }
  }

  return maxIdx;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution(	"blind", {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"});

}