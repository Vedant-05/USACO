#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        double base, height;
     
        double area_total = 0.0000000;
        cin >> n >> base >> height;
        vector<int> pos(n);

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            pos[i] = a;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (i + 1 < n)
            {
                if (pos[i + 1] >= pos[i] + height)
                {
                    area_total += (base * height) / 2.0000000;
                }
                else
                {
                    double tt_area = (base * height) / 2.0000000;
                    double overlaped_height = pos[i] + height - pos[i + 1];
                    double new_base = (overlaped_height * base) / height;

                    double to_minus = (new_base * overlaped_height) / 2.0000000;

                    area_total += tt_area - to_minus;

                }
            }
            else
            {
                area_total += (base * height) / 2.0000000;
            }
        }

        // Set precision to 6 decimal places
        cout << fixed << setprecision(7) << area_total << endl;
    }
}
