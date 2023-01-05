#include<iostream>
#include<vector>

using namespace std;

// 가위1, 바위2, 보3
vector<pair<int, int>> win = { {1,3},{2,1},{3,2} };

int main(int argc, char** argv)
{
	int a, b;

	cin >> a >> b;

	bool Awin = false;
	// A가 이김
	for (auto w : win) {
		if (w.first == a && w.second == b) {
			Awin = true;
		}
	}

	if (Awin) cout << "A";
	else cout << "B";

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}