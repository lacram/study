#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int n;
vector<int> arr;

int solution() {
	int total = 0;
	for (auto a : arr) {
		total += a;
	}
	return round((double)total / arr.size());
}

int main(int argc, char** argv)
{
	int t;
	cin >> t;
	for (int j = 1; j <= t; j++) {
		arr.clear();
		for (int i = 0; i < 10; i++) {
			int a;
			cin >> a;
			arr.push_back(a);
		}
		cout << "#" << j << " " << solution() << endl;
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}