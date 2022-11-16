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
UPDATE r c value

UPDATE value1 value2

MERGE r1 c1 r2 c2

UNMERGE r c

PRINT r c

 */

string board[51][51];
int mergeNum[51][51];

vector<string> solution(vector<string> commands) {
  vector<set<pair<int,int>>> merged(1001);
  vector<string> mergeValue(1001);
  int idx = 1;
  vector<string> ans;

  for (auto command : commands) {
    vector<string> v;
    string str = "";
    for (int i=0; i<command.size(); i++) {
      if (command[i] == ' ') {
        v.push_back(str);
        str = "";
      } else {
        str.push_back(command[i]);
      }
    }
    v.push_back(str);

    // UPDATE r c value
    if (v[0] == "UPDATE") {
      // 단일 값 변경
      if (v.size() == 4) {
        int r = stoi(v[1]);
        int c = stoi(v[2]);
        string value = v[3];

        // 병합된 셀일 경우
        if (mergeNum[r][c]) {
          mergeValue[mergeNum[r][c]] = value;
        }
        else { // 단일 셀일 경우
          board[r][c] = value;
        } 
        
      } 
      // 다중 값 변경, 
      // UPDATE value1 value2
      else { 
        string value1 = v[1];
        string value2 = v[2];

        for (int i=1; i<=50; i++)
          for (int j=1; j<=50; j++) {
            if (board[i][j] == value1) board[i][j] = value2;
            if (mergeValue[mergeNum[i][j]] == value1) mergeValue[mergeNum[i][j]] = value2;
          }
      }

    } else if (v[0] == "MERGE") { // MERGE r1 c1 r2 c2
      int r1 = stoi(v[1]);
      int c1 = stoi(v[2]);
      int r2 = stoi(v[3]);
      int c2 = stoi(v[4]);

      int lidx = mergeNum[r1][c1];
      int ridx = mergeNum[r2][c2];

      // 둘다 병합 된 셀일 경우
      if (mergeNum[r1][c1] && mergeNum[r2][c2]) {
        
        // 왼쪽 셀이 값을 가지고 있을 경우 
        if (mergeValue[lidx] != "") {

          for (auto a : merged[ridx]) {
            merged[lidx].insert(a);
            mergeNum[a.first][a.second] = lidx;
          }
        } 
        else { // 오른쪽 셀 만 값을 가지고 있는 경우
          for (auto a : merged[lidx]) {
            merged[ridx].insert(a);
            mergeNum[a.first][a.second] = ridx;
          }
        }

      } else if (mergeNum[r1][c1] && !mergeNum[r2][c2]) { // 왼쪽만 병합됨
        
        merged[lidx].insert({r2,c2});
        mergeNum[r2][c2] = lidx;

        // 오른쪽 셀만 값을 가지고 있을 경우 
        if (mergeValue[lidx] == "" && board[r2][c2] != "") {
          mergeValue[lidx] = board[r2][c2];
        }

      } else if (!mergeNum[r1][c1] && mergeNum[r2][c2]) { // 오른쪽만 병합됨
        
        merged[ridx].insert({r1,c1});
        mergeNum[r1][c1] = ridx;

        // 왼쪽 셀이 값을 가지고 있는 경우
        if (board[r1][c1] != "") {
          mergeValue[ridx] = board[r1][c1];
        }

      }
      // 첫 병합
      else {
        merged[idx].insert({r1,c1});
        merged[idx].insert({r2,c2});
        mergeNum[r1][c1] = idx;
        mergeNum[r2][c2] = idx;

        if (board[r1][c1] != "") mergeValue[idx] = board[r1][c1];
        else if (board[r2][c2] != "") mergeValue[idx] = board[r2][c2];

        idx++;
      }

      board[r1][c1] = "";
      board[r2][c2] = "";

    } else if (v[0] == "UNMERGE") { // UNMERGE r c
      int r = stoi(v[1]);
      int c = stoi(v[2]);

      int nidx = mergeNum[r][c];
      for (auto a : merged[nidx]) {
        mergeNum[a.first][a.second] = 0;
      }
      merged[nidx].clear();
      board[r][c] = mergeValue[nidx];
      mergeValue[nidx] = "";

    } else if (v[0] == "PRINT") { // PRINT r c
      int r = stoi(v[1]);
      int c = stoi(v[2]);

      if (board[r][c] != "") ans.push_back(board[r][c]);
      else if (mergeValue[mergeNum[r][c]] != "") ans.push_back(mergeValue[mergeNum[r][c]]);
      else ans.push_back("EMPTY");
    }
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({"UPDATE 1 1 menu", "UPDATE 1 2 category", "UPDATE 2 1 bibimbap", "UPDATE 2 2 korean", "UPDATE 2 3 rice", "UPDATE 3 1 ramyeon", "UPDATE 3 2 korean", "UPDATE 3 3 noodle", "UPDATE 3 4 instant", "UPDATE 4 1 pasta", "UPDATE 4 2 italian", "UPDATE 4 3 noodle", "MERGE 1 2 1 3", "MERGE 1 3 1 4", "UPDATE korean hansik", "UPDATE 1 3 group", "UNMERGE 1 4", "PRINT 1 3", "PRINT 1 4"});

}