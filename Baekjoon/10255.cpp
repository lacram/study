#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#define endl '\n'

using namespace std;

struct vec{
  long long x;
  long long y;

  vec(){};
  vec(long long x, long long y): x(x), y(y) {};

  vec operator- (vec v){
    return vec(x-v.x, y-v.y);
  }
  bool operator== (vec v){
    return x == v.x && y ==v.y;
  }
};

long long ccw(vec v1, vec v2){
  return v1.x*v2.y - v1.y*v2.x;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int t,xmin,ymin,xmax,ymax;
  int x1,y1,x2,y2;

  cin >> t;

  while(t--){
    
    cin >> xmin >> ymin >> xmax >> ymax;
    cin >> x1 >> y1 >> x2 >> y2;

    vec squarev[5];
    vec linev[2];

    squarev[0].x = xmin;
    squarev[0].y = ymin;
    squarev[1].x = xmin;
    squarev[1].y = ymax;
    squarev[2].x = xmax;
    squarev[2].y = ymax;
    squarev[3].x = xmax;
    squarev[3].y = ymin;
    squarev[4].x = xmin;
    squarev[4].y = ymin;

    linev[0].x = x1;
    linev[0].y = y1;
    linev[1].x = x2;
    linev[1].y = y2;

    double cnt = 0;

    for (int i=0; i<4; i++){
      long long x = ccw(linev[1]-linev[0], squarev[i]-linev[1])*ccw(linev[1]-linev[0], squarev[i+1]-linev[1]);
      long long y = ccw(squarev[i+1]-squarev[i], linev[1]-squarev[i+1])*ccw(squarev[i+1]-squarev[i], linev[0]-squarev[i+1]);

      if (x==0 && y==0) {
        if (linev[1].y-linev[0].y == 0 && squarev[i+1].y-squarev[i].y == 0){
          cnt = 4;
          break;
        }
        if ((linev[1].y != linev[0].y && squarev[i+1].y != squarev[i].y) && (linev[1].x-linev[0].x)/(linev[1].y-linev[0].y) == (squarev[i+1].x-squarev[i].x)/(squarev[i+1].y-squarev[i].y)){
          cnt = 4;
          break;
        }
        cnt += 0.5;
      }
      if (x==0 && y<0) cnt += 0.5;
      if (x<0 && y==0) cnt += 1;
      if (x<0 && y<0) cnt++;
    }

    cout << (int)cnt << endl;

  }
}