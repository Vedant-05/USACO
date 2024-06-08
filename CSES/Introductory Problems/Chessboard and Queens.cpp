#include <bits/stdc++.h>

using namespace std;

int countQ = 0;

vector<bool> rDone(8, false);

vector<bool> cDone(8, false);
vector<bool> diag1(15, false);
vector<bool> diag2(15, false);

void findi(int q, vector<vector<char>> chess, int stR)
{
    if (q == 0 || stR == 8)
    {
        countQ++;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        if (chess[stR][i] == '.')
        {
            if (cDone[i] == false && diag1[i + stR] == false && diag2[i - stR + 7] == false)
            {
                cDone[i] = true;
                diag1[i + stR] = true;
                diag2[i - stR + 7] = true;
                findi(q - 1, chess, stR + 1);
                cDone[i] = false;
                diag1[i + stR] = false;
                diag2[i - stR + 7] = false;
            }
        }
    }
}

int main()
{
    vector<vector<char>> chess(8, vector<char>(8));

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char z;
            cin >> z;
            chess[i][j] = z;
        }
    }

    findi(8, chess, 0);

    cout << countQ << endl;
}
