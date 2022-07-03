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

int solution(int n, vector<int> weak, vector<int> dist) {

  int ans = INF;
  
  int w = weak.size();
  for (int i=0; i<w; i++) {
    weak.push_back(weak[i]+n);
  }

  sort(dist.begin(), dist.end());

  do {
    for (int i=0; i<weak.size()/2; i++) {
      // srt~end 를 커버하면 성공
      int srt = weak[i];
      int end = weak[i+weak.size()/2-1];

      for (int j=0; j<dist.size(); j++) {
        int now = srt + dist[j];
        if (now >= end) {
          ans = min(ans, j+1);
          break;
        }
        srt = weak[upper_bound(weak.begin(), weak.end(), now)-weak.begin()];
      }
    }

  }while(next_permutation(dist.begin(), dist.end()));

  return ans == INF ? -1 : ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution();

}