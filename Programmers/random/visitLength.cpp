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
visited[x][y][dir]을 기억
 */

int visited[5][5][4];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
map<char,int> mapping = {
  {'R',0},{'D',1},{'L',2},{'U',3}
};

int solution(string dirs) {
    int answer = 0;
    return answer;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}