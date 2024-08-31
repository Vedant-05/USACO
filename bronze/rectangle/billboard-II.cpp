#include <cstdio>
#include <iostream>

using namespace std;

bool covered(int x, int y, int x1, int y1, int x2, int y2) {
	/*
	 * returns true if (x, y) is covered by the rectangle bounded by
	 * (x1, y1) and (x2, y2) and false otherwise
	 */
	return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

int main() {
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x3, y3, x4, y4;
	cin >> x3 >> y3 >> x4 >> y4;

	// count how many corners of the billboard are covered
	int corner_num = 0;
	if (covered(x1, y1, x3, y3, x4, y4)) corner_num++;
	if (covered(x1, y2, x3, y3, x4, y4)) corner_num++;
	if (covered(x2, y1, x3, y3, x4, y4)) corner_num++;
	if (covered(x2, y2, x3, y3, x4, y4)) corner_num++;

	// if fewer than 2 corners are covered, the whole rectangle must be covered
	if (corner_num < 2) {
		cout << (x2 - x1) * (y2 - y1);
	} else if (corner_num == 4) {
		// if all 4 corners are covered, then nothing needs to be covered
		cout << 0;
	} else {
		// we only need to cover some portion of the rectangle
		// find the intersection of the two rectangles
		int xl = max(x1, x3);
		int xr = min(x2, x4);
		int yl = max(y1, y3);
		int yr = min(y2, y4);
		// subtract away the area of the intersection
		cout << (x2 - x1) * (y2 - y1) - (xr - xl) * (yr - yl);
	}
}
