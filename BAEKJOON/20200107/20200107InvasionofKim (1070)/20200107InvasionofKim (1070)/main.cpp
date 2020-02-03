#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool alphabetCheck(int alphabet[26]) {
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] < 1 || alphabet[i]>1000000) {
			return false;
		}
	}
	return true;
}

int main() {
	int m, n, i, j;
	int cX, cY;
	int alphabet[26];
	char map[50][50];
	do {
		cin >> m >> n;
	} while (m > 50 || m < 3 || n > 50 || n < 3);
	for (i = 0; i < m; i++) {
		cin >> map[i];
	}
	do {
		for (i = 0; i < 26; i++) {
			cin >> alphabet[i];
		}
	} while (!alphabetCheck(alphabet));
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (map[i][j]=='*') {
				cX = i;
				cY = j;
			}
		}
	}
	return 0;
}