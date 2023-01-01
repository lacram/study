#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#define endl '\n'
#define INF 2000000000

using namespace std;

/* 
1. qr코드 별로 4방향 회전 결과 저장
2. 각각 유사도 비교해 최댓값 저장
3. 많은 qr코드 사용한 경우 추리기
4. 이어붙인 숫자가 최소인 경우 찾기
 */

vector<vector<string>> rotatedQR[16];
double similarity[16][16];
vector<vector<char>> options;

// (x,y) - > (y,n-x)
vector<string> rotate(vector<string> qr) {
  vector<string> tmp(6, "      ");
  for (int i=0; i<6; i++)
    for (int j=0; j<6; j++) {
      tmp[i][j] = qr[j][5-i];
    }
  return tmp;
}

void setRotatedQR(vector<vector<string>> qr) {
  for (int i=0; i<qr.size(); i++) {
    vector<string> qrcode = qr[i];
    rotatedQR[i+1].push_back(qrcode);
    for (int j=0; j<3; j++) {
      qrcode = rotate(qrcode);
      rotatedQR[i+1].push_back(qrcode);
    }
  }
}

double getSimilarity(vector<string> a, vector<string> b) {
  int count = 0;
  for (int i=0; i<6; i++)
    for (int j=0; j<6; j++) {
      if (a[i][j] == b[i][j]) {
        count++;
      }
    }
  return (double) count / 36 * 100;
}

void setSimilarity(int n) {
  for (int i=1; i<=n; i++)
    for (int j=i+1; j<=n; j++) {
      // 각각 4방향 회전하여 비교
      double res = 0;
      for (int k=0; k<4; k++)
        for (int t=0; t<4; t++) {
          res = max(res, getSimilarity(rotatedQR[i][k], rotatedQR[j][t]));
        }
      similarity[i][j] = res;
      similarity[j][i] = res;
    }
}

bool canIN(vector<char> v, int n) {
  for (auto a : v) {
    if (similarity[a-'0'][n] > 50) return false;
  }
  return true;
}

void getOptions(int n) {
  for (int i=1; i<=n; i++){
    vector<char> v;
    v.push_back(i+'0');
    for (int j=i+1; j<=n; j++) {
      if (canIN(v,j)) v.push_back(j+'0');
    }
    options.push_back(v);
  }
}

bool compare(vector<char> v1, vector<char> v2) {
  if (v1.size() == v2.size()) {
    string a(v1.begin(), v1.end());
    string b(v2.begin(), v2.end());
    return stoi(a) < stoi(b);
  }
  return v1.size() > v2.size();
}


vector<int> solution(int n, vector<vector<string>> qr) {
  // qr코드 별로 4방향 회전 결과 저장
  setRotatedQR(qr);
  // 각각 유사도 비교해 최댓값 저장
  setSimilarity(n);
  // 많은 qr코드 사용한 경우 추리기
  getOptions(n);
  // 이어붙인 숫자가 최소인 경우 찾기
  sort(options.begin(), options.end(), compare);

  vector<int> ans;
  for (auto o : options.front()) {
    ans.push_back(o-'0');
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<int> ans = solution(2   ,    {{"######", "######", "######", "######", "######", "######"}, {"######", "######", "######", "######", "######", "######"}}  );

  for (auto a : ans) {
    cout << a << endl;
  }
}