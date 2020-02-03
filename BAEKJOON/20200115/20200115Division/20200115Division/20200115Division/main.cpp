#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	int n, f, i;
	do {
		cin >> n;
	} while (n > 2000000000 || n < 100);
	do {
		cin >> f;
	} while (f > 100 || f < 0);
	n -= n % 100;
	for (i = 0; i < 100; i++) {
		if ((n + i) % f == 0) {
			break;
		}
	}
	if (i < 10) {
		cout << "0";
	}
	cout << i << endl;
	return 0;
}