#include <iostream>
#include <cmath>
using namespace std;

int sum(int l) {
	int sum = 0;
	for (int i = 0; i < l; i++)
		sum += i;
	return sum;
}
bool check(long long n, int l) {
	if (n >= sum(l) && (n - sum(l)) % l == 0)
		return true;
	return false;
}
int main() {
	long long n, ans;
	int l, i, j;
	cin >> n >> l;
	for (i = l; i <= 100; i++) {
		if (check(n,i))
			break;
	}
	if (i == 101)
		cout << "-1" << endl;
	else {
		ans = (n - sum(i)) / i;
		for (j = 0; j < i; j++)
			cout << ans++ << ' ';
		cout << endl;
	}
	return 0;
}