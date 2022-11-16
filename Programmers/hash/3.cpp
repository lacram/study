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

bool solution(vector<string> phone_book) {
  sort(phone_book.begin(), phone_book.end());

  for (int i=0; i<phone_book.size()-1; i++) {
    if (phone_book[i+1].substr(0, phone_book[i].size()) == phone_book[i]) return false;
  }
  return true;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}