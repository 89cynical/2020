#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, i, j;
	cin >> n;
	int *a = new int[n];
	int *b = new int[n];
	int *p = new int[n];
	bool *used = new bool[n];
	for (i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
		used[i] = false;
	}
	sort(b, b + n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (a[i] == b[j] && used[j] == false) {
				p[i] = j;
				used[j] = true;
				break;
			}
		}
	}
	for (i = 0; i < n; i++)
		cout << p[i] << ' ';
	cout << endl;
	return 0;
}