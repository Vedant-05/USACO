#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> first_quest(n);
        vector<int> second_quest(n);

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            first_quest[i] = a;
        }
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            second_quest[i] = a;
        }

        vector<int> prefixSum(n, 0);

        for (int i = 0; i < n; i++)
        {
            prefixSum[i] = (i - 1 >= 0 ? prefixSum[i - 1] : 0) + first_quest[i];
        }

        int ans = 0;

        int maxBusin = second_quest[0];

        for (int i = 0; i < n; i++)
        {
            if (i + 1 <= k)
            {
                maxBusin = max(maxBusin, second_quest[i]);

                int temp = prefixSum[i] + (maxBusin * (k-i-1));
                // cout<<prefixSum[i]<<" "<<maxBusin<<" "<<(k-i-1)<<endl;
                // cout<<temp<<endl;
                ans = max(ans, temp);
            }
        }

        cout<<ans<<endl;
    }
}
