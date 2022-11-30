#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int total, win;

int winrate(long long t, long long w){
  return (w*100)/t;
}

bool decision(int game){
  return winrate(total,win) != winrate(total+game, win+game);
}

int solve(){
  if (winrate(total,win) >= 99) return -1;

  int lo=0;
  int hi=1000000000;
  while (lo <= hi){
    int mid = (lo+hi)/2;

    if(decision(mid)) hi=mid-1;
    else lo=mid+1;
  }

  return lo;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> total >> win;

  cout << solve();

}