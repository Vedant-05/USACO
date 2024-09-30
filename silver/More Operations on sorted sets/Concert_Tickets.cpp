#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  multiset<long long> ticketPrice;

  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    ticketPrice.insert(x);
  }

  for (int i = 0; i < m; i++) {
    long long willingPrice;
    cin >> willingPrice;

    if (ticketPrice.empty()) {
      cout << -1 << endl;
      continue;
    }
    
    auto isIt = ticketPrice.lower_bound(willingPrice);

    if (isIt == ticketPrice.end()) {
      isIt--;
    }

    if (isIt == ticketPrice.begin() && *isIt > willingPrice) {
      cout << -1 << endl;
    } else {
      if (*isIt > willingPrice) {
        --isIt;
      }
      cout << *isIt << endl;
      ticketPrice.erase(isIt);
    }
  }

  return 0;
}
