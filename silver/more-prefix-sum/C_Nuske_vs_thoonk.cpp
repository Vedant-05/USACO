#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 2e3;

int main() {
	int n, m, q;
	cin >> n >> m >> q;

	/*
	 * The next 4 loops can be combined one for-loop, but for ease of
	 * understanding we have divided it.
	 * Reading the grid:
	 */
	vector<bitset<MAX_SIZE + 1>> grid(MAX_SIZE + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char a;
			cin >> a;
			grid[i][j] = (a == '1');
		}
	}

	// Overall prefix sums array. pref[x][y] is how many components
	// we have in the 2D array from (1, 1) to (x, y), inclusive.
	vector<vector<int>> pref(MAX_SIZE + 1, vector<int>(MAX_SIZE + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
			if (grid[i][j]) {
				if ((!grid[i - 1][j]) && (!grid[i][j - 1])) {
					/*
					 *   0
					 * 0 1
					 * A new connected component forms!
					 */
					pref[i][j]++;
				}
				if ((grid[i - 1][j]) && (grid[i][j - 1])) {
					/*
					 *   1
					 * 1 1
					 * Two connected components merge!
					 */
					pref[i][j]--;
				}
			}
		}
	}

	// horpref[x][y] is how many connected components we have in the row
	// from (x, 1) to (x, y), inclusive.
	vector<vector<int>> horpref(MAX_SIZE + 1, vector<int>(MAX_SIZE + 1));

	// verpref[x][y] is how many connected components we have in the column
	// from (1, y) to (x, y), inclusive.
	vector<vector<int>> verpref(MAX_SIZE + 1, vector<int>(MAX_SIZE + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			horpref[i][j] = horpref[i][j - 1];
			verpref[i][j] = verpref[i - 1][j];
			if (grid[i][j]) {
				horpref[i][j] += !grid[i][j - 1];
				verpref[i][j] += !grid[i - 1][j];
			}
		}
	}

	for (int i = 0; i < q; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int ans = grid[a][b];  // Whether we start with a connected component

		// How many new components appear in the top row and leftmost column
		ans += horpref[a][d] - horpref[a][b];
		ans += verpref[c][b] - verpref[a][b];

		// Change in # of connected components in the rest of the grid
		ans += pref[c][d] - pref[a][d] - pref[c][b] + pref[a][b];
		cout << ans << endl;
	}
}
