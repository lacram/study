#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

int n;
int ans=0;
int diagoanlL[29]={0};
int diagoanlR[29]={0};
int ypos[15]={0};

void solve(int x){
  if (x == n) {
    ans++;
    return;
  }
  // y좌표만 움직이기
  for (int i=0; i<n; i++)
    if (!ypos[i] && !diagoanlL[x-i+14] && !diagoanlR[x+i]){
      ypos[i] = 1;
      diagoanlR[x+i]=1;
      diagoanlL[x-i+14]=1;
      solve(x+1);
      ypos[i] = 0;
      diagoanlR[x+i]=0;
      diagoanlL[x-i+14]=0;
    }
        
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  solve(0);

  cout << ans;
  
}