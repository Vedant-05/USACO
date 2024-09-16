#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> intervals(k);
    for (int i = 0; i < k; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    
    vector<long long> dp(n + 1, 0), pref(n + 1, 0);
    dp[1] = pref[1] = 1;  // We start at cell 1
    
    for (int i = 2; i <= n; i++) {
        for (auto [l, r] : intervals) {
            int left = max(1, i - r);
            int right = i - l;
            if (left > right) continue;
            dp[i] = (dp[i] + pref[right] - pref[left - 1] + MOD) % MOD;
        }
        pref[i] = (pref[i-1] + dp[i]) % MOD;
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
