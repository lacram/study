#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#define endl '\n'

using namespace std;

int n;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  priority_queue<int> heap;

  for (int i=0; i<n; i++){
    int num;
    cin >> num;

    if (!num) {
      if (heap.empty()) cout << 0 << endl;
      else {
        cout << heap.top() << endl;
        heap.pop();
      }
    }
    else{
      heap.push(num);
    }
  }

}