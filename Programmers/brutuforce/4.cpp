#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#define endl '\n'
#define INF 2000000000

using namespace std;

/* 
x,y?
2x + 2y -4 = brown
x = (4-2y+brown)/2
x*y = brown+yellow
 */

vector<int> solution(int brown, int yellow) {
  
  for (int x=1; x<1500; x++) {
    int y = (4+brown-2*x)/2;
    if (y > x || y < 0) continue;

    if (x*y == brown + yellow) return {x,y};
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}