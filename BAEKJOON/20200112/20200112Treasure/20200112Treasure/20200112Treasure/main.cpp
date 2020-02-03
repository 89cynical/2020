#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void insertionSort(int* array, int n) {
	for (int i = 1; i < n; i++) {
		int temp = array[i];
		int j = i - 1;
		while (array[j]>temp && j>=0) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}
}

void insertionSortR(int* array, int n) {
	for (int i = 1; i < n; i++) {
		int temp = array[i];
		int j = i - 1;
		while (array[j]<temp && j >= 0) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}
}
bool check(int* array, int n) {
	for (int i = 0; i < n; i++) {
		if (array[i] > 100 || array[i] < 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, i, j;

	do {
		cin >> n;
	} while (n > 50);

	int *a = new int[n];
	int *aTemp = new int[n];
	int *b = new int[n];
	int *bIdx = new int[n];
	bool *used = new bool[n];
	int s = 0;

	do {
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
	} while (!check(a, n));
	do {
		for (i = 0; i < n; i++) {
			cin >> b[i];
		}
	} while (!check(b, n));

	for (i = 0; i < n; i++) {
		bIdx[i] = b[i];
		used[i] = false;
	}

	insertionSort(a, n);
	insertionSortR(bIdx, n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (bIdx[i] == b[j] && used[j]==false) {
				bIdx[i] = j;
				used[j] = true;
				break;
			}
		}
	}
	for (i = 0; i < n; i++) {
		aTemp[i] = a[i];
	}
	for (i = 0; i < n; i++) {
		a[bIdx[i]] = aTemp[i];
	}
	for (i = 0; i < n; i++) {
		s += a[i] * b[i];
	}
	cout << s << endl;
	delete[]a;
	delete[]aTemp;
	delete[]b;
	delete[]bIdx;
	delete[]used;
	return 0;
}