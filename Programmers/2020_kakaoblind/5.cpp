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

vector<vector<int>> ans;

bool find(int x, int y, int a) {
  for (auto an :ans)
    if (an[0] == x && an[1] == y && an[2] == a) return true;
  return false;
}

void del(int x, int y, int a) {
  for (auto it = ans.begin(); it != ans.end(); it++)
    if ((*it)[0] == x && (*it)[1] == y && (*it)[2] == a) {
      ans.erase(it);
      return; 
    }
}

bool canBuild(int x, int y, int a) {
  if (a) return find(x,y-1,0) || find(x+1,y-1,0) || (find(x-1,y,1) && find(x+1,y,1));
  else return !y || find(x,y-1,0) || find(x-1,y,1) || find(x,y,1);
}

// 1. 기둥인지 보인지 구분
// 2. 설치 인지 삭제인지 구분
// 3. 가능하다면 해당 명령 실행
// 가로, 세로, 구조물 종류 기둥 : 0, 보 :1, 0 삭제, 1 설치
void check(int x, int y, int a, int b, int n) {
  // 보
  if (a) {
    // 설치
    if (b) {
      // 보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
      if (canBuild(x,y,a)) ans.push_back({x,y,a});
    }
    // 삭제
    else {
      del(x,y,a);
      // 영향 받는 기둥또는 보
      vector<vector<int>> affected = {{x-1,y,1},{x+1,y,1},{x,y,0},{x+1,y,0}};
      for (auto aff : affected) {
        int X = aff[0];
        int Y = aff[1];
        int A = aff[2];
        if (find(X,Y,A)) {
          if (!canBuild(X,Y,A)) {
            ans.push_back({x,y,a});
            return;
          }
        }
      }
    }
  }
  // 기둥
  else {
    // 설치
    if (b) {
      // 기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
      if (canBuild(x,y,a)) ans.push_back({x,y,a});
    }
    // 삭제
    else {
      del(x,y,a);
      // 영향 받는 기둥또는 보
      vector<vector<int>> affected = {{x-1,y+1,1},{x,y+1,1},{x,y+1,0}};
      for (auto aff : affected) {
        int X = aff[0];
        int Y = aff[1];
        int A = aff[2];
        if (find(X,Y,A)) {
          if (!canBuild(X,Y,A)) {
            ans.push_back({x,y,a});
            return;
          }
        }
      }
    }
  }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
  for (auto build : build_frame) {
    check(build[0],build[1],build[2],build[3],n);
  }

  sort(ans.begin(), ans.end());

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution();

}