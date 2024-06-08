#include <bits/stdc++.h>

using namespace std;

long long findi(vector<int> arr, long long w1, long long w2, int ind)
{
    if (ind < 0)
    {
        return abs(w1 - w2);
    }

    return min(findi(arr, w1 + arr[ind], w2, ind - 1), findi(arr, w1, w2 + arr[ind], ind - 1));
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }

    cout << findi(arr, 0, 0, n - 1) << endl;
}
