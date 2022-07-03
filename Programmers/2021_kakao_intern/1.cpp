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
#define endl '\n'
#define INF 2000000000

using namespace std;

int solution(string s) {
  string ans = "";
  string str = s;
  for (int i=0; i<str.length(); i++){
    if (str[i] == 'z') {
      ans.append("0");
      i += 3;
    } else if (str[i] == 'o'){
      ans.append("1");
      i += 2;
    } else if (str[i] == 't'){
      if (str[i+1] == 'w'){
        ans.append("2");
        i += 2;
      } else {
        ans.append("3");
        i += 4;
      }
    } else if (str[i] == 'f'){
      if (str[i+1] == 'o'){
        ans.append("4");
        i += 3;
      } else {
        ans.append("5");
        i += 3;
      }
    } else if (str[i] == 's'){
      if (str[i+1] == 'i'){
        ans.append("6");
        i += 2;
      } else {
        ans.append("7");
        i += 4;
      }
    } else if (str[i] == 'e'){
      ans.append("8");
      i += 4;
    } else if (str[i] == 'n'){
      ans.append("9");
      i += 3;
    } else {
      ans.push_back(str[i]);
    }
  }
  return stoi(ans);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

}