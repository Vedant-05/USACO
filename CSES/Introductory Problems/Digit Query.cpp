#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long> powers(19, 1);

    for (int i = 1; i < 19; i++)
    {
        powers[i] = powers[i - 1] * 10;
    }

    int t;
    cin >> t;
    while (t--)
    {
        long long k;
        cin >> k;

        long long numDig = 0;
        long long digits = 0;
        long long prevDig = 0;

        for (int i = 1; i < 19; i++)
        {
            digits += (powers[i] - powers[i - 1]) * i;

            if (digits >= k)
            {
                numDig = i;
                break;
            }

            prevDig = digits;
        }

        long long low = powers[numDig - 1];
        long long high = powers[numDig];
        long long ans = 0;
        long long startPosAns = 0;
        while (low <= high)
        {
            long long mid = (low + high) / 2;
            long long startPos = (mid - powers[numDig - 1]) * numDig + prevDig + 1;

            if (startPos <= k)
            {
                if (mid > ans)
                {
                    ans = mid;
                    startPosAns = startPos;
                }
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        string numberTo = to_string(ans);
        cout << numberTo[k - startPosAns] << endl;
    }
    return 0;
    
}
