#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  // ifstream cin;
  // cin.open("input.txt");

  int test, n;
  cin >> test;

  while (test--){
    cin >> n;
    vector<int> enemy;
    vector<int> team;
    
    for (int i=0; i<n; i++){
      int a;
      cin >> a;
      enemy.push_back(a);
    }
    for (int i=0; i<n; i++){
      int a;
      cin >> a;
      team.push_back(a);
    }
    
    sort(enemy.begin(), enemy.end());
    sort(team.begin(), team.end());
    
    int ans = 0;
    int esrt=0, tsrt=0;
    for (int i=esrt; i<n; i++){
      for (int j=tsrt; j<n; j++){
        if (team[j] >= enemy[i]){
          ans++;
          tsrt = j+1;
          break;
        }
      }
    }

    cout << ans << endl;  
  }
  
}