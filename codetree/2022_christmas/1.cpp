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

vector<string> str = {"##  ##     ##     #####    #####    ##  ##            ##  ##            ##   ##    ##      ####",
"##  ##    ####    ##  ##   ##  ##   ##  ##            ##  ##            ### ###   ####    ##  ##",
"##  ##   ##  ##   ##  ##   ##  ##   ##  ##             ####             #######  ##  ##   ##",
"######   ######   #####    #####     ####               ##     ######   ## # ##  ######    ####",
"##  ##   ##  ##   ##       ##         ##               ####             ##   ##  ##  ##       ##",
"##  ##   ##  ##   ##       ##         ##              ##  ##            ##   ##  ##  ##   ##  ##",
"##  ##   ##  ##   ##       ##         ##              ##  ##            ##   ##  ##  ##    ####"};

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  for (auto s : str) {
    cout << s << endl;
  }
}