#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  int height[9];
  for(int i=0; i<9; i++){
    cin >> height[i];
  }
  int sum = 0;
  for(int i=0; i<9; i++) 
    sum += height[i];

  sort(height, height+9);
  int x=-1,y;
  for(int i=0; i<9; i++){
    for(int j=i+1; j<9; j++){
      if(sum-height[i]-height[j] == 100){
        x = i, y = j; 
        break;
      }
    }
    if(x != -1) break;
  }

  for(int i=0; i<9; i++){
    if (i != x && i != y){
      cout << height[i] << endl;
    }
  }

}