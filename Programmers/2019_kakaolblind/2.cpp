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

vector<double> difficulty(501); 

bool compare(int a, int b){
  return difficulty[a] > difficulty[b];
}

vector<int> solution(int N, vector<int> stages) {
  vector<int> ans(N);
  vector<int> num(N+2);
  vector<int> clear(N+1);

  for (auto stage : stages) 
    num[stage]++;

  int sum = 0;
  for (int i=N+1; i>=1; i--){
    sum += num[i];
    clear[i-1] = sum;
  }

  for (int i=1; i<=N; i++)
    difficulty[i] = double(num[i]) / (num[i]+clear[i]);
  
  for (int i=0; i<N; i++)
    ans[i] = i+1;

  stable_sort(ans.begin(), ans.end(), compare);

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<int> v =  solution(5,	{2, 1, 2, 6, 2, 4, 3, 3});

  for (auto a : v)
    cout << a << " ";
}