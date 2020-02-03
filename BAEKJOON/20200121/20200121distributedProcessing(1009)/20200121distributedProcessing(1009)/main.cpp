#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t, a, b, i;
	cin >> t;
	int *ans = new int[t];
	for (i = 0; i < t; i++) {
		cin >> a >> b;
		b %= 4;
		if (b == 0)
			b = 4;
		ans[i] = pow(a, b);
		ans[i] %= 10;
		if (ans[i] == 0)
			ans[i] = 10;
	}
	for (i = 0; i < t; i++) {
		cout << ans[i] << endl;
	}
	delete[]ans;
	return 0;
}