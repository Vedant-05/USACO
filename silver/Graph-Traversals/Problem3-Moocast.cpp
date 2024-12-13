#include <bits/stdc++.h>
using namespace std;

int dfs(int start, vector< bool > &vis, const vector< vector< int > > &adj) {
  if (vis[start])
    return 0;

  vis[start] = true;
  int count = 1; // count current node

  for (auto c : adj[start]) {
    if (!vis[c]) {
      count += dfs(c, vis, adj);
    }
  }

  return count;
}

int main() {
  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector< pair< int, int > > xy(n);
  vector< int > power(n);
  vector< vector< int > > adj(n);

  for (int i = 0; i < n; i++) {
    int x, y, p;
    cin >> x >> y >> p;
    xy[i] = {x, y};
    power[i] = p;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      int dx = xy[i].first - xy[j].first;
      int dy = xy[i].second - xy[j].second;
      long long dist = 1LL * dx * dx + 1LL * dy * dy;
      long long p = 1LL * power[i] * power[i];
      if (dist <= p) {
        adj[i].push_back(j);
      }
    }
  }

  int maxReachable = 0;
  for (int i = 0; i < n; i++) {
    vector< bool > vis(n, false);
    maxReachable = max(maxReachable, dfs(i, vis, adj));
  }

  cout << maxReachable << endl;
  return 0;
}
