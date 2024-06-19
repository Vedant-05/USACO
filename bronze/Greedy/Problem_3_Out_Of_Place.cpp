#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> vc(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vc[i] = a;
    }

    vector<int> sorted_vc(vc);

    sort(sorted_vc.begin(), sorted_vc.end());

    // call irregular places
    int bad_placed = 0;
    for (int i = 0; i < n; i++)

    {
        if (vc[i] != sorted_vc[i])
        {
            bad_placed++;
        }
    }

    cout << bad_placed - 1 << endl;
}
