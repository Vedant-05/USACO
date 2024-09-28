#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long long m;
    cin >> n >> m;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long sum = 0;
    int left = 0, ans = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right];
        
        while (sum > m && left <= right) {
            sum -= arr[left];
            left++;
        }

        if (sum == m) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
