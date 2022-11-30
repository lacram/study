#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int height[9];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int total = 0;

  for (int i=0; i<9; i++){
    cin >> height[i];
    total += height[i];
  }
 
  sort(height, height+9);

  int ret = total - 100;
  
  bool find = false;
  for (int i=0; i<9; i++){
    for (int j=i+1; j<9; j++)
      if (height[i]+height[j] == ret){
        height[i] = 0;
        height[j] = 0;
        find = true;
        break;
      }
    if (find) break;
  }
    
  for (int i=0; i<9; i++)
    if (height[i]) 
      cout << height[i] << endl;
}