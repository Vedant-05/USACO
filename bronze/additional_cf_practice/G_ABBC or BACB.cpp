#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        // AB -> BC 1 coin
        // BA -> CB 1 coin

        // if two substring of a and one b than need to conditionaly hanlde the case
        vector<int> grp;
        int currLenA = 0;
        int countB = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B')
            {
                countB++;
                grp.push_back(currLenA);
                currLenA = 0;
            }
            else
            {
                currLenA++;
            }
        }
        if (currLenA != 0)
        {
            grp.push_back(currLenA);
            currLenA = 0;
        }
        if (s[0] == 'B' || s[n - 1] == 'B')
        {
            int sumAns = 0;
            for (auto c : grp)
            {
                sumAns += c;
            }
            cout << sumAns << endl;
        }
        else
        {
            if (countB > 0 && grp.size() > 0)
            {
                sort(grp.begin(), grp.end());
                int sumAns = 0;

                for (int j = grp.size() - 1; j >= 0 && countB != 0; j--, countB--)
                {
                    sumAns += grp[j];
                }

                cout << sumAns << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
}
