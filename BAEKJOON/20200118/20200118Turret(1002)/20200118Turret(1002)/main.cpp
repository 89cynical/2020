#include <iostream>
#include <cmath>
using namespace std;

bool check(int arr[2], int max, int min) {
	for (int i = 0; i < 2; i++) {
		if (arr[i] > max || arr[i] < min) {
			return true;
		}
	}
	return false;
}

int nodalPoint(int x[2],int y[2], int r[2]) {
	double d = sqrt(pow(x[1] - x[0], 2) + pow(y[1] - y[0], 2));
	if (x[0] == x[1] && y[0] == y[1] && r[0] == r[1])
		return -1;
	else if (fmax(r[0], r[1]) > d) {
		if (d + fmin(r[0], r[1]) < fmax(r[0], r[1]))
			return 0;
		else if (d + fmin(r[0], r[1]) == fmax(r[0], r[1]))
			return 1;
		else
			return 2;
	}
	else {
		if (r[0] + r[1] > d)
			return 2;
		else if (r[0] + r[1] == d)
			return 1;
		else
			return 0;
	}
}

int main() {
	int t, x[2], y[2], r[2], i;
	do {
		cin >> t;
	} while (t < 0);
	int* num = new int[t];
	for(i=0;i<t;i++) {
		do {
			cin >> x[0] >> y[0] >> r[0] >> x[1] >> y[1] >> r[1];
		} while (check(x, 10000, -10000) || check(y, 10000, -10000) || check(r, 10000, 1));
		num[i] = nodalPoint(x, y, r);
	}
	for (i = 0; i < t; i++) {
		cout << num[i] << endl;
	}
	delete[]num;
	return 0;
}