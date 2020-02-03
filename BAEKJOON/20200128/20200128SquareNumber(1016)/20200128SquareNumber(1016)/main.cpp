#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long min, max, ans, sNum = 0;
	long long i, j;
	cin >> min >> max;
	bool* check = new bool[max - min + 1];
	for (i = 0; i < max - min + 1; i++) 
		check[i] = false;
	ans = max - min + 1;
	for (i = 2; pow(i, 2) <= max; i++) {
		for (j = ceil(min / pow(i, 2)); pow(i, 2)*j <= max; j++) {
			if (check[(long long)pow(i, 2)*j - min] == false) {
				sNum++;
				check[(long long)pow(i, 2)*j - min] = true;
			}
		}
	}
	ans -= sNum;
	cout << ans << endl;
	return 0;
}