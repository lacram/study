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

int n;
bool flag = true;
vector<string> arr;

/* 
두 숫자를 비교할 때 길이가 다르다면 다른 숫자가 등장할 때 비교
367
3

10
1004
 */

bool compare(string str1, string str2) {
  return str1 + str2 > str2 + str1;
}

string solution() {
  if (flag) return "0";

  sort(arr.begin(), arr.end(), compare);

  string ans = "";
  for (auto a : arr) {
    ans += a;
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    string str;
    cin >> str;
    if (str != "0") flag = false;
    arr.push_back(str);
  }

  cout << solution();
}