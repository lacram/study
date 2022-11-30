#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;

struct vec{
  long long x;
  long long y;

  vec(){};
  vec(int x, int y) : x(x), y(y) {};

  double cross(vec v1){
    return x*v1.y - y*v1.x;
  }
};

vec *vectors;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n;

  vectors = new vec[n-1];
  int a,b,x,y;

  cin >> a >> b;

  for (int i=0; i<n-1; i++){
    cin >> x >> y;
    vectors[i].x = x-a;
    vectors[i].y = y-b;
  }

  double ans=0;

  for (int i=0; i<n-2; i++){
    ans += vectors[i].cross(vectors[i+1]);
  }

  cout << fixed;
  cout.precision(1);

  cout << abs(ans)/2;
}