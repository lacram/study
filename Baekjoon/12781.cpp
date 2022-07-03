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

  vec vectors[4];

  for (int i=0; i<4; i++){
    cin >> vectors[i].x;
    cin >> vectors[i].y;
  }
  vec a = vectors[0];
  vec b = vectors[1];
  vec c = vectors[2];
  vec d = vectors[3];

  long long ab = ccw(b-a, d-b) * ccw(b-a, c-b);
  long long cd = ccw(d-c, b-d) * ccw(d-c, a-d);

  if (ab <0 && cd<0) cout << 1;
  else cout << 0;

}