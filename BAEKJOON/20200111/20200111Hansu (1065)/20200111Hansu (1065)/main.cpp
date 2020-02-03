#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

bool hansuCheck(int num){
	int a, b, dif;
	a = num % 10;
	num /= 10;
	b = num % 10;
	dif = a - b;
	while (num/10) {
		num /= 10;
		a = b;
		b = num % 10;
		if (dif != a - b) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, i, hansu = 0;
	do {
		cin >> n;
	}
	while (n > 1000 || n < 1);
	for (i = 1; i <= n; i++) {
		if (hansuCheck(i)) {
			hansu++;
		}
	}
	cout << hansu << endl;
	return 0;
}