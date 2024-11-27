#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll x;
    int n;
    cin >> x >> n;
    
    // Use priority queue to always combine smallest pieces first
    // Huffmon coding 
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    
    // Read stick lengths and add to priority queue
    for(int i = 0; i < n; i++) {
        ll len;
        cin >> len;
        pq.push(len);
    }
    
    ll total_cost = 0;
    
    // While there are at least 2 pieces to combine
    while(pq.size() > 1) {
        // Take the two smallest pieces
        ll first = pq.top(); pq.pop();
        ll second = pq.top(); pq.pop();
        
        // Cost of combining is their sum
        ll cost = first + second;
        total_cost += cost;
        
        // Put the combined piece back
        pq.push(cost);
    }
    
    cout << total_cost << endl;
    
    return 0;
}
