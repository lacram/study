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

vector<int> solution(vector<int> array, vector<vector<int>> commands) {

  vector<int> ans;
  for (auto command : commands) {
    int fr = command[0]-1;
    int to = command[1];
    int want = command[2]-1;
    
    vector<int> v(array.begin()+fr, array.begin()+to);
    sort(v.begin(), v.end());
    ans.push_back(v[want]);
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}