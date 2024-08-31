#include <fstream>
#include <iostream>

using std::cout;
using std::endl;

int fastest_time(int dist, int max_speed) {
	int speed_up_dist = 0;   // Amount of distance where Bessie's speeding up
	int slow_down_dist = 0;  // and slowing down respectively
	int time = 0;

	// Gradually speed up until we achieve our distance
	for (int curr_speed = 1;; curr_speed++) {
		speed_up_dist += curr_speed;
		time++;
		if (speed_up_dist + slow_down_dist >= dist) { return time; }

		/*
		 * If we're above the speed limit, add the current speed
		 * to the part where we slow down as well.
		 */
		if (curr_speed >= max_speed) {
			slow_down_dist += curr_speed;
			time++;
			// Check again if we've reached or passed the finish line
			if (speed_up_dist + slow_down_dist >= dist) { return time; }
		}
	}
}

int main() {
	std::ifstream read("race.in");
	int dist;
	int query_num;
	read >> dist >> query_num;

	std::ofstream written("race.out");
	for (int q = 0; q < query_num; q++) {
		int max_speed;
		read >> max_speed;
		written << fastest_time(dist, max_speed) << '\n';
	}
}
