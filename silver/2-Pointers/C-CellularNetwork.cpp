#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> cities(n);
    set<long long> antennas;

    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    for (int i = 0; i < m; i++) {
        long long x;
        cin >> x;
        antennas.insert(x);
    }

    long long max_distance = 0;

    for (int i = 0; i < n; i++) {
        auto it = antennas.lower_bound(cities[i]);
        long long dist;

        if (it == antennas.end()) {
            // If no antenna >= cities[i], use the last antenna
            dist = abs(cities[i] - *antennas.rbegin());
        } else if (it == antennas.begin()) {
            // If the first antenna is >= cities[i], use it
            dist = abs(cities[i] - *it);
        } else {
            // Compare with the found antenna and the previous one
            long long dist1 = abs(cities[i] - *it);
            --it;
            long long dist2 = abs(cities[i] - *it);
            dist = min(dist1, dist2);
        }

        max_distance = max(max_distance, dist);
    }

    cout << max_distance << endl;
    return 0;
}
