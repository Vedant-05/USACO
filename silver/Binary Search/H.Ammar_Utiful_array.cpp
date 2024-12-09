#include <bits/stdc++.h>
using namespace std;

int main() { 
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;

    vector<int> val(n);
    vector<int> col(n);

    for(int i = 0; i < n; i++) cin >> val[i];
    for(int i = 0; i < n; i++) cin >> col[i];

    // Store prefix sums for each color
    map<int, vector<long long> > colorPrefixSum;
    for(int i = 0; i < n; i++) {
        if(colorPrefixSum[col[i]].empty()) 
            colorPrefixSum[col[i]].push_back(0);
        colorPrefixSum[col[i]].push_back(colorPrefixSum[col[i]].back() + val[i]);
    }

    int q;
    cin >> q;

    long long genericAdd = 0;
    map<int, long long> colorExclude;

    while(q--) {
        int type, color;
        long long x;
        cin >> type >> color >> x;

        if(type == 1) {
            genericAdd += x;
            colorExclude[color] += x;
        } else {
            int left = 0;
            int right = colorPrefixSum[color].size() - 1;
            int ans = -1;

            while(left <= right) {
                int mid = (left + right) / 2;
                long long initialSum = colorPrefixSum[color][mid];
                long long addedValue = (genericAdd - colorExclude[color]) * mid;
                
                if(initialSum + addedValue <= x) {
                    ans = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
