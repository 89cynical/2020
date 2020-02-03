#include <iostream>
using namespace std;

int cheating(char** classRoom, int j, int k, int m) {
	int cnt = 0;
	if (k > 0 && k < m - 1) {
		if (classRoom[j][k - 1] == '.')
			cnt++;
		if (classRoom[j][k + 1] == '.')
			cnt++;
		if (j > 0) {
			if (classRoom[j - 1][k - 1] == '.')
				cnt++;
			if (classRoom[j - 1][k + 1] == '.')
				cnt++;
		}
	}
	else if (k == 0) {
		if (classRoom[j][k + 1] == '.')
			cnt++;
		if (j > 0) {
			if (classRoom[j - 1][k + 1] == '.')
				cnt++;
		}
	}
	else {
		if (classRoom[j][k - 1] == '.')
			cnt++;
		if (j > 0) {
			if (classRoom[j - 1][k - 1] == '.')
				cnt++;
		}
	}
	return cnt;
}

int cheated(char** classRoom, int j, int k, int n, int m) {
	int cnt = 0;
	if (k > 0 && k < m - 1) {
		if (classRoom[j][k - 1] == '.')
			cnt++;
		if (classRoom[j][k + 1] == '.')
			cnt++;
		if (j < n - 1) {
			if (classRoom[j + 1][k - 1] == '.')
				cnt++;
			if (classRoom[j + 1][k + 1] == '.')
				cnt++;
		}
	}
	else if (k == 0) {
		if (classRoom[j][k + 1] == '.')
			cnt++;
		if (j < n - 1) {
			if (classRoom[j + 1][k + 1] == '.')
				cnt++;
		}
	}
	else {
		if (classRoom[j][k - 1] == '.')
			cnt++;
		if (j < n - 1) {
			if (classRoom[j + 1][k - 1] == '.')
				cnt++;
		}
	}
	return cnt;
}

int xNum(char** classRoom, int k, int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (classRoom[i][k] == 'x')
			cnt++;
	}
	return cnt;
}
int main() {
	int c, n, m, x, cNum, max;//case, n행, m열, x의 개수, 컨닝하거나 당하는 학생 수, 컨닝 인덱스 최대값
	int i, j, k;//index
	int t, tC, tR;//max값 중복 시 xNum 비교를 위한 temp
	cin >> c;
	int *ans = new int[c];
	for (i = 0; i < c; i++) {
		x = 0;
		cin >> n >> m;
		char **classRoom = new char*[n];
		int **classRoomIdx = new int*[n];
		for (j = 0; j < n; j++) {
			classRoom[j] = new char[m + 1];
			classRoomIdx[j] = new int[m];
		}
		for (j = 0; j < n; j++)
			cin >> classRoom[j];
		do {
			cNum = 0, max = 0, t = -1, tC = -1, tR = -1;
			for (j = 0; j < n; j++) {
				for (k = 0; k < m; k++) {
					classRoomIdx[j][k] = 0;
				}
			}
			for (j = 0; j < n; j++) {
				for (k = 0; k < m; k++) {
					if (classRoom[j][k] == '.') {
						if (cheating(classRoom, j, k, m) || cheated(classRoom, j, k, n, m)) {
							classRoomIdx[j][k] = cheating(classRoom, j, k, m) + cheated(classRoom, j, k, n, m);
							cNum++;
						}
					}
				}
			}
			for (j = 0; j < n; j++) {
				for (k = 0; k < m; k++) {
					if (classRoomIdx[j][k] > max)
						max = classRoomIdx[j][k];
				}
			}
			if (max > 0) {
				for (j = 0; j < n; j++) {
					for (k = 0; k < m; k++) {
						if (classRoomIdx[j][k] == max) {
							if (t < xNum(classRoom, k, n)) {
								t = xNum(classRoom, k, n);
								tC = j;
								tR = k;
							}
						}
					}
				}
				classRoom[tC][tR] = 'x';
			}
		} while (cNum);
		for (j = 0; j < n; j++) {
			for (k = 0; k < m; k++) {
				if (classRoom[j][k] == 'x')
					x++;
			}
		}
		ans[i] = n * m - x;
		for (j = 0; j < n; j++) {
			cout << classRoom[j] << endl;
		}
		for (j = 0; j < n; j++) delete[] classRoom[j];
		delete[]classRoom;
		delete[]classRoomIdx;
	}
	for (i = 0; i < c; i++)
		cout << ans[i] << endl;
	delete[]ans;
	return 0;
}