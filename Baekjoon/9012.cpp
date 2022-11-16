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

    int cnt = 0;
    bool flag = true;
    for (auto s : str) {
      if (s == '(') cnt++;
      else cnt--;

      if (cnt < 0) {
        flag = false;
        break;
      }
    }
    if (cnt == 0 && flag) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

}