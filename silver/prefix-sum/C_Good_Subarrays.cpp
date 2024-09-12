#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            arr[i] = s[i] - '0';
            // cout<<arr[i]<<endl;
        }

        vector<int> prefix(n, 0);
        vector<int> halci(n, 0);

        for (int i = 0; i < n; i++)
        {
            prefix[i] = i > 0 ? prefix[i - 1] + arr[i] : arr[i];
            halci[i] = i > 0 ? (prefix[i - 1] + arr[i] - i) : (arr[i] - i);
            // cout << halci[i] << " ";
        }

        // cout << endl;

        map<int, int> mp;

        mp[1] = 1;

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp[halci[i]] != 0)
            {
                ans += mp[halci[i]];
            }

            mp[halci[i]]++;
        }

        cout << ans << endl;
    }

    return 0;
}
