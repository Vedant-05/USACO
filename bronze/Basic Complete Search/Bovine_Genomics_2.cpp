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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char a;
            cin >> a;
            spotty[i][j] = a;
            // cout << a << " ";
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char a;
            cin >> a;
            plain[i][j] = a;
        }
    }

    long long ans = 0;

    for (int i = 0; i < m - 2; i++)
    {

        for (int j = i + 1; j < m - 1; j++)
        {
            for (int z = j + 1; z < m; z++)
            {

                map<string, int> mp;

                for (int l = 0; l < n; l++)
                {
                    string tempString;

                    tempString += (char)(spotty[l][i]);
                    tempString += (char)(spotty[l][j]);
                    tempString += (char)(spotty[l][z]);
                    // cout << tempString << endl;
                    mp[tempString]++;
                }

                bool isSame = false;

                for (int l = 0; l < n; l++)
                {
                    string tempString;

                    tempString += (char)(plain[l][i]);
                    tempString += (char)(plain[l][j]);
                    tempString += (char)(plain[l][z]);
                    if (mp[tempString] != 0)
                    {
                        isSame = true;
                    }
                }

                if (!isSame)
                {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
