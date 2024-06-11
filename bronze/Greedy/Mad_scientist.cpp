#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n;
    cin >> n;
    string a, b;

    cin >> a >> b;

    int same = 0;
    bool disParity = false;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            if (disParity)
            {
                ans++;
                disParity = false;
            }
        }
        else
        {
            disParity = true;
        }
    }

    if (disParity)
    {
        ans++;
        cout << ans << endl;
    }
    else
    {
        cout << ans << endl;
    }
}
