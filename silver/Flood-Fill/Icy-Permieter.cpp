#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

  using pi = pair< int, int >;
#define mp make_pair
#define f first
#define s second

#define tcT template < class T
tcT > using V = vector< T >;
tcT, size_t SZ > using AR = array< T, SZ >;
using vi = V< int >;
using vb = V< bool >;
using vpi = V< pi >;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

const int MOD = 1e9 + 7;
const db PI = acos((db)-1);

tcT > bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
tcT > bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

int directions[4][2] = {
    {0, -1}, // left
    {0, 1},  // right
    {-1, 0}, // up
    {1, 0}   // down
};

vector< vector< bool > > vis(1005, vector< bool >(1005, false));
long long tempArea = 0;
long long tempPerimeter = 0;

void dfs(int x, int y, const vector< vector< int > > &vc) {
  if (vis[x][y])
    return;

  queue< pair< int, int > > pc;
  pc.push(make_pair(x, y));

  while (!pc.empty()) {
    pair< int, int > tp = pc.front();
    pc.pop();
    int x1 = tp.first, y1 = tp.second;

    if (x1 >= 0 && y1 >= 0 && x1 < vc.size() && y1 < vc.size() &&
        !vis[x1][y1]) {
      vis[x1][y1] = true;
      tempArea++;

      for (int z = 0; z < 4; z++) {
        int newx1 = x1 + directions[z][0];
        int mewy1 = y1 + directions[z][1];

        if (newx1 >= 0 && mewy1 >= 0 && newx1 < vc.size() &&
            mewy1 < vc.size() && (vc[newx1][mewy1] == 1)) {
          if (!vis[newx1][mewy1]) {
            pc.push(make_pair(newx1, mewy1));
          }
        } else {
          tempPerimeter++;
        }
      }
    }
  }
}

int main() {
  freopen("perimeter.in", "r", stdin);
  freopen("perimeter.out", "w", stdout);

  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector< vector< int > > adj(n, vector< int >(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char a;
      cin >> a;
      if (a == '#') {
        adj[i][j] = 1;
      }
    }
  }

  long long maxPerim = INT_MAX;
  long long maxArea = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (adj[i][j] == 1 && !vis[i][j]) {
        dfs(i, j, adj);
        if (tempArea > maxArea) {
          maxArea = tempArea;
          maxPerim = tempPerimeter;
        } else if (tempArea == maxArea) {
          maxPerim = min(tempPerimeter, maxPerim);
        }
        tempArea = 0;
        tempPerimeter = 0;
      }
    }
  }

  cout << maxArea << " " << maxPerim << endl;
}
