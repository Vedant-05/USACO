#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("cownomics.in", "r", stdin);

    freopen("cownomics.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> spotty(n, vector<char>(m));
    vector<vector<char>> plain(n, vector<char>(m));

    vector<set<int>> tempSpotty(m);
    vector<set<int>> tempPlain(m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char a;
            cin >> a;
            spotty[i][j] = a;
            tempSpotty[j].insert(a);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char a;
            cin >> a;
            plain[i][j] = a;
            tempPlain[j].insert(a);
        }
    }

    long long ans = 0;

    for (int i = 0; i < m; i++)
    {
        bool matchingOther = false;
        for (auto c : tempSpotty[i])
        {
            if (tempPlain[i].find(c) != tempPlain[i].end())
            {
                matchingOther = true;
                break;
            }
        }
        if (!matchingOther)
        {
            ans++;
        }
    }

    cout << ans << endl;
}
