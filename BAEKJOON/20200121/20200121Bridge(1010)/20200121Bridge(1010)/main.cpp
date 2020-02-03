#include <iostream>
#include <cmath>
using namespace std;

long long permutation(int m, int n)
{
	long long val = 1;
	for (int i = m - n + 1; i <= m; i++) {
		val *= i;
	}
	return val;
}

int main() {
	int t, i, n, m;
	cin >> t;
	long long *ans = new long long[t];
	for (i = 0; i < t; i++) {
		cin >> n >> m;
		n = fmin(n, m - n);
		ans[i] = permutation(m, n) / permutation(n, n);
	}
	for (i = 0; i < t; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}