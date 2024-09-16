#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<long long> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<long long> effect_count(m + 1, 0);
    vector<tuple<int, int, long long>> effects(m);
    
    for(int i = 0; i < m; i++) {
        int l, r;
        long long d;
        cin >> l >> r >> d;
        effects[i] = {l - 1, r - 1, d};
    }
    
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        effect_count[x - 1]++;
        effect_count[y]--;
    }
    
    for(int i = 1; i < m; i++) {
        effect_count[i] += effect_count[i - 1];
    }
    
    vector<long long> diff(n + 1, 0);
    
    for(int i = 0; i < m; i++) {
        if(effect_count[i] > 0) {
            int l, r;
            long long d;
            tie(l, r, d) = effects[i];
            diff[l] += effect_count[i] * d;
            diff[r + 1] -= effect_count[i] * d;
        }
    }
    
    for(int i = 1; i < n; i++) {
        diff[i] += diff[i - 1];
    }
    
    for(int i = 0; i < n; i++) {
        cout << arr[i] + diff[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}
