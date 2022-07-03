#include <iostream>
#include <algorithm>
using namespace std;


double a,d, k;
double cache[1000000];

double win(double possibility, int time) {
  if (possibility >= 1) return 1*time;

  double ret = 0;
	
  ret = possibility*time;

  ret += (1 - possibility) * win(possibility*(1+k), time+a);

  return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  cout << fixed;
  cout.precision(7);

	for (int i = 0; i < 1000000; ++i)
		cache[i] = 0;

	cin >> a >> d >> k;

	d /= 100;
	k /= 100;

	cout << win(d,a);
	return 0;
}