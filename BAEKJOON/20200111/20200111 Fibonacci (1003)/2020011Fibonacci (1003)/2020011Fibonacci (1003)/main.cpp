#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	int t, i;
	cin >> t;
	int *n = new int[t];
	int zero[41] = { 1,0 };
	int one[41] = { 0,1 };
	for (i = 2; i < 41; i++) {
		zero[i] = zero[i - 1] + zero[i - 2];
	}
	for (i = 2; i < 41; i++) {
		one[i] = one[i - 1] + one[i - 2];
	}
	for (i = 0; i < t; i++) {
		do {
			cin >> n[i];
		} while (n[i] > 40);
	}
	for (i = 0; i < t; i++) {
		cout << zero[n[i]] << " " << one[n[i]] << endl;
	}
	delete[]n;
	return 0;
}