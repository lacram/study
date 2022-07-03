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

vector<vector<int>> v;
vector<int> ans;
map<int, int> mapping;

bool compare(vector<int> v1, vector<int> v2) {
  if (v1[1] == v2[1]) return v1[0] < v2[0];
  return v1[1] > v2[1];
}

bool check(int node, vector<pair<int,int>> vec){
  for (auto ve : vec) {
    if (ve.second && node < ve.first) return false;
    if (!ve.second && node > ve.first) return false;
  }
  return true;
}

void preorder(int depth, vector<pair<int,int>> record) {
  if (depth == v.size()) return;

  for (auto node : v[depth]) {
    if (depth && !check(node,record)) continue;
    // 방문
    ans.push_back(mapping[node]);
    // 왼쪽
    record.push_back({node, 0});
    preorder(depth+1, record);
    record.pop_back();
    // 오른쪽
    record.push_back({node, 1});
    preorder(depth+1, record);
    record.pop_back();
  }
}

void postorder(int depth, vector<pair<int,int>> record) {
  if (depth == v.size()) return;
  
  for (auto node : v[depth]) {
    if (depth && !check(node,record)) continue;
    // 왼쪽
    record.push_back({node, 0});
    postorder(depth+1, record);
    record.pop_back();
    // 오른쪽
    record.push_back({node, 1});
    postorder(depth+1, record);
    record.pop_back();
    // 방문
    ans.push_back(mapping[node]);
  }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
  int idx = 1;
  for (auto node : nodeinfo) {
    mapping[node[0]] = idx++;
  }

  sort(nodeinfo.begin(), nodeinfo.end(), compare);

  int pos;

  // y좌표 같은 것끼리 분리
  for (int i=0; i<nodeinfo.size(); i = pos){
    vector<int> tmp = {nodeinfo[i][0]};
    pos = i+1;
    while(pos < nodeinfo.size() && nodeinfo[i][1] == nodeinfo[pos][1]) {
      tmp.push_back(nodeinfo[pos][0]);
      pos++;
    }
    v.push_back(tmp);
  }

  vector<vector<int>> a;
  preorder(0,{});
  a.push_back(ans);
  ans.clear();
  postorder(0,{});
  a.push_back(ans);
  
  return a;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<vector<int>> ans =  solution({{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}});

  for (auto a : ans){

    for (auto b : a)
      cout << b << " ";
    cout << endl;
  }
}