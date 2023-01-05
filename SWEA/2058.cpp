#include<iostream>
#include<string>

using namespace std;

string str;

void solution() {
	int ans = 0;
	for (auto s : str) {
		ans += s - '0';
	}

	cout << ans;
}

int main(int argc, char** argv)
{
	cin >> str;

	solution();

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}