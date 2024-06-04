#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("circlecross.in", "r", stdin);
    string crossings;
    cin >> crossings;

    vector<int> start(26, -1);
    vector<int> end(26, -1);
    for (int i = 0; i < crossings.size(); i++)
    {
        if (start[crossings[i] - 'A'] == -1)
        {
            start[crossings[i] - 'A'] = i;
        }
        else
        {
            end[crossings[i] - 'A'] = i;
        }
    }

    int crossing_pairs = 0;
    // Check all pairs of cows (i, j)
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            // Increment by 1 if the condition in the explanation is met
            crossing_pairs +=
                (start[i] < start[j] && start[j] < end[i] && end[i] < end[j]);
        }
    }

    freopen("circlecross.out", "w", stdout);
    cout << crossing_pairs << endl;
}
