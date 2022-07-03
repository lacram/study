#include <iostream>
#include <vector>
using namespace std;

void pick(int n, vector<int> picked, int toPick);
void printRes(vector<int> picked);
int main(){
  // n : 전체 원소의 개수
  // picked : 지금까지 고른 원소의 번호
  // topick : 골라야할 원소 수

  vector<int> picked;
  pick(6, picked, 3);
}
void pick(int n, vector<int> picked, int toPick){
  if (toPick == 0){
    printRes(picked);
    return;
  }
  int next = picked.empty() ? 0 : picked.back() + 1;
  for (int i = next; i<n; i++){
    picked.push_back(i);
    pick(n, picked, toPick-1);
    picked.pop_back();
  }

}
void printRes(vector<int> picked){
  for (int i=0; i<picked.size(); i++){
    cout << picked[i];
  }
  cout << endl;
}


