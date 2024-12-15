#include <bits/stdc++.h>
using namespace std;

int directions[4][2] = {
    {0, -1}, // left
    {0, 1},  // right
    {-1, 0}, // up
    {1, 0}   // down
};

bool isValid(int x, int y, int n, int m) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, vector< vector< bool > > &visited,
         vector< vector< char > > &grid, int n, int m, int &goodReached) {
  if (!isValid(x, y, n, m) || visited[x][y] || grid[x][y] == '#')
    return;

  visited[x][y] = true;
  if (grid[x][y] == 'G')
    goodReached++;

  for (int k = 0; k < 4; k++) {
    int newX = x + directions[k][0];
    int newY = y + directions[k][1];
    dfs(newX, newY, visited, grid, n, m, goodReached);
  }
}

bool solve() {
  int n, m;
  cin >> n >> m;

  vector< vector< char > > grid(n, vector< char >(m));
  int totalGood = 0;

  // Read input and count good people
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'G')
        totalGood++;
    }
  }

  // If no good people, answer is Yes
  if (totalGood == 0)
    return true;

  // Block around bad people and check for adjacent good people
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'B') {
        for (int k = 0; k < 4; k++) {
          int newX = i + directions[k][0];
          int newY = j + directions[k][1];

          if (isValid(newX, newY, n, m)) {
            if (grid[newX][newY] == 'G')
              return false;
            if (grid[newX][newY] == '.')
              grid[newX][newY] = '#';
          }
        }
      }
    }
  }

  // Run DFS from end cell and count reachable good people
  vector< vector< bool > > visited(n, vector< bool >(m, false));
  int goodReached = 0;
  dfs(n - 1, m - 1, visited, grid, n, m, goodReached);

  return goodReached == totalGood;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    cout << (solve() ? "Yes\n" : "No\n");
  }
  return 0;
}
