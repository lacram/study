#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#define endl '\n'

using namespace std;

int p1x,p1y;
int p2x,p2y;
int p3x,p3y;

struct vec{
  int x;
  int y;

  vec(int x, int y) : x(x), y(y) {};

  vec operator- (vec v){
    return vec(x-v.x, y-v.y);
  }
};

int solve(vec v1, vec v2){
  int ret = v1.x * v2.y - v1.y * v2.x;
  if (ret > 0) return 1;
  else if (ret < 0) return -1;
  return 0;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> p1x >> p1y;
  cin >> p2x >> p2y;
  cin >> p3x >> p3y;
  
  vec p1(p1x,p1y);
  vec p2(p2x,p2y);
  vec p3(p3x,p3y);

  cout << solve(p2-p1,p3-p2);
}