#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long sum = 0;
    long long ans = 0;
    map<long long, int> mp;
    mp[0] = 1;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
        long long remainder = ((sum % n) + n) % n;  // Ensure positive remainder
        ans += mp[remainder];
        mp[remainder]++;
    }

    cout << ans << endl;
    return 0;
}
