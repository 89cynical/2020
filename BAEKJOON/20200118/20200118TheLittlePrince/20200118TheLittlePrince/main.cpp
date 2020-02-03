#include <iostream>
using namespace std;

bool check(int x, int max, int min) {
	if (x > max || x < min)
			return true;
	return false;
}
int main() {
	int t, pX[2], pY[2], n, i, j, k = 0, l, cx, cy, cr, p[3] = {0,};
	do {
		cin >> t;
	} while (t < 0);
	int *ans = new int[t];
	l = t;
	while (t) {
		do {
			cin >> pX[0] >> pY[0] >> pX[1] >> pY[1];
		} while (check(pX[0], 1000, -1000) || check(pY[0], 1000, -1000) ||
			check(pX[1], 1000, -1000) || check(pY[1], 1000, -1000));
		do {
			cin >> n;
		} while (n > 50 || n < 1);
		int *x = new int[n];
		int *y = new int[n];
		int *r = new int[n];
		for (i = 0; i < n; i++) {
			do {
				cin >> cx >> cy >> cr;
			} while (check(cx, 1000, -1000) || check(cy, 1000, -1000) || check(cr, 1000, 0));
			x[i] = cx;
			y[i] = cy;
			r[i] = cr;
		}
		for (i = 0; i < 2; i++) {
			for (j = 0; j < n; j++) {
				if (sqrt(pow(pX[i] - x[j], 2) + pow(pY[i] - y[j], 2)) < r[j])
					p[i]++;
			}
		}
		for (i = 0; i < n; i++) {
			if (sqrt(pow(pX[0] - x[i], 2) + pow(pY[0] - y[i], 2)) < r[i] 
				&& sqrt(pow(pX[1] - x[i], 2) + pow(pY[1] - y[i], 2)) < r[i])
				p[2]+=2;
		}
		ans[k] = p[0] + p[1] - p[2];
		k++;
		t--;
		p[0] = 0;
		p[1] = 0;
		p[2] = 0;
	}
	for (i = 0; i < l; i++)
		cout << ans[i] << endl;
	return 0;
}