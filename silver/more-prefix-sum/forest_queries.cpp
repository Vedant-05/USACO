#include <bits/stdc++.h>
using namespace std;

long long max(long long a, long long b)
{

    return (a > b) ? a : b;
}
int main()
{

    int n, q;
    cin >> n >> q;
    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char s;
            cin >> s;

            arr[i][j] = s == '.' ? 0 : 1;
        }
    }

    vector<vector<int>> prefix(n, vector<int>(n));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            prefix[i][j] = arr[i][j] + (i > 0 ? prefix[i - 1][j] : 0) + (j > 0 ? prefix[i][j - 1] : 0) - (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0);
        }
    }

    for(int i=0;i<q;i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;

        cout << prefix[x2][y2] - (y1 > 0 ? prefix[x2][y1 - 1] : 0) - (x1 > 0 ? prefix[x1 - 1][y2] : 0) + (x1 > 0 && y1 > 0 ? prefix[x1 - 1][y1 - 1] : 0) << endl;
    }

    return 0;
}
