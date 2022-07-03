#include <iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> clk(16);
const int INF=9999;
int switchs[10][5]={
  {0,1,2,-1,-1},
  {3,7,9,11,-1},
  {4,10,14,15,-1},
  {0,4,5,6,7},
  {6,7,8,10,12},
  {0,2,14,15,-1},
  {3,14,15,-1,-1},
  {4,5,7,14,15},
  {1, 2, 3, 4, 5},
  {3, 4, 5, 9, 13}
};
void clickswit(int n){
  for(int i=0; i<sizeof(switchs[10])/4;i++)
    if(switchs[n][i] != -1){
      clk[switchs[n][i]] += 3;
      if(clk[switchs[n][i]] == 15)
        clk[switchs[n][i]] = 3;
    }
}
bool areAligned(){
  for(auto it : clk){
    if(it != 12){
      return false;
    }
  }
  return true;
}
int solve(int n){
  if(n == 10)
    return areAligned() ? 0 : INF;

  int ret = INF;

  for(int cnt=0; cnt<4; cnt++){
    ret = min(ret, solve(n+1) + cnt);

    clickswit(n);
  }
  return ret;
}

int main(){
    int test_case;
    cin >> test_case;
    while(test_case--){
      clk.clear();
        for(int i=0;i<16;i++){
          cin >> clk[i];
        }

        int result = solve(0);
        cout << (result == INF ? -1 : result) << endl;
    }
}
////////////////////////////////// Self
#include <iostream>
#include<vector>
#include<cstring>
using namespace std;

int clocks[16];
int INF=9999;
int ret;
int swit[10]={0};
int switchs[10][5]={
  {0,1,2,-1,-1},
  {3,7,9,11,-1},
  {4,10,14,15,-1},
  {0,4,5,6,7},
  {6,7,8,10,12},
  {0,2,14,15,-1},
  {3,14,15,-1,-1},
  {4,5,7,14,15},
  {1, 2, 3, 4, 5},
  {3, 4, 5, 9, 13}
};
void clickswit(int n, int a){
  for(int i=0; i<sizeof(switchs[10])/4;i++)
    if(switchs[n][i] != -1)
      clocks[switchs[n][i]] += a;
  swit[n]+=a/3;
}
void setclocks(int cnt,int x){
  int clk=-1;
  for(int i=0; i<16; i++) 
    if(clocks[i]%12 !=0){
      clk=i;
      break;
    }
  if(clk == -1) {
    ret = min(ret, cnt);
    return;
  }

  for(int i=x; i<10; i++){
    if (swit[i] < 4){
      clickswit(i,3);
      setclocks(cnt+1,i);
      clickswit(i,-3);
    }   
  }
}

int main(){
  int test;
  cin >> test;

  while(test--){
    int i = 16;
    while(i--){
      cin >> clocks[15-i];
    }
    memset(swit, 0, sizeof(swit));
    ret = INF;

    setclocks(0,0);
    if (ret != INF) cout << ret << endl;
    else cout << -1 << endl;
  }
  
}
