// just pure brute force
// two cases, if all three rectanges are stacked on top of each other, and if one rectangle is stacked on //top of the other two, which are side by side.

#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>> &arr, vector<int> &vis)
{

    vis[v] = 1;
    for (auto c : arr[v])
    {
        {
            if (vis[c] != 1)
                dfs(c, arr, vis);
        }
    }
}

int main()
{
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int>> arr(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        arr[a].push_back(b);
    }

    vector<int> netVis(n + 1, 1);

    for (int i = 1; i <= n; i++)
    {
        vector<int> vis(n + 1, 0);
        dfs(i, arr, vis);
        for (int i = 0; i <= n; i++)
        {
            if (vis[i] == 1 && netVis[i] == 1)
            {
                netVis[i] = 1;
            }
            else
            {
                netVis[i] = 0;
            }
        }
    }
    int ans = -1;
    for (int i = 0; i <= n; i++)
    {
        if (netVis[i] == 1)
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
