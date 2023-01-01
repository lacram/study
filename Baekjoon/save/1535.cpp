#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int happys[20];
int healths[20];
int n;

int solve(int health, int srt){

  int ret = 0;
  for (int i=srt; i<n; i++){
    if(health > healths[i]){
      ret = max(ret, solve(health-healths[i], i+1)+happys[i]);
    }
  }
  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  // ifstream cin;
  // cin.open("test.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> healths[i];
  }
  for (int i=0; i<n; i++){
    cin >> happys[i];
  }
    
  cout << solve(100,0);

  
}