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
#include <typeinfo>
#define endl '\n'
#define INF 2000000000

using namespace std;



int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<int> v= {1,2,3,4,5};

  int value = 5;
  int *ptr = &value;

  *ptr -= 1;

  cout << value;


}