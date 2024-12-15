#include <bits/stdc++.h>
using namespace std;

int directions[4][2] = {
    {0, 1},  // right
    {0, -1}, // left
    {1, 0},  // down
    {-1, 0}  // up
};

int M, N;
vector< vector< int > > grid;
vector< vector< int > > waypoints;
vector< pair< int, int > > waypointsList;

bool isValid(int x, int y) { return x >= 0 && x < M && y >= 0 && y < N; }

void dfs(int x, int y, int D, vector< vector< bool > > &visited) {
  visited[x][y] = true;

  for (int k = 0; k < 4; k++) {
    int newX = x + directions[k][0];
    int newY = y + directions[k][1];

    if (isValid(newX, newY) && !visited[newX][newY]) {
      // If elevation difference is at most D, we can pass
      if (abs(grid[newX][newY] - grid[x][y]) <= D) {
        dfs(newX, newY, D, visited);
      }
    }
  }
}

// Check if all waypoints are connected with difficulty D
bool canReachAll(int D) {
  vector< vector< bool > > visited(M, vector< bool >(N, false));

  // Start DFS from first waypoint
  dfs(waypointsList[0].first, waypointsList[0].second, D, visited);

  // Check if all waypoints are visited
  for (auto wp : waypointsList) {
    if (!visited[wp.first][wp.second])
      return false;
  }
  return true;
}

int solve() {
  // Binary search over D
  int left = 0;
  int right = 1000000000;
  int result = right;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (canReachAll(mid)) {
      result = mid;
      right = mid - 1; // Try to find smaller D
    } else {
      left = mid + 1;
    }
  }

  return result;
}

int main() {
  freopen("ccski.in", "r", stdin);
  freopen("ccski.out", "w", stdout);

  cin >> M >> N;

  // Read grid
  grid.resize(M, vector< int >(N));
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> grid[i][j];
    }
  }

  // Read waypoints
  waypoints.resize(M, vector< int >(N));
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> waypoints[i][j];
      if (waypoints[i][j] == 1) {
        waypointsList.push_back(make_pair(i, j));
      }
    }
  }

  cout << solve() << endl;
  return 0;
}
