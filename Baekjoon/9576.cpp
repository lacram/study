#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int test, n, m;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> test;
  while(test--){
    cin >> n >> m;

    vector<vector<int>> v;
    int hasbook[1001] = {0};
    for (int i=0; i<m; i++){
      int srt, end;
      cin >> srt >> end;
      vector<int> tmp = {srt, end, i};
      v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int ans=0;

    for (int i=1; i<=n; i++){
      int minend=1000, people=-1;
      for (int j=0; j<m; j++){
        if (v[j][0] != i) break;
        if (!hasbook[v[j][2]] && v[j][1]>=v[j][0]){
          // 간격이 좁은순
          if (minend > v[j][1]-v[j][0]){
            minend = v[j][1]-v[j][0];
            people = v[j][2];
          }
        }
        //시작 위치 갱신
        v[j][0]++;
      }
      if (people != -1){
        hasbook[people] = 1;
        ans++;
      }

    }
    
    cout << ans << endl;
  }
}