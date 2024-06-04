#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("gymnastics.in", "r", stdin);

    freopen("gymnastics.out", "w", stdout);
    int k, n;
    cin >> k >> n;
    vector<vector<int>> arr(k, vector<int>(n));
    map<int, vector<int>> mp;

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            arr[i][j] = a;
            mp[a].push_back(j);
        }
    }

    long long ans = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            bool greater = false;
            bool smaller = false;
            for (int x = 0; x < k; x++)
            {
                if (mp[i][x] > mp[j][x])
                {
                    greater = true;
                }
                else if (mp[i][x] < mp[j][x])
                {
                    smaller = true;
                }
            }

            if (greater && smaller)
            {
                continue;
            }
            else
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
}
