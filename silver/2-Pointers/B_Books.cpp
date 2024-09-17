#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> suffSum, vector<int> vc, int len, int n, int t)
{

    int i = 0;
    int j = len - 1;

    while (j < n)
    {
        int inThisSum = suffSum[i] - suffSum[j + 1];
        if (inThisSum <= t)
        {
            return true;
        }
        else
        {
            i++;
            j++;
        }
    }

    return false;
}

int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> arr(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }

    vector<int> oldArr(arr);

    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] += arr[i + 1];
    }

    int start = 0;
    int end = 2 * n;
    int ans = 0;

    if (n == 1)
    {
        if (t >= oldArr[0])
        {
            cout << 1 << endl;
            return 0;
        }
        else
        {
            cout << 0 << endl;
            return 0;
        }
    }

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (possible(arr, oldArr, mid, n, t))
        {
            ans = max(ans, mid);
            start = mid + 1;
        }
        else
        {
            end = mid;
        }

        // cout << mid << " " << possible(arr, oldArr, mid, n, t) << endl;
    }

    cout << ans << endl;
}
