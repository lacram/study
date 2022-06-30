#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> arr(5,vector<int>(5,0));
map<long long, vector<vector<int>>> memo;
int n;


vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b){
  vector<vector<int>> ret(n,vector<int>(n,0));
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++){
      for (int k=0; k<n; k++)
        ret[i][j] += a[i][k]*b[k][j];
      ret[i][j] %= 1000;
    }
  return ret;
}

vector<vector<int>> solve(long long cnt){
  if (cnt == 1) return arr;
  if (memo.find(cnt) != memo.end()) return memo[cnt];
  if (cnt % 2 ==0) return memo[cnt] = mul(solve(cnt/2),solve(cnt/2));
  else return memo[cnt] = mul(arr, solve(cnt-1));
}

int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
  long long b;
  cin >> n >> b;
  
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> arr[i][j];
  
  vector<vector<int>> ret = solve(b);

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      cout << ret[i][j]%1000 << " ";
    cout << '\n';
  }
    
}