#include <bits/stdc++.h>
using namespace std;

struct Boot {
	int max_depth, max_steps, index;
};

int main() {
	freopen("snowboots.in", "r", stdin);

	int tile_num;
	int boot_num;
	cin >> tile_num >> boot_num;

	vector<int> tiles(tile_num);
	for (int &t : tiles) { cin >> t; }

	vector<Boot> boots(boot_num);
	for (int i = 0; i < boot_num; ++i) {
		cin >> boots[i].max_depth >> boots[i].max_steps;
		boots[i].index = i;
	}
	// sort the boots from greatest depth to least depth
	sort(boots.begin(), boots.end(),
	     [&](const Boot &a, const Boot &b) { return a.max_depth > b.max_depth; });

	vector<int> tiles_by_depth;  // list of tile indices, sorted by snow depth
	for (int i = 1; i < tile_num - 1; i++) { tiles_by_depth.push_back(i); }
	sort(tiles_by_depth.begin(), tiles_by_depth.end(),
	     [&](int a, int b) { return tiles[a] > tiles[b]; });

	set<int> valid_tiles;
	for (int i = 0; i < tile_num; i++) { valid_tiles.insert(i); }

	// the deepest tile that can still be traversed with the boot we're at
	int tile_at = 0;
	// the min step a boot needs to be able to take to reach the barn
	int needed_step = 1;
	vector<bool> can_reach(boot_num);
	for (const Boot &b : boots) {
		/*
		 * remove all the tiles that this boot can't traverse
		 * & update tile_at & needed_step accordingly
		 */
		while (tile_at < tiles_by_depth.size() &&
		       tiles[tiles_by_depth[tile_at]] > b.max_depth) {
			auto removed = valid_tiles.find(tiles_by_depth[tile_at]);
			needed_step = max(needed_step, *next(removed) - *prev(removed));
			valid_tiles.erase(removed);
			tile_at++;
		}
		can_reach[b.index] = b.max_steps >= needed_step;
	}

	freopen("snowboots.out", "w", stdout);
	for (bool b : can_reach) { cout << b << '\n'; }
}
