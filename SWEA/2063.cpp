#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> arr;

void solution() {
	sort(arr.begin(), arr.end());
	cout << arr[n / 2];
}

int main(int argc, char** argv)
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	solution();

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}