#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    // int mp[s.length()][26];
    vector<vector<int>> mp(s.length(), vector<int>(26, 0));

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            mp[i][j] = i > 0 ? mp[i - 1][j] : 0;
        }
        mp[i][s[i] - 'a']++;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l - r == 0)
            cout << "Yes" << endl;
        else
        {
            if (s[l] != s[r])
            {
                cout << "Yes" << endl;
            }
            else
            {
                int diffSpec = 0;
                vector<int> mpTemp(26, 0);

                if (l == 0)
                {
                    for (int i = 0; i < 26; i++)
                    {
                        mpTemp[i] = mp[r][i];
                    }
                }
                else
                {

                    for (int i = 0; i < 26; i++)
                    {
                        // cout<<mp[l-1][i]<<" "<<mp[r][i]<<endl;
                        mpTemp[i] = mp[l - 1][i] - mp[r][i];
                    }
                }
                for (int i = 0; i < 26; i++)
                {
                    if (mpTemp[i] != 0)
                    {
                        diffSpec++;
                    }
                }

                // cout<<diffSpec<<"diffSpec"<<endl;

                if (diffSpec >= 3)
                {
                    cout << "Yes" << endl;
                }
                else
                {
                    cout << "No" << endl;
                }
            }
        }
    }

    return 0;
}
