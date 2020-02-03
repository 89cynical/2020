#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int x, y, w, h;
	do {
		cin >> x >> y >> w >> h;
	} while (w > 1000 || w < 0 || h>1000 || h<0 || x>w - 1 || x<0 || y>h - 1 || y < 0);
	cout << min(min(w - x, x), min(h - y, y)) << endl;
	return 0;
}