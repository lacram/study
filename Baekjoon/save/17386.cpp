#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

struct vec{
  long long x,y;

  vec(long long x=0, long long y=0): x(x), y(y){}

  vec operator- (vec p){
    return vec(x-p.x,y-p.y);
  }
  bool operator< (vec p){
    return x == p.x ? y < p.y : x < p.x;
  }
};

int cross(vec p1, vec p2){
  long long ans = p1.x*p2.y - p1.y*p2.x;
  if (ans > 0) return 1;
  else if (ans < 0) return -1;
  return 0;
}

long long ccw(vec p, vec a, vec b){
  return cross(a-p,b-p);
} 

bool intersect(vec a, vec b, vec c, vec d){
  int ab = ccw(a,b,c) * ccw(a,b,d);
  int cd = ccw(c,d,a) * ccw(c,d,b);

  if (ab == 0 && cd == 0){
    if (b < a) swap(a,b);
    if (d < c) swap(c,d);
    return !(b < c || d < a);
  }
  return ab <= 0 && cd <= 0;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  vec p1,p2,p3,p4;

  cin >> p1.x >> p1.y >> p2.x >> p2.y;
  cin >> p3.x >> p3.y >> p4.x >> p4.y;
  
  cout << intersect(p1,p2,p3,p4);
}