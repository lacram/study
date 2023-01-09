#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
// #include<fstream>
#include <queue>

using namespace std;

int n,m;
int ans;
vector<int> arr;
int total;

/* 
정렬해서 next_permutation으로 모든 순열 구하기
순열별 모든 경우 만들어보기
오른쪽 위에 올라가 있는 무게의 총합이 왼쪽에 올라가 있는 무게의 총합보다 더 커져서는 안 된다.
항상 왼 >= 오
남은 추를 모두 오른쪽에 올려도 조건이 부합하면 남은추의수 팩토리얼을 더해 가지치기한다
 */

int ex[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void dfs(int leftTotal, int rightTotal, int depth) {
  if (rightTotal > leftTotal) return;
  if (depth == n) {
    ans++;
    return;
  }

  if ((total - leftTotal) <= leftTotal) {
    ans += ex[n-depth];
    return;
  }

  // 왼쪽 추가
  dfs(leftTotal + arr[depth], rightTotal, depth+1);

  // 오른쪽 추가
  dfs(leftTotal, rightTotal + arr[depth], depth+1);
}

int solution() {
  sort(arr.begin(), arr.end());

  do {
    dfs(0,0,0);

  } while (next_permutation(arr.begin(), arr.end()));

  return ans;
}

int main()
{
	// ifstream cin;
	// cin.open("input.txt");

  int test;
  cin >> test;
	for (int k = 1; k <= test; k++) {
    cin >> n;

    ans = 0;
    arr.resize(n);
    total = 0;

    for (int i=0; i<n; i++) {
      cin >> arr[i];
      total += arr[i];
    }

    cout << "#" << k << " " << solution() << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

