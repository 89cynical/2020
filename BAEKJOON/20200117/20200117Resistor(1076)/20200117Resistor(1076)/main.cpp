#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	string color[10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
	string c[3];
	int i, j;
	int n[3] = { 10, 10, 10 };
	long long ans;
	for (i = 0; i < 3; i++) {
		do {
			cin >> c[i];
			for (j = 0; j < 10; j++) {
				if (c[i] == color[j]) {
					n[i] = j;
				}
			}
		} while (n[i] >= 10);
	}
	ans = (n[0] * 10 + n[1]) * pow(10, n[2]);
	cout << ans << endl;
	return 0;
}