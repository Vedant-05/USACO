#include <bits/stdc++.h>
using namespace std;

int maxen = 1502;
int alphabet = 26;

int main()
{

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> arr(alphabet, vector<int>(maxen, 0));

    for (int c = 0; c < alphabet; c++)
    {
        for (int i = 0; i < n; i++)
        {
            int need_to_change = 0;
            for (int j = i; j < n; j++)
            {
                if (s[j] - 'a' != c)
                {
                    need_to_change++;
                }

                arr[c][need_to_change] = max(arr[c][need_to_change], j - i + 1);
            }
        }
        for(int i=1;i<maxen;i++)
        {
            arr[c][i]=max(arr[c][i],arr[c][i-1]);
        }
    }

    int q;
    cin>>q;
    while(q--)
    {
        int m;
        char z;
        cin>>m>>z;
        cout<<arr[z-'a'][m]<<endl;
    }
    return 0;
}
